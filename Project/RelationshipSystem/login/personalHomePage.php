<?php

require('../include/init.php');
$cid = $_GET['cid'];

$query = "SELECT * FROM classmates WHERE cid = '$cid'";
$result = getRow($query, $conn);
?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
		<style text = "text/css">
			body {text-align:center}
			.mytable{ border-right:1px dashed gray}
			.content { border:1px dashed #334455 }
			.left { float:left; }
		</style>
	</head>
	
	<body background = "../images/asensualdawn.jpg">
	<center>
		<h1 style = "color: red"> Welcome to Personal Relationship Network Space </h1>
		<hr>
		<table>
			<tr>
				<td width = 50 > <a style="text-decoration:blink" href = "index.html"> 首页 </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://www.calm.com/"> Calm </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://www.sina.com.cn/"> 新浪 </a> </td>
				<td align = "center" width = 50 > <a style="text-decoration:blink" href = "http://www.trends.com.cn/"> 时尚 </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://www.qq.com/"> 腾讯 </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://www.163.com/"> 网易 </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://www.youku.com/"> 优酷 </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "http://china.nba.com/"> NBA </a> </td>
				<td width = 50 > <a style="text-decoration:blink" href = "https://www.baidu.com/"> 百度 </a> </td>
				<td width = 70 > <a style="text-decoration:blink" href = "http://www.google.cn/"> Google </a> </td>
				<td width = 70 > <a style="text-decoration:blink" href = "https://github.com/"> Github </a> </td>
			</tr>
		</table>
		<p> 
			<!--------- border : border-width || border-style || border-color -------->
			<hr style="border:0.5px dashed #000; height:1px">
			<hr style="border:1px dotted #036" />
			<hr style="border:0.5px solid #ff0000"/>
			<hr style="border:1px double #e8e8e8"/>
		</p>
		
		<div class = "content"> 
			
		</div>
		<div >
			<div style = "margin:0 auto;">
				<div class = "left" style = "width:20%;">
					<table class = "mytable">
						<tr>
							<td> 
								<p> 您好，<?php echo $result['name'] ?> </p>
								<p> <a href = "#"> <?php echo $result['email'] ?> </p>
							</td>
						</tr>
					</table>
				</div>
				<div class = "left" style = "width:70%;">
					<font size = 5> 好友信息 </font>
					<table class = "mytable">
						
						<tr>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
							<td> 
								<p> 你的好友很多 </p>
							</td>
						</tr>
					</table>
				</div>
				<div class = "left" style = "width:10%;">
					<table>
						<tr class = "mytable">
							<td > 推荐信息 </td>
						</tr>
						<tr>
							<td> 

							</td>
						</tr>
					</table>
				</div>
			</div>
		<div>
	</center>				
	</body>
</html>