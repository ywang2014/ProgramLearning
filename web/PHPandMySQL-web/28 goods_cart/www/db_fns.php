<?php
/*
	数据库操作函数
*/

function db_connect()
{
	if(date_default_timezone_get() != "Asia/Shanghai")
	{
		date_default_timezone_set("Asia/Shanghai");
	}
	
	$conn = mysql_connect('localhost', 'book_sc', 'book_sc') or die('Failed to connect the server host!');
	@mysql_select_db('book_sc', $conn) or die('Failed to connect the database!');
	mysql_query("set names utf8");
	
	return $conn;
}

function getAll($result)
{
	$rows = array();
	
	while ($row = mysql_fetch_array($resulr))
	{
		$rows[] = $row;
	}
	
	return $rows;
}

?>