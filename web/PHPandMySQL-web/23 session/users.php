<?php
/*
	网站用户身份验证
*/

session_start();

echo "<h1> Members only </h1>";

if (isset($_SESSION['user']))
{
	echo "<p> You are logged in as ".$_SESSION['user']."</p>";
	echo "<p> Members only content goes here!</p>";
	echo "123456<br>";
	
	echo "<a href = \"logout.php\"> logout </a>";
}
else
{
	echo "<p> You are not logged in </p>";
	echo "<p> Please logged !</p>";
	
	echo "<a href = \"check_auth.php\"> Back to login page </a>";
}


?>