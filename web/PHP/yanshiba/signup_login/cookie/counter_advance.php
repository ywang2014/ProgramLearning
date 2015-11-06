<?php
/*
	cookie完成浏览历史功能
	
	cookie计数器
*/

/* 
	第一次访问，仅服务器设置cookie，浏览器根本没有cookie，Notice提示没有$_COOKIE['num'] 
	只有刷新的时候，才会显示有cookie值，因此比你实际访问次数小一次。
	因此改进方法：
	赋值给一个变量，变量的值，就是同步的值
*/

if(!isset($_COOKIE['num']))	// 第一次，没有cookie
{
	$num = 1;	// 设置初始值为1
}
else
{
	$num = $_COOKIE['num'] + 1;
}
setcookie('num', $num);	

echo "这是你的第 ".$num." 次访问！";

?>