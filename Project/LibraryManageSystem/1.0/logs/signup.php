<html>
	<meta charset = "utf-8">
	<script type = "text/css">
		a{text-decoration:none; color: #0000cc}
		a:link{text-decoration:none; color: #000000; font-size: 24px;}
	</script>
	
<body>

<?php
// 负责登录处理的php脚本程序
// login.php

$name = trim($_POST["name"]);
$sex = trim($_POST["sex"]);
$password = trim($_POST["password"]);
$repassword = trim($_POST["repassword"]);
$email = trim($_POST["email"]);
$idnum = trim($_POST["idnum"]);
$tel = trim($_POST["tel"]);
$job = trim($_POST["job"]);
$addr = trim($_POST["addr"]);

if ($name == "" || $password == "" || $repassword == "" || $email == "" || $addr == "" || $idnum == "" || $tel == "" || $job == "")
{
	echo "<p align = center> 对不起，您还有选项没有填完！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}

/*
// 用户名是否存在的验证
$query = mysql_query("select id from t_user where username='$name'"); 
$num = mysql_num_rows($query); 
if($num==1){ 
    echo '用户名已存在，请换个其他的用户名'; 
    exit; 
}  
*/

// 检查两次的密码是否相同
if ($password != $repassword)
{
	echo "<p align = center> 对不起，您的两次输入的密码不相同！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}
// 加密密码

$passwordmd5 = md5($password.$name);

// 检查email 地址是否正确
if ($email != "")
{
	$pattern="/([a-z0-9]*[-_.]?[a-z0-9]+)*@([a-z0-9]*[-_]?[a-z0-9]+)+[.][a-z]{2,3}([.][a-z]{2})?/i";
	//if (! strpos($email, "@") || ! strpos($email, "."))
	if (! preg_match($pattern, $email))
	{
		echo "<p align = center> Email 地址格式错误";
		echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
		exit();
	}
}

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $hostpassword) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$borrowed = 0;
$insert = "INSERT INTO reader(name, sex, email, addr, tel, idnum, password, max, borrowed)";
$insert .= "values('$name', '$sex', '$email', '$addr', '$tel', '$idnum', '$passwordmd5', $max_lend_books, $borrowed)";
mysql_query($insert) or die("<p align = center> 录入时发生错误");

$query = "SELECT id FROM reader WHERE name = '$name' and email = '$email'";
$result = @mysql_query($query) or die("<p align = center> 录入时发生错误");

$num = mysql_num_rows($result);
if ($num != 0)
{
	// $row = mysql_fetch_row($result); // 不能使用 row["id"]访问，需要使用数字访问结果，如：row[0]
	$row = mysql_fetch_array($result);
	echo "<h1> <p align = center> 用户注册成功 </h1>";
	echo "<p align = center> 您的借书证号是 ".$row["id"]."<br>";
	echo "这是能够唯一标识您的借书证的号码，请您务必牢记！！</p>";
	echo "<p align = right> <a href = \"../users/personal.html\"> 用户空间 </a>";
}
else
{
	// 注册失败
	echo "<center> 对不起，注册不成功！<br>";
	echo "<p align = right> <a href = \"javascript:history.back()\"> 返回 </a>";
}

mysql_close();

// 找到SQL，输入如下语句：ALTER TABLE reader AUTO_INCREMENT = 100。下一个用户将从100开始。
?>


