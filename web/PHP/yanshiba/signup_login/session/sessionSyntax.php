<?php
/*
	session语法学习：
	创建、修改、销毁
	
	创建：直接使用超级数组，赋值即可
	
	修改：重新赋值即可
	
	销毁：	unset($_SESSION['user']);	// 销毁其中某一个元素
			$_SESSION = array();	// 直接将数组，变成空数组
			session_unset();		// 同上
			session_destroy();		// 文件本身都给删除了
	
	第一步必须，session_start()
*/
session_start();

$_SESSION['user'] = 'zhang3';
$_SESSION['company'] = 'xinlang';

echo "ok";


?>