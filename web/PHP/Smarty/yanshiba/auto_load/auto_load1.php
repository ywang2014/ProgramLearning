<?php
/*
	自动加载方法
	
	问题：此方法名，别人不能再使用了。
*/

function __autoload($class)
{
	include('./'.$class.'.class.php');
}

$man = new Man();

?>