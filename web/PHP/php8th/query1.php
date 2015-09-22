<?php

// query1.php

// 连接数据库
$link = mysql_pconnect($localhost, $username, $password);
if ($link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库连接错误！')";
	echo "</script>";
	exit();
}

// 激活数据库
if (mysql_select_db(exam, $link) == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库exam激活失败！')";
	echo "</script>";
	exit();
}

$query = "SELECT count FROM exam WHERE mark >= $low AND mark <= $high";
$count_link = mysql_query($query, $link);
if ($count_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}
$count = mysql_fetch_row($count_link);

$query = "SELECT sum(mark) FROM exam WHERE mark >= $low AND mark <= $high";
$sum_link = mysql_query($query, $link);
if ($sum_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}
$sum = mysql_fetch_row($sum_link);

$average = $sum[0] / $count[0];
?>

<html>
	<head>
		<meta charset = "utf-8">
	</head>
	<h1 align = center> 查询结果 </h1>
	<h3> 共有 
		<?php echo("$count[0]"); ?> 
		人
	</h3>
	<h3>
		他们的平均分是
		<?php echo("$average"); ?>
	</h3>
	<a href = query.html> 返回 </a>
</html>