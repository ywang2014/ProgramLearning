<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
		<style text = "text/css">
			h:hover{color: #ef7a82}
			a{text-decoration:none; color: #000066}
			a:link{text-decoration:none; color: #002266; font-size: 14px;}
			a:visited {text-decoration:none; color: #005588}
			a:active {text-decoration: none; color: #0000ff}
			a:hover{text-decoration:none; color: #ef7a82}
			
		</style>
	</head>
	
	<body 
		<div>
			<div style = "height:60px; background-color:#a1afc9;">
				<table align = "center" border = 0>
					<tr>
						<td align = "center" style = "width:200px;">
							<a href = "../index.html"> <font size = 6> Homepage </font> </a>
						</td>
						<td style = "width:800px;">
							<table>
								<tr>
									<td width = "30%"> 
										<a href = ""> <font size = 6>  </font> </a>
									</td>
									<td width = "30%"> 
										<a href = ""> <font size = 6>  </font> </a>
									</td>
									<td width = "40%"> 
										<a href = ""> <font size = 6>  </font> </a>
									</td>
								</tr>
							</table>
						</td>
						<td width = style = "width:600px;">
							<table>
								<tr align = "center">
									<td width = 100> 
										<a href = ""> <font size = 6>  </font> </a>
									</td>
									<td width = 100> 
										<a href = "signup.html"> <font size = 6> Login </font> </a>
									</td>
									<td width = 100> 
										<a href = ""> <font size = 6> Signup </font> </a>
									</td>
								</tr>
							</table>
						</td>
					</tr>
				</table>
			</div>
		</div>
		<div style = "padding:15px;">
			<p>
				<h1 align = center style = "color: red"> 欢迎使用图书搜索 </h1>
				<hr>
			</p>
			<p align = "right">
				<?php 
					require_once("../include/showLocalTime.php");
					show_His_Time();
				?>
			</p>
		</div>
		
		<?php require_once("base_search_.php") ?>
		
		<div>
			<div style = "height:380px;">
				
			</div>
		</div>
			
		<div style = "position:bottom; height: 20%; background-color:#a1afc9;">
			<center>
				<br>
				<p> <font size = 4>&copy; </font>权力声明：</p>
				<p> All rights reserved! </p>
			</center>
		</div>
	</body>
</html>