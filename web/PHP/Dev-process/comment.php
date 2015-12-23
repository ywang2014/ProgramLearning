<?php 
/* 
	主页
*/

header('content-type: text/html; charset=utf-8');

if (! isset($_POST['content']))
{
	include('./static/template/comment.html');
	exit;
}
else
{
	print_r($_POST);
	exit;
}

?>
