<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
	</head>
</html>

<?php
$name = $_POST["name"];
$password = $_POST["password"];

include "mysql/connection.php";

$query = "SELECT * FROM friends WHERE name = $name and birthday = '$password'";
$result = mysql_query($query);
if ($result == 0)
{
	echo "Sorry, 数据库服务器查询是失败！";
	exit();
}

$num = mysql_num_rows($result);
if ($num != 0)
{
	header("Location: personalHomePage.html");
}
else
{
	echo "<script> alert('用户名不存在或者密码错误，请重新输入！'); history.go(-1); </script>";
}

mysql_close();

?>
