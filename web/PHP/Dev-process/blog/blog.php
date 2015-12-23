<?php 
/* 主页
* php 可以与 html 混合
* php解释器，见到<?php ?> 才当做php解释！
*/

header('content-type: text/html; charset=utf-8');
require("../include/init.php");

@mysql_select_db($_CFG['dbname'], $conn) or die ("数据库连接失败！");

$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
$pageNum = 10;

$sql = "select * from blogs";
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
$sql = "select * from blogs order by ptime desc limit $offset, $pageNum";	// 逆序排列，新发项目的显示在前面
$list = getAll($sql, $conn);

include('../static/template/blog.html');

?>
