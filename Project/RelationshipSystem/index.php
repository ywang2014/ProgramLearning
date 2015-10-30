<?php
require("include/init.php");
?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
		<style text = "text/css">
			a{text-decoration:none; color: #000066}
			a:link{text-decoration:none; color: #002266; font-size: 14px;}
			a:visited {text-decoration:none; color: #005588}
			a:active {text-decoration: none; color: #0000ff}
			a:hover{text-decoration:none; color: #ef7a82}
		</style>
	</head>
	
	<body background = "images/background.jpg">
		<h1 align = center style = "color: red"> Welcome my deal friends </h1>
		<div>
			<div>
				<p align = "right">
					<a style="text-decoration:blink" href = "login/login.html"> 登录 </a>
					<a style="text-decoration:none" href = "login/register.html"> 注册 </a>
				</p>
			</div>
		</div>
		
		<div>
			<center>
				<form action = "mysql/search.php" method = "post">
					<table border = 0>
						<tr>
							<td>
								<select name = "search_topic" style = "height:40px">
									<option value = "name" selected = "selected"> 姓名 </option>
									<option value = "school"> 学校 </option>
									<option value = "birthday"> 生日 </option>
									<option value = "hobby"> 兴趣爱好 </option>
								</select>
							</td>
							<td>
								<input type = "text" style = "width:300px; height:40px" name = "search_keyword" value = "请输入关键字">
							</td>
							<td>
								<input type = "submit" style = "width:80px; height:40px" value = "信息搜索">
							</td>
						</tr>
					</table>
				</form>
			</center>
		</div>
		<div>
			<div style = "height:480px;">
				
			</div>
		</div>
				
<?php
	require("include/footer.php");
?>