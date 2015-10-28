<?php
// 负责登录处理的php脚本程序
// ma_log.php
$id = $_POST["id"];
$password = $_POST["password"];

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $hostpassword) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$query = "SELECT * FROM manage WHERE id = $id and password = '$password'";
$result = mysql_query($query);
if ($result == 0)
{
	echo "Sorry, 数据库服务器查询是失败！";
	exit();
}
// 计算符合条件的记录行数，以此判断账号是否存在：查找的时候，同时验证账号和密码！
$num = mysql_num_rows($result);
if ($num != 0)
{
	// 账号存在，且密码验证正确，跳转到管理员功能界面
	header("Location: ma_web.html");
}
else
{
	// 账号或者密码错误，需要重新登录
	echo "<center> 对不起，用户名不存在或者密码错误！！<br>";
	echo "<a href = retry.php> 请重新输入！</a> </center>";
}

// close the DB connect 
mysql_close();

?>