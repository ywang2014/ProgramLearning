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

/*
// 配置smarty左右定界符
$smarty->left_delimiter = '{<';
$smarty->right_delimiter = '>}';
*/
// {literal}标签告诉smarty直接输出，不解析


$title = 'Resume';
// array 数据库取数据结果一般都是数组
$user = array('name'=>'Alice', 'tel'=>'13100000000', 'email'=>'123@126.com');

// key为字符串的时候--关联数组，html模板中，只能使用 $var.key 
$us = array('name'=>'Lena', 'tel'=>'18700000000', 'email'=>'123@163.com');

// key为数字的时候--索引数组，html模板中，可以使用索引$var[i]，也可以使用$var.key
$us2 = array(0=>'John', 1=>'13600000000', 2=>'123@sina.com');

// assignment
$smarty->assign('title', $title);

$smarty->assign('name', $user['name']);
$smarty->assign('tel', $user['tel']);
$smarty->assign('email', $user['email']);

$smarty->assign('us', $us);	// 直接传数组

$smarty->assign('us2', $us2);

// show in broswer
$smarty->display('test2.html');

?>