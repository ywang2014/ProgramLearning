<?php
/*
	使用大括号 {}形式
	
	可以直接使用 <?php echo ;?>
	更好：原生php输出，不需要解析大括号标签
	
	smarty可以不使用，但是模板肯定会用到！
*/

$title = "My Smarty";
$content = "I will parse the {} to <??> by myself";

include('./temp_smarty.php');

/*
	自己写一个简单模板类，解析这个html模板
	
	作用：把html标签，解析成php语句
*/

?>