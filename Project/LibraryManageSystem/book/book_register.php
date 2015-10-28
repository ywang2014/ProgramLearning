<!DOCTYPE html>
<html>
	<head>
		<meta charset = "utf-8">
		<title> New book warehouse </title>
		<style type="text/css">
			a:link,a:visited{text-decoration:none;}
			a:hover{text-decoration:none; color:gray;}
		</style>
	</head>
	<body>

	


<?php
// 新书入库的脚本实现
// ma_web5.php

include "../include/common.php";

// connection
$link = mysql_connect($hostname, $username, $hostpassword) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$year = trim($_POST["year"]);
$month = trim($_POST["month"]);
if ($year == "" || $month == "")
{
	echo "<p align = center> 日期选项不能为空! ";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}
else
{
	$time = $year."-".$month;
}

$name = trim($_POST["name"]);
$author = trim($_POST["author"]);
$pub = trim($_POST["pub"]);
$memo = trim($_POST["memo"]);
$num = trim($_POST["num"]);

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

$query = "SELECT * FROM book WHERE name = '$name' and pub = '$pub'";
$result = @mysql_query($query) or die("<p align = center> 录入时发生错误");
$row = mysql_fetch_array($result);
// print_r($row);
if ($row != 0)
{	?>
	<center>
	<h1> 新书入库成功！</h1>
	<hr>
	<div>
		<table cellpadding = 4>
			<tr>
				<td> 书籍编号: </td>
				<td> <font size = 4.5 color = "red"> <?php echo $row['id']; ?> </font>
						<strong> 请记录下来! </strong> 
				</td>
			</tr>
			<tr>
				<td> 书名：</td>
				<td> <?php echo $row['name']; ?> </td>
			</tr>
			<tr>
				<td> 作者：</td>
				<td> <?php echo $row['author']; ?> </td>
			</tr>
			<tr>
				<td> 出版社：</td>
				<td> <?php echo $row['pub']; ?> </td>
			</tr>
			<tr>
				<td> 备注：</td>
				<td> <?php echo $row['memo']; ?> </td>
			</tr>
		</table>
	</div>
	
	<?php
}
else
{
	echo "录入时发生错误";
	exit();
}

echo "<br> <p align = right> <a href = \"javascript:history.back()\"> 返回 &nbsp;</a>";

mysql_close($link);

?>

	</body>
</html>