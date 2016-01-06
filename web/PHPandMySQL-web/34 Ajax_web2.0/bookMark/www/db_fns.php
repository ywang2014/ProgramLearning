<?php
/*
	数据库连接函数库
*/

function db_connect_mysqli()
{
	$result = new mysqli('localhost', 'friend', 'friend', 'friends');
	if (! result)
	{
		throw new Exception('Could not connect to database server');
	}
	else
	{
		return $result;
	}
}

function db_connect()
{
	$conn = mysql_connect("127.0.0.1", "root", "wang") or die("Server host is busy!");
	@mysql_select_db("friends", $conn) or die("Database is busy!");
	mysql_query("set names utf8", $conn);
	
	return $conn;
}

?>