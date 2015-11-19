<?php
/*
	身份验证，数据库
*/	
$username = trim($_POST['name']);
$password = trim($_POST['password']);

if ((!isset($username)) || (!isset($password)))
{ ?>
	<h1> Please login </h1>
	<p> You need login then you can visit this page. </p>
	<form method = "post" action = "secret.php">
		<p> Username: <input type = "text" name = "name"> </p>
		<p> Password: <input type = "password" name = "password"> </p>
		<p> <input type = "submit" name = "submit" value = "login"> </p>
	</form>
	<?php 
}
else
{
	// 分配用户权限 grant admin
	$conn = mysql_connect('localhost', 'admin', 'admin') or die('Cannot connect to database.');
	@mysql_select_db($conn, 'test');
	
	//$query = 'select count(*) from user where username = '.$username.' and password = '.$password;
	//$query = "select count(*) from user where username = '".$username."' and password = '".$password."'";
	$query = "select count(*) from user where username = '".$username."' and password = sha1('".$password."'");
	$result = mysql_query($query, $conn);
	if (!$result)
	{
		echo "Cannot run query.";
		exit;
	}
	
	$row = mysql_fetch_row($result);
	$count = $row[0];
	
	if ($count > 0)
	{
		echo '<h1> Success, you can access! </h1>';
	}
	else
	{
		echo '<h1> 404 Not Found </h1>';
	}
}


?>