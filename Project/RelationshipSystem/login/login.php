<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
	</head>
</html>

<?php

require('../include/init.php');
$name = $_POST['name'];
$password = $_POST['password'];

$query = "SELECT * FROM classmates WHERE name = '$name' and birthday = '$password'";
$result = getRow($query, $conn);
//print_r($result);
//exit;

if ($result != 0)
{
	header("Location: personalHomePage.php?cid=".$result['cid']);
}
else
{
	echo "<script> alert('用户名不存在或者密码错误，请重新输入！'); history.go(-1); </script>";
}

mysql_close();

?>
