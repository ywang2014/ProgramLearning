<?php
/*
	smarty配置文件
*/
if (!defined('ACCESS'))
{
	echo "<h1 align = \"center\" > 404 not found! </h1>";
	exit;
}

require_once('../Smarty3/libs/Smarty.class.php');

define('ROOT', 'D:/Soft/PHP/PHPnow-1.5.6/htdocs/127.0.0.100/www/mytest/');

require_once(dirname(ROOT)."/includes/functions.php");
require_once(dirname(ROOT)."/includes/config.inc.php");

$smarty = new Smarty();

$smarty->template_dir = ROOT."template123/";
$smarty->compile_dir = ROOT."compile123//";

$smarty->left_delimiter = '<{';
$smarty->right_delimiter = '}>';


?>