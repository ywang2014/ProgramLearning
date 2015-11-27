<?php 
/* 
	相册主页
*/
header('content-type: text/html; charset=utf-8');
require("./include/init.php");

$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
$pageNum = 10;

$sql = "select * from photos";
$total = mysql_num_rows(mysql_query($sql));
$pages = ceil($total/$pageNum);

/* 安全检查 */
if ($page > $pages)
{
	$page = $pages;	// 最大为pages，最后一页
}
else if ($page < 1)
{
	$page = 1;	// 最小为1，首页
}

$offset = ($page - 1)*$pageNum;
$sql = "select * from photos limit $offset, $pageNum";

if (!($list = getAll($sql, $conn)))
{
	$list = array(array());
}
/*
print_r($list);
exit;*/
include('./static/template/photo.html');
?>
