<?php
// 新书入库的脚本实现
// ma_web5.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$year = $_POST["year"];
$month = $_POST["month"];
if ($year == "" || $month == "")
{
	echo "<p align = center> 日期选项不能为空! ";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}
else
{
	$time = $year."年".$month."月";
}

$name = $_POST["name"];
$author = $_POST["author"];
$pub = $_POST["pub"];
$memo = $_POST["memo"];
$num = $_POST["num"];
if ($name == "" || $author == "" || $time == "" || $pub == "" || $memo == "" || $num == "")
{
	echo "<p align = center> 所有选项不能为空";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}

$lend = 0;

// 构造SQL查询语句
$insert = "INSERT INTO book(name, author, time, pub, memo, num, lend)";
$insert .= "values('$name', '$author', '$time', '$pub', '$memo', $num, $lend)";
mysql_query($insert) or die("<p align = center> 录入时发生错误！");

$query = "SELECT id FROM book WHERE name = '$name' and pub = '$pub'";
$result = @mysql_query($query) or die("<p align = center> 录入时发生错误");
$row = mysql_fetch_row($result);
if ($row != 0)
{
	echo "<h1> <p align = center> 新书入库成功！</h1> <br> <br>";
	echo "<p align = center> 书籍编号是".$row[0];
	echo "<br> <br> <br>";
	echo "请记录下来！";
}
else
{
	echo "录入时发生错误";
	exit();
}

echo "<br> <p align = right> <a href = \"javascript:history.back()\"> 返回 &nbsp; &nbsp; &nbsp;</a>";

mysql_close($link);

?>