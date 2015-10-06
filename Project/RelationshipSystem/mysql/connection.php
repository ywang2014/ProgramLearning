<?php
// 连接数据库

include "common.php"

$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

@mysql_select_db($dbname, $link) or die("数据库连接失败！");

?>