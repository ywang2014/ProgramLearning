<?php
/*
	添加新书签到数据库中
*/
function add_bm($new_url)
{
	
}


function get_user_urls($username)
{
	$conn = db_connect();
	$sql = "select bm_url from bookmark where username = '$username'";
	$result = $conn->query($sql);
	if (!$result)
	{
		return false;
	}
	$url_array = array();
	
	for ($count = 0; $row = $result->fetch_row(); $count++)
	{
		$url_array[$count] = $row[0];
	}
	
	return $url_array;
}


function delete_bm($username, $url)
{
	$conn = db_connect();
	
	$sql = "delete from bookmark where username = '$username' and bm_url = '$url'";
	if (!$conn->query($sql))
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
			
	if (!($result = $conn->query($query)))
	{
		throw new Exception('Could not find any bookmarks to recommend.');
	}
	else if ($result->num_rows == 0)
	{
		throw new Exception('Could not find any bookmarks to recommend.');
	}
	
	$urls = array();
	for ($count = 0; $row = $result->fetch_object(); $count++)
	{
		$urls[$count] = $row->bm_url;
	}
	
	return $urls;
}

?>