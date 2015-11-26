<?php
/*
	实际样例程序
	
	<img title = "点击刷新" src = './captcha.php' align = "absbottom" onclick = "this.src = 'captcha.php?'+Math.random();" />
*/
header('Content-type: text/html; charset=utf-8');

session_start();

//session_unset();
unset($_SESSION['wuliu_captcha']);

?>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8">
		<title> Session 验证码 </title>
		<style type = "text/css">
			*{
				padding:0px;
				margin:0px;
			}
			#login p{
				margin-top:15px;
				line-height:20px;
				font-size:14px;
				font-weight:bold;
			}
			#login img{
				cursor:pointer;
			}
			form{
				margin-left:20px;
			}
		</style>
	</head>
	
	<body>
		<form id = "login" action = "case1_act.php" method = "post">
			<p> 验证码实例 </p>
			<p>
				<span> 验证码：<span>
				<input type = "text" name = "validate" value = "" size = 10>
				<img title = "点击刷新" src = './captcha.php' align = "absbottom" onclick = "this.src = 'captcha.php?'+Math.random();" />
			</p>
			<p>
				<input type = "submit">
			</p>
		</form>
	</body>
</html>