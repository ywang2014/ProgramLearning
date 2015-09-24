<?php
// ma_web4.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

// 完整性判断，检查用户是否填了所有的项目
if ($name == "" || $addr == "" || $idnum == "" || $tel == "" || $password == "" || $password0 == "" || $email == "")
{
	echo "<p align = center> 所有选项不能为空！";
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

echo "<p align = center> 用户注册成功 <br>";
echo "您的借书证号是".$row[id];
echo "<br>";

echo "这是能够唯一标识您的借书证的号码，请您务必牢记！！";

mysql_close();

?>