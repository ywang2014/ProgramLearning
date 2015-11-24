<?php 
header('content-type: text/html; charset=utf-8');

include("connection.php");

$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
$pageNum = 5;

$sql = "select * from news";
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
$sql = "select * from news limit $offset, $pageNum";
$result = mysql_query($sql);
while ($row = mysql_fetch_array($result))
{
	print_r(nl2br($row['title']));
	echo "<br>";
}

for($i = 1; $i <= $pages; $i++)
{
	if ($i == 1)
	{
		$show = ($i != $page) ? "<a href='news.php?page=".$i."'>首页</a>" : "<b>首页</b>";
	}
	else if ($i == $pages)
	{
		$show = ($i != $page) ? "<a href='news.php?page=".$i."'>尾页</a>" : "<b>尾页</b>";
	}
	else
	{
		$show = ($i != $page) ? "[ <a href='news.php?page=".$i."'>$i</a> ]" : "[ <b>$i</b> ]";
	}
    
    echo $show." ";
}


?>