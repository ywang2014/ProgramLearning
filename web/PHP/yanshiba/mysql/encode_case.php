<?php
/*

数据库不乱码

	实际使用案例：
	
	1.正确指定客户端编码
	2.合理选择连接器的编码
	3.正确指定返回值编码
	
	分析：网页
	网页使用utf8编码，因此client utf8
	数据库表是utf8，因此connection utf8
	返回值，用于网页显示，utf8
	set names utf8;
*/

$conn = mysql_connect('localhost', 'root', '123456');
$sql = 'use test';
mysql_query('set names utf8');

?>

<!DOCTYPE html>
<html>
	<head>
		<title> New Page </title>
		<meta http-equiv = "Content-Type" content = "text/html; charset=UTF-8">
		
		<script type = "text/javascript">
		
		</script>
		
		<style type = "text/css">
		
		</style>
	</head>
	
	<body>
		the reason is which encoding you choose not match to the decoding!
		<br>
		我是中国人！
	</body>
</html>
