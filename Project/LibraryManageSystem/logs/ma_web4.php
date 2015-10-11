<?php
// ma_web4.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

// 完整性判断，检查用户是否填了所有的项目
$name = $_POST["name"];
$addr = $_POST["addr"];
$idnum = $_POST["idnum"];
$tel = $_POST["tel"];
$password = $_POST["password"];
$password0 = $_POST["password0"];
$email = $_POST["email"];
$sex = $_POST["sex"];

if ($name == "" || $addr == "" || $idnum == "" || $tel == "" || $password == "" || $password0 == "" || $email == "")
{
	echo "<p align = center> 所有选项不能为空！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}

// 检查两次的密码是否相同
if ($password != $password0)
{
	echo "<p align = center> 两次输入的密码不相同！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}

// 检查email 地址是否正确
if ($email != "")
{
	if (! strpos($email, "@") || ! strpos($email, "."))
	{
		echo "<p align = center> Email 地址格式错误";
		echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
		exit();
	}
}

$borrowed = 0;
$insert = "INSERT INTO reader(name, sex, email, addr, tel, idnum, password, max, borrowed)";
$insert .= "values('$name', '$sex', '$email', '$addr', '$tel', '$idnum', '$password', $max_lend_books, $borrowed)";
mysql_query($insert) or die("<p align = center> 录入时发生错误");

$query = "SELECT id FROM reader WHERE name = '$name' and password = '$password'";
$result = @mysql_query($query) or die("<p align = center> 录入时发生错误");
$row = mysql_fetch_row($result);
/*
print_r($result);
while ($row = mysql_fetch_row($result))
{
	$array[] = $row;
}
print_r($array);
*/

echo "<br><br> <h1> <p align = center> 用户注册成功 </h1> <br><br><br>";
echo "<p align = center> 您的借书证号是".$row[0];
echo "<br> <br>";

echo "这是能够唯一标识您的借书证的号码，请您务必牢记！！";
echo "<br> <p align = right> <a href = \"javascript:history.back()\"> 返回 &nbsp;&nbsp;&nbsp; </a>";

mysql_close();

?>