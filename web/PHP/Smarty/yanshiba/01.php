<?php
/*
	smarty:
	
	在比较的项目中，分工较细，html代码，一般专门由前端做的
	php程序员，在html代码中，加入到php代码，形成动态页面
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

?>

<!DOCTYPE html PUBLIC "-//WAC//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml" lang = "zh-CN">
	<head>
		<title> <?php echo $title; ?> </title>
		<meta http-equiv = "Content-Type" content = "text/html" charset = "utf-8">
		<meta name = "description" content = "">
		<meta name = "keywords" content = "">
		
		<script type = "text/javascript">
		
		</script>
		
		<style type = "text/css">
		
		</style>
	</head>
	
	<body>
		<p> <?php echo $content; ?> </p>
		
	</body>
</html>