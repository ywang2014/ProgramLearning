<?php
/*
	文件乱码问题
*/

// 第一步
header("content-Type: text/html; charset=Utf-8"); //设置字符的编码是utp-8
mysql_query('set names utf8');

// 第二步
$temp = utf8Encode('张三');
$template->setVariable("CUSTOMERNAME", $temp);

// 第三步
php页面
$temp=urlencode('张三');
$template->setVariable("CUSTOMERNAME",$temp);
// 模板页面  输出时用urldecode函数解码

/* 第四步
	mb_convert_encoding
	iconv
	*/
$str='张三';
$temp= mb_convert_encoding($str, "UTF-8", "auto"); //未知原编码，通过auto自动检测后，转换编码为utf-8 或者
$temp=mb_convert_encoding($str, "UTF-8", "GBK"); //已知原编码为GBK，转换为utf-8
$template->setVariable("CUSTOMERNAME",$temp);
//模板页直接调用不用解码，你再试下
?>