<?php
/*
	销毁session
*/

/*
	1.销毁其中某一个元素

unset($_SESSION['user']);
*/

/*
	2.直接将数组，变成空数组

$_SESSION = array();
*/

/*
	3.直接将数组，变成空数组

session_unset();
*/

/*
	4.文件本身都给删除了
*/
session_destroy();	

?>