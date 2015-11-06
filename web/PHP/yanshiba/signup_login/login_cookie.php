<?php
/*
	不能访问的信息，如何显示？
	非合法用户，不能看见的提示
	
	1.检测用户名，密码，再定义常量
*/

setcookie('username', 'Alice');
echo "设置好了cookie";





/*

$conn = mysql_connect('localhost', 'root', 'wang');
@mysql_select_db('users', $conn);
mysql_query('set names utf8');

$username = $_POST['username'];
$password = $_POST['password'];

$sql = "select count(*) from user where username = '$username' and password = '".md5($password)."'";
$res = mysql_query($sql, $conn);
$row = mysql_fetch_row($res);
// print_r($row);
if ($row[0] == 1)
{
	echo "登录成功";
	define("USER", true);	// 定义常量法
}
else
{
	echo "用户名或密码错误";
	exit;
}

if (USER != true)
{
	echo "你没有登录，请登录";
	exit;	// 直接退出很重要！
}


// 执行到这个地方，说明前面的 if语句执行成功！
echo "你是合法用户，你可以看见这些信息";
echo $username;

?>

<a href = "login_action2.php"> 个人信息 </a>
<!-- 此时就有问题，状态不能保留 -->
*/