<?php
/*
	1.下载smarty
	2.引入smarty
	3.实例化对象
	4.配置文件目录
	
	如下实例：即smarty使用方法，大体流程就是这么简单！
	
	assign 将对应的值，赋给对应的标签！-- “标签一定要正确”
	
*/

// include smarty
require('../Smarty3/libs/Smarty.class.php');

// instance
$smarty = new Smarty();
//print_r($smarty);

// configure
$smarty->template_dir = './template123';
$smarty->compile_dir = './compile123';

// variable
$title = 'Smarty-test';
$content = 'I like php program, so I want to learn smarty template to help my project.';

// assignment
//$smarty->assign('title', 'Smarty-test');
$smarty->assign('title', $title);
//$smarty->assign('content', 'I like php program, so I want to learn smarty template to help my project.');
$smarty->assign('content', $content);

// show in broswer
$smarty->display('test.html');

?>