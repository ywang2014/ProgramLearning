<?php
/*
	自动加载冲突问题
	
	使用第三方库、插件的时候，如果有自动加载
	如何协调这些加载
	
	1.都使用__autoload，重复定义，报错
	
	
	php解决办法
	spl_autoload_register()函数
	不负责自动加载函数，负责注册各自自动加载函数

*/
function __autoload($class)
{
	echo $class.<br/>;
}

function __autoload($class)
{
	echo $class.<br/>;
}

?>