<?php

function expand_all(&$expanded) 
{
	// mark all threads with children as to be shown expanded
	$conn = db_connect();
	$sql = "select postid from forums where children > 0";
	
	$rows = getRows($sql);
	$num = getNum($sql);
	for($i = 0; $i < $num; $i++)   
	{
		$expanded[$rows[$i]]=true;
	}
}

function get_post($postid) 
{
	// extract one post from the database and return as an array

	if(!valid_postid($postid)) 
	{
		return false;
	}

	$conn = db_connect();

	//get all header information from 'header'
	$sql = "select * from forums where postid = '".$postid."'";
	
	if(getNum($sql) != 1) 
	{
		return false;
	}
	
	$post = getRow($sql);

	// get message from body and add it to the previous result
	$sql = "select * from forum_body where postid = '".$postid."'";
	
    $body = getRow($sql);
    if($body) 
	{
		$post['content'] = $body['content'];
    }
	
	return $post;
}

function get_post_title($postid) 
{
	// extract one post's name from the database

	if(!valid_postid($postid)) 
	{
		return false;
	}

	$conn = db_connect();

	//get all header information from 'header'
	$sql = "select title from forums where postid = '".$postid."'";
	if(getNum($sql) != 1) 
	{
		return false;
	}
	
	$title = getRow($sql);
	return  $title[0];
}

function get_post_message($postid) 
{
	// extract one post's content from the database

	if(!valid_postid($postid)) 
	{
		return false;
	}

	$conn = db_connect();

	//get all header information from 'header'
	$sql = "select content from forum_body where postid = '".$postid."'";
	if(getNum($sql) != 1) 
	{
		return false;
	}
	
	$content = getRow($sql);
	return  $content[0];
}


function add_quoting($string, $pattern = '> ') 
{
	// add a quoting pattern to mark text quoted in your reply
	return $pattern.str_replace("\n", "\n$pattern", $string);
}

function store_new_post($post) 
{
	// validate clean and store a new post
	
	// check no fields are blank
	if(!filled_out($post))  
	{
		return false;
	}
	$post = clean_all($post);
	
	$conn = db_connect();

	//check parent exists
	if($post['parent'] != 0)   
	{
		$sql = "select postid from forums where postid = '".$post['parent']."'";
		if(getNum($sql) != 1) 
		{
			return false;
		}
	}

	// check not a duplicate
	$sql = "select forums.postid from forums, forum_body where
            forums.postid = forum_body.postid and
            forums.parent = ".$post['parent']." and
            forums.author = '".$post['author']."' and
            forums.title = '".$post['title']."' and
            forums.area = ".$post['area']." and
            forum_body.content = '".$post['content']."'";

  
	if(getNum($sql) > 0) 
	{
		// 说明已经存在了此文章
		
		$row = getRow($sql);
		
		return $row[0];
	}

	$sql = "insert into forums values
            (NULL,
			'".$post['parent']."',
            '".$post['author']."',
            '".$post['title']."',
            0,
            '".$post['area']."',
            now()
            )";

	if (! do_sql_ok($sql))
	{
		return false;
	}

	// note that our parent now has a child
	$sql = "update forums set children = 1 where postid = '".$post['parent']."'";
	if (! do_sql_ok($sql))
	{
		return false;
	}

	// find our post id, note that there could be multiple headers
	// that are the same except for id and probably posted time
	$sql = "select forums.postid from forums left join body on forums.postid = forum_body.postid
                   where parent = '".$post['parent']."'
                   and author = '".$post['author']."'
                   and title = '".$post['title']."'
                   and forum_body.postid is NULL";

	if (getNum($sql) > 0)
	{
		$row = getRow($sql);
		$id = $row[0];
	}

	if($id) 
	{
		$sql = "insert into forum_body values ($id, '".$post['content']."')";
		if (! do_sql_ok($sql))
		{
			return false;
		}

		return $id;
	}
}

?>
