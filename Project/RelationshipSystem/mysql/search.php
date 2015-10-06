<html>
	<head>
		<meta charset = "utf-8">
		<title> FriendsInformation </title>
	</head>
	
	<body>
		<center>
			<h1 style = "color: red"> Search Result </h1>
			<hr>
			<?php
			include "connection.php"
			
			$search_topic = $_POST['search_topic'];
			$search_keyword = $_POST['search_keyword']
			
			$query = "SELECT * FROM friends WHERE ".$search_topic." = ".$search_keyword;
			
			$result = mysql_query($query);
			if ($result == 0)
			{
				echo "Sorry, 数据库服务器查询是失败！";
				exit();
			}
			$num = mysql_num_rows($result);
			if ($num != 0)
			{
				echo "<p align = center> 对不起，这里没有任何相关记录！！</p>";
				echo "<a href = \"../index.html\"> 请重新输入关键字！</a>";

			}
			else
			{
				// 输出相关记录
			}

			mysql_close();
			?>		
	</body>
</html>