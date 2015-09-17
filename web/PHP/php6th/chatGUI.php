<html>
<!-- 聊天室框架结果，图形界面 -->
	<head>
		<meta charset = 'utf-8'>
		<title> 聊天室 </title>
	</head>
	<?php
		echo "<frameset rows = \"78%, * \" cols = \" * \">";
		echo "<frame src = \"view.php? room = $room \" name = 'top'>";
		echo "<frame src = \"input.php? name = $name&room = $room \" name = 'down'>";
		echo "</frameset>";		// 实现一个快捷方式，复制/剪切粘贴最近的单词(一个单词或汉子)????
		echo "<noframes>";
		echo "<body bgcolor = \" #cccccc \">";
		echo "</body> </noframes>";
	?>
</html>