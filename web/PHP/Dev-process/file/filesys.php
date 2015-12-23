<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");

$sql = "select * from files where status = 1";
if (!($rows = getAll($sql, $conn)))
{
	$rows = array(array());
}

// 读取文件
$sql = "select * from files where status = 1 order by uptime desc limit 5";
$files = getAll($sql, $conn);

include('../static/template/filesys.html');
?>
