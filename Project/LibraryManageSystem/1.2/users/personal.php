<?
include "../include/common.php";
$link = mysql_connect($hostname, $username, $hostpassword) or die("数据库服务器连接失败！");
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$rid = $_GET['rid'] + 0;	// 通过id查询
if ($rid <= 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = 'select * from reader where id='.$rid;
$result = mysql_query($sql);

if ($result == 0)
{
	echo "Sorry, 数据库服务器查询失败！";
	exit();
}

$row = mysql_fetch_array($result);

mysql_close();
?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> PersonalHomePage </title>
		<style type = "text/css">
			h1{color: #ff0000;}
			h1:hover{color: #d6ecf0}
			
			a{text-decoration:none; color: #0000cc}
			a:link{text-decoration:none; color: #0000ff; font-size: 14px;}
			a:visited {text-decoration:none; color: #005588}
			a:active {text-decoration: none; color: #0000ff}
			a:hover{text-decoration:none; color: #ef7a82}
			
			.content
			{
				width: 300px;
				margin-left: auto;
				margin-right: auto;
			}
			
			.body{
				height: auto;
				width: auto;
				background: url(../images/shinei.jpg) repeat-x;
			}
		</style>
	</head>
	<body>
		<div valign = "middle" style = "width: 100%; height: 120px; background-color: blue;">
			<br>
			<h1 align = center valign = "middle"> Welcome to your home page </h1>
		</div>
		<div style = "background-color:#b0a4e3;" > 
			<table border = 0 valign = "middle">
				<tr valign = "middle" cellpadding = 0 height = 50>
					<td align = "left" valign = "middle">
						<a href = "../library/index.html"> <font size = 4> 首页 </font> </a>
					</td>
					<td width = 400>
					
					</td>
					<td width = 100>
						<li> <a href = "../logs/ma_web5.html"> <font size = 4> 借书记录 </font> </a> </li>
					</td>
					<td width = 100>
						<li> <a href = "ma_web5.html"> <font size = 4> 书籍续借 </font> </a> </li>
					</td>
					<td width = 100>
						<li> <a href = "ma_web5.html"> <font size = 4> 在线阅读 </font> </a> </li>
					</td>
					<td width = 100>
						<li> <a href = "../book/book_search.php"> <font size = 4> 书籍查询 </font> </a> </li>
					</td>
					<td width = 100>
						<li> <a href = "ma_web5.html"> <font size = 4> 新书订阅 </font> </a> </li>
					</td>
				</tr>
			</table>
		</div>
			
		<div style = "position:top; height: 80%;">
			<div style = "float: left; width: 10%; height: 100%; background-color:#cca4e3;">
				<div>
					<a href = "../library/litera.html"> 文学书屋 </a>
				</div>
				<br>
				<div>
					<a href = "math.html"> 数学殿堂 </a>
				</div>
				<br>
				<div>
					<a href = "astronomy.html"> 天文世界 </a>
				</div>
				<br>
				<div>
					<a href = "computerS.html"> 计算机科学 </a>
				</div>
			</div>
			
			<center>
			<div class = "body" style = "float: left; width: 75%; height: 100%;">
				<table cellpadding = 10>
					<tr>
						<td>
							<a href = "litera.html"> 
								<font size = "6"> 文学书屋 </font>
							</a>
						</td>
					</tr>
					<tr>
						<td>
							<a href = "math.html"> 数学殿堂 </a>
						</td>
					</tr>
					<tr>
						<td>
							<a href = "astronomy.html"> 天文世界 </a>
						</td>
					</tr>
					<tr>
						<td>
							<a href = "computerS.html"> 计算机科学 </a>
						</td>
					</tr>
					<tr>
						<td>
						
						</td>
					</tr>
				</table>
			</div>
			</center>
			
			<div style = "float: left; width: 15%; height: 100%; background-color:#b0a0e0;">
				<center>
				<div>
					<p> <strong> 您好，<font color = "blue"> <?php echo $row['name']; ?> </font> </strong> </p>
				</div>
				<div>
					<p> <?php echo $row['addr']; ?> 28摄氏度 晴 </p>
				</div>
				<div>
					<p> 您的工作邮箱：</p>
					<p> <?php echo $row['email']; ?> </p>
				</div>
				</center>
			</div>
		</div>
			
		<div align = "right">
			<a href = "../index.html"> 
				<font size = "4"> 返回 </font>
			</a> 
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