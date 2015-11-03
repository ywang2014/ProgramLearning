<?php
/*
	分离 php 与 html 代码
*/

?>

<?php
/*
	模拟连接数据库，读取数据
	$conn = mysql_connect();
	$sql = "select * from ...";
*/

$title = "两会召开";
$content = "国务院发布最新通知：内容如下...";


include('./temp_php.html');

/*
	temp.html中的php只负责echo数据，传入动态页面需要的数据
	html代码负责专门的框架--标签、css等
*/

?>