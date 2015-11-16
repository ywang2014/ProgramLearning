<?php
/*
	测试网页间的链接跳转路径
	是哪个相对路径
	index.html---index.php
	index.php---login.php
*/

define('ACCESS', true);

header("Content-Type: text/html; charset=utf-8;");

require_once('main.php');

$title = "我是主页";
$content = "能不能链接到其他的网页呢？";

$smarty->assign('title', $title);
$smarty->assign('content', $content);

$smarty->display("index.html");

?>