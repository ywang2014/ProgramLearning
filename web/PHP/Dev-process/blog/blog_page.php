<?php
/*
* 动态页面
*/
header('content-type: text/html; charset=utf-8');

require('../include/init.php');

$bid = $_GET['bid'] + 0;	// 通过id查询
if ($bid < 1)
{
	// id 不可能小于1，非法
	exit('id 非法');
}

$sql = "select * from blogs where bid = '$bid'";

$blog = getRow($sql, $conn);
if (empty($blog))
{
	exit('查找失败，id非法！');
}

//$sql = "select * from reply where pid = '$pid' order by replytime";
$sql = "select * from comments where bid = '$bid' order by ptime";

if($comments = getAll($sql, $conn))	// 回复可能有多行记录
{
	// 有回复
}
else
{
	$comments = false;
}

include('../static/template/blog_page.html');

?>

