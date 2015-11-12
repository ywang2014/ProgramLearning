<?php
/*
	数据库连接信息：
*/

$conn = mysql_connect("localhost", "root", "******");
@mysql_select_db("test", $conn);
mysql_query("set characterset 'utf8'");
mysql_query("set names 'utf8'");

?>