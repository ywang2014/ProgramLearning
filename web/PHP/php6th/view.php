<html>
<!-- 
	聊天室的显示，采用浏览器“拉”技术：
	在HTML文件头插入<meta>标记
	http-equiv: HTTP头部协议：	告诉浏览器网页属性
	content: 确定刷新时间间隔
	
-->
	<head>
		<meta charset = 'utf-8'>
		<meta http-equiv = "Refresh" content = "5; url = view.php? room = <?php echo $room; ?>">
	</head>
	
	<body bgcolor = RGB(201, 139, 194)>
		<?php
		switch($room)
		{
			case '1': 
				$room = "时政军事";
				$write_file = "1.txt";
				break;
			case '2': 
				$room = "红袖飘香";
				$write_file = "2.txt";
				break;
			case '3': 
				$room = "少男少女";
				$write_file = "3.txt";
				break;
			case '4': 
				$room = "时尚娱乐";
				$write_file = "4.txt";
				break;
			case '5': 
				$room = "科技创新";
				$write_file = "5.txt";
				break;
			case '6': 
				$room = "青青校园";
				$write_file = "6.txt";
				break;
			default:
				$write_file = "0.txt";
				break;
		}
		
		switch ($room)
		{
			case '时政军事': $write_file = "1.txt"; break;
			case '红袖飘香': $write_file = "2.txt"; break;
			case '少男少女': $write_file = "3.txt"; break;
			case '时尚娱乐': $write_file = "4.txt"; break;
			case '科技创新': $write_file = "5.txt"; break;
			case '青春校园': $write_file = "6.txt"; break;
			default: $write_file = "0.txt"; break;
		}
		
		$chat_length = 25;
		$lines = file($write_file);
		$a = count($lines);
		$u = $a - $chat_length;
		for ($i = $a; $i + 1 >= $u; $i--)
		{
			echo $lines[$i]."<br>";
		}
		switch ($room)
		{
			case '时政军事': $room = "1"; $write_file = "1.txt"; break;
			case '红袖飘香': $room = "2"; $write_file = "2.txt"; break;
			case '少男少女': $room = "3"; $write_file = "3.txt"; break;
			case '时尚娱乐': $room = "4"; $write_file = "4.txt"; break;
			case '科技创新': $room = "5"; $write_file = "5.txt"; break;
			case '青春校园': $room = "6"; $write_file = "6.txt"; break;
			default: $write_file = "0.txt"; break;
		}
		?>
		
	</body>
</html>