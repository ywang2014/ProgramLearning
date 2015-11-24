<?php
/*
* 初始化脚本
*	
*	作用：检测运行环境，并做相应的处理
*	比如：判断魔术引号有没有打开、判断当前是运行环境还是产品上线环境，设置相应的错误报告
*/

define('ROOT', 'D:/Soft/PHP/PHPnow-1.5.6/htdocs/127.0.0.100/Dev-process/');	// 定义绝对路径：根目录

require(ROOT."include/config.php");
require(ROOT."include/mysql.func.php");

// 检测当前是否是开发环境
if (DEBUG)	// 检测debug
{
	//echo "debug";
	error_reporting(E_ALL);	// 安全级别最高
}
else
{
	error_reporting(0);	// 不报任何错
}

// 检测魔术引号是否开启，若未开启，则递归处理$_POST/$_GET/$_COOKIE，进行转义
if (!get_magic_quotes_gpc())
{
	function _addslashes(&$v, $k)
	{
		$v = addcslashes($v);
	}
	
	// 递归处理
	array_walk_recursive(&$_GET, _addslashes);
	array_walk_recursive(&$_POST, _addslashes);
	array_walk_recursive(&$_COOKIE, _addslashes);
}

// 连接数据库
$conn = mysql_connect($_CFG['host'], $_CFG['user'], $_CFG['password']);
if (!$conn)
{
	exit('数据库连接错误');
}

mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");
//mysql_query("set names gb2312");
mysql_query("SET names utf8");

?>