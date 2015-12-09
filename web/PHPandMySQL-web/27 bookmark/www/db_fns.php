<?php
/*
	数据库连接函数库
*/

function db_connect()
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

?>