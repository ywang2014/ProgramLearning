<?php
/*
	结束会话
*/
session_start();

echo 'The content of $_SESSION[\'sess_var\'] is '.$_SESSION['sess_var'].'<br>';

session_destroy();

?>

<a href = "session_start.php"> Home page </a>