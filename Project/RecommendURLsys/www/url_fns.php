<?php
/*
	添加新书签到数据库中
*/
function add_bm($new_url)
{
	$conn = db_connect();
	
	$username = $_SESSION['valid_user'];
	
	$sql = "select * from bookmark where bm_url = '$new_url' and username = '$username'";
	
	$result = mysql_query($sql);
	if (!$result)
	{
		throw new Exception('could not execute query');
	}
	else if (mysql_num_rows($result) > 0)
	{
		throw new Exception('That url has been added, go back and choose another one.');
	}
	else
	{
		$sql = "insert into bookmark (username, bm_url) values ('$username', '$new_url')";
		$result = mysql_query($sql);
		if (!$result)
		{
			throw new Exception('Could not add url in database, please try again later.');
		}
	}
	
	return true;
}


function get_user_urls($username)
{
	$conn = db_connect();
	$sql = "select bm_url from bookmark where username = '$username'";
	$result = mysql_query($sql);
	
	if (!$result)
	{
		return false;
	}
	$url_array = array();
	
	for ($count = 0; $row = mysql_fetch_row($result); $count++)
	{
		$url_array[$count] = $row[0];
	}
	
	return $url_array;
}


function delete_bm($username, $url)
{
	$conn = db_connect();
	
	$sql = "delete from bookmark where username = '$username' and bm_url = '$url'";
	if (!mysql_query($sql))
	{
		throw new Exception('Bookmark could not be deleted.');
	}
	
	return true;
}


// 推荐
function recommend_urls($username, $popularity = 1)
{
	$conn = db_connect();
	
	$sql = "select bm_url from bookmark where username in".
				"(select distinct(b2.suername) from bookmark b1, bookmark b2 where b1.username = '".$username."'".
				"and b1.username != b2.username and b1.bm_url = b2.bm_url)".
			"and bm_url not in (select bm_url from bookmark where username = '".$username."')".
			"group by bm_url having count(bm_url)>".$popularity;
			
	if (!($result = mysql_query($sql)))
	{
		throw new Exception('Could not find any bookmarks to recommend.');
	}
	else if (mysql_num_rows($result) == 0)
	{
		throw new Exception('Could not find any bookmarks to recommend.');
	}
	
	$urls = array();
	for ($count = 0; $row = mysql_fetch_array($result); $count++)
	{
		$urls[$count] = $row->bm_url;
	}
	
	return $urls;
}

?>