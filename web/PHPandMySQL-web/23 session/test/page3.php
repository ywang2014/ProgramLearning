<?php
/*
	结束会话
*/
session_start();

error_reporting(0);	// 禁止notice

echo "<h1> Session Destroy </h1>";

echo 'The content of $_SESSION[\'sess_var\'] is '.$_SESSION['sess_var'].'<br>';

session_destroy();

?>

<a href = "session_start.php"> Home page </a>