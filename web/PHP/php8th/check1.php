<html>
	<head>
		<meta charset = "utf-8">
	</head>
	<!-- check1.php
		批改主观题！
		人工判卷！
	-->
	<body>
		<form>
			<center>
			<?php
			echo "该考生填写的答案是: <br> \n";
			echo "第二题 <br> \n";
			for ($i = 1; $i <= 3; $i++)
			{
				// $n2_q_num 第二题的题目数，可以文件读取
				echo "第$i题：<br> \n";
				echo "<p> $name </p> <br>";
			
				// 输出考生答案
				echo "评分<br>";
				echo "<input type = \"text\" size = 10 name = $name> <br> \n";
			}
			?>
			</center>
		</form>
	</body>
</html>

