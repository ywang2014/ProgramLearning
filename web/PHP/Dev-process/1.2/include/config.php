<?php
/*
* 可以命名为：config.inc.php

* 公共配置文件：
*	网站的运行参数
*	比如：主机名、数据库、密码等
*	
*	作用：当网站更换主机的时候，只需要修改主机即可。
*/

$_CFG = array();	// 空数组

$_CFG['host'] = 'localhost';
$_CFG['user'] = 'root';
$_CFG['password'] = 'wang';
$_CFG['dbname'] = 'project';
$_CFG['charset'] = 'utf-8';

define('DEBUG', true);	// 定义开发环境，true
?>