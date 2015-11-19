<?php
/*
	简单的身份验证机制
*/
$username = trim($_POST['username']);
$password = trim($_POST['password']);

if ((!isset($username)) || (!isset($password)))
{ ?>
	<h1> Please log in </h1>
	<p> You need login then you can visit this page. </p>
	<form method = "post" action = "secret.php">
		<p> Username: <input type = "text" name = "name"> </p>
		<p> Password: <input type = "password" name = "password"> </p>
		<p> <input type = "submit" name = "submit" value = "login"> </p>
	</form>
<?php
}
else if (($username === "user") && ($password == "pass"))
{
	echo '<h1> Success, you can access! </h1>';
}
else
{
	echo '<h1> Not Found </h1>';
}
?>