<?php

// basic.php
// 基本的数据情况查询

// 连接数据库
link = mysql_pconnect($localhost, $username, $password);
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

$query = "SELECT sum(mark) FROM exam";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}

$result = mysql_fetch_row($result_link);
if ($result == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}

$query = "SELECT count(*) FROM exam";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}
$count = mysql_fetch_row($result_link);
if ($count == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}

$average = $result[0] / $count[0];

$query = "SELECT count(*) FROM exam WHERE mark >= 60";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}
$pass = mysql_fetch_row($result_link);
if ($pass == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}

$pass_ratio = $pass[] / $count[];

$query = "SELECT count(*) FROM exam WHERE mark >= 80";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}
$good = mysql_fetch_row($result_link);
if ($good == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询失败！')";
	echo "</script>";
	exit();
}

$good_ratio = $good[0] / $count[0];

?>

<html>
	<head> 
		<meta charset = "utf-8">
		<title> 基本情况 </title>
	</head> 
	
	<body>
		<h1 align = "center">
			考试基本情况
		</h1>
		<p align = "left"> 参加考试人数：
			<?php echo("$count"); ?>
		</p>
		<p align = "left"> 平均分：
			<?php echo("$average"); ?>
		</p>
		<p align = "left"> 及格人数：
			<?php echo("$pass"); ?>
		</p>
		<p align = "left"> 及格率：
			<?php echo("$pass_ratio"); ?>
		</p>
		<p align = "left"> 优秀人数：
			<?php echo("$good"); ?>
		</p>
		<p align = "left"> 优秀率：
			<?php echo("$good_ratio"); ?>
		</p>
		
		<a href = query.html> 查询 </a>
		
	</body>
</html>