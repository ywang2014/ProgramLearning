<?php
/*
	用户注册，登录和退出
	cookie session
	控制用户，只能查看自己的信息
*/

$user_id = $_GET['user_id'] + 0;

$conn = mysql_connect('localhost', 'root', 'wang');
@mysql_select_db('users', $conn);
mysql_query('set names utf8');

$sql = 'select * from user where user_id = '.$user_id;
$res = mysql_query($sql, $conn);
$row = mysql_fetch_array($res);

print_r($row);

/*
	如何控制，只能看见自己的信息
*/

?>