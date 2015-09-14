<?PHP
// diaocha.php
?>

<html>
	<meta charset = "utf-8">
	<body>
		<center>
			<?php
			include "common.php";
			mysql_connect($hostname, $username, $password) or die("Unable to connect database");
			mysql_select_db("$dbname") or die("Unable to select database");
			
			print "您好：$name <br>";	// print 和 echo命令相似
			print("谢谢您的参与! <br><br>");
			
			// 把信息插入到表中
			// 因为有使用mysql_select_db函数选取了数据库，所以可以不用输入数据库名
			$query = "INSERT INTO $userstable(name, sex, age, place)
					 VALUES(, '{$name}', '{$sex}', $age, '$place')";
			$result = mysql_query($query);
			if (! $result)
			{
				echo "很遗憾，您的表格无法保存。";
			}
			else
			{
				echo "您的表格已经保存到数据库。";
			}
			
			mysql_close();
			?>
			<br> <br> <br> <br>
			<a href = "query.php"> 你想查看调查结果吗？</a>
	</body>
</html>