<?php

/*
	框架初始化
*/

// 设置报错级别
define('DEBUG', true);

if (DEBUG == true)
{
	error_reporting(E_ALL);
}
else
{
	error_reporting(0);
}

// 初始化绝对路径
echo __FILE__;

echo dirname(__FILE__);
// 计算根目录
define('ROOT', str_replace('\\', '/', dirname(dirname(__FILE__))).'/');

include(ROOT.'include/db.class.php');
include(ROOT.'include/config.class.php');
include(ROOT.'include/log.class.php');
include(ROOT.'include/function.base.php');


?>