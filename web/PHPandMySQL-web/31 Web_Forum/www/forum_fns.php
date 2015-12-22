<?php
/*
	forum_fns.php 
*/

// 展开论坛中所有话题
function expand_all($expanded)
{
	$conn = db_connect();
	
	$sql = "select postid from header where children > 0";	// 增加引用计数，否则删除很难实现
	$result = mysql_query($sql);
	
	$num = mysql_num_rows($result);
	for ($i = 0; $i < $num; $i++)
	{
		$row = mysql_fetch_array($result);
		$expanded[$row[0]] = true;
	}
}

// 从数据库中取出一则消息
function get_post($postid)
{
	if ($postid < 1)
	{
		// 检查不够完备
		return false;
	}
	
	$conn = db_connect();
	
	$sql = "select * from header where postid = '$postid'";
	$result = mysql_query($sql, $conn);
	if (mysql_num_rows($result) != 1)
	{
		return false;
	}
	
	$post = mysql_fetch_array($result);
	
	$sql = "select * from body where postid = '$postid'";
	$result = mysql_query($sql);
	if (mysql_num_rows($result) > 0)
	{
		$body = mysql_fetch_array($result);
		if ($body)
		{
			$post['content'] = $body['content'];
		}
	}
	
	return $post;
}

// 从数据库得到某消息的标题
function get_post_title($postid)
{
	if ($postid < 1)
	{
		// postid invalid
		return '';
	}
	
	$conn = db_connect();
	
	$sql = "select title from header where postid = '$postid'";
	$reault = mysql_query($sql, $conn);
	if (mysql_num_rows($reault) != 1)
	{
		return '';
	}
	
	$row = mysql_fetch_array($result);
	
	return $row[0];
	
}

// 从数据库获得某消息的正文
function get_content($postid)
{
	if ($postid < 1)
	{
		return '';
	}
	
	$conn = db_connect();
	
	$sql = "select content from body where postid = '$postid'";
	$result = mysql_query($sql, $conn);
	
	if (mysql_num_rows($result) > 0)
	{
		$row = mysql_fetch_array($result);
		
		return $row[0];
	}
}

// 用 ">" 符号缩进一则消息正文
function add_quoting($string, $pattern = ">")
{
	return $pattern.str_replace("\n", "\n$pattern", $string);
}

// 在数据库中保存并检查新发表的文章
function store_new_post($post)
{
	$conn = db_connect();
	
	if (!filled_out($post))
	{
		return false;
	}
	
	$post = clean_all($post);
	
	if ($post['parent'] > 0)
	{
		$sql = "select postid from header where postid = '".$post['parent']."'";
		$result = mysql_query($sql);
		if (mysql_num_rows($result) != 1)
		{
			return false;
		}
	}
	
	// check not a duplicate
	$sql = "select header.postid from header, body where header.postid = body.postid and header.parent = '".
			$post['parent']."' and header.title = '".$post['title']."' and header.area = '".$post['area'].
			"' and body.content = '".$post['content']."'";
	$result = mysql_query($sql);
	if (!$result)
	{
		return false;
	}
	
	if (mysql_num_rows($result) > 0)
	{
		$row = mysql_fetch_array($result);
		
		return $row[0];
	}
	
	$sql = "insert into header values (NULL, '".$post['parent']."', '".$post['author']."', '".$post['title']."', 0, '".$post['area']."', time())";
	$result = mysql_query($sql);
	if (!$result)
	{
		return false;
	}
	
	$sql = "update header set children = children + 1 where postid = '".$post['parent']."'";
	$result = mysql_query($sql);
	if (!$result)
	{
		return false;
	}
	
	// find out post id note that there could be multiple headers that are the same except for id and probably posted time 
	$sql = "select header.postid from header left join body on header.postid = body.postid ".
			"where parent = '".$post['parent']."' and author = '".$post['author']."' and ".
			"title = '".$post['title']."' and body.postid is NULL";
	$result = mysql_query($sql);
	if (!$result)
	{
		return false;
	}
	
	if (mysql_num_rows($result) > 0)
	{
		$row = mysql_fetch_array($result);
		$id = $row[0];
	}
	
	if ($id)
	{
		$sql = "insert into body values ($id, '".$post['content']."')";
		$result = mysql_query($sql);
		if (!$result)
		{
			return false;
		}
		
		return $id;
	}
}

?>