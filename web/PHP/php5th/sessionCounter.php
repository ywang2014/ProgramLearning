<meta charset = 'utf-8'>

<?php 
// PHP4 才内置了对session的创建和管理 (低版本：PHPLIB)

// session 计数器

/* 第一次访问页面时，初始化一个变量，重新装入页面时增加计数 */

// 初始化一个session
session_start();	/* 检查session是否存在，不存在则创建一个新的 */

// 注册一个session变量
session_register('counter');

// 增加计数器
$counter++;
echo("你访问了这个页面已经 $counter 次了");

?>