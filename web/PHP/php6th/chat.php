<html>
	<haed>
		<meta charset = 'utf-8'>
		<title> 聊天室 </title>
	</head>
	
	<body bgcolor = RGB(128, 142, 213) top align = 0>
		<?php
		switch($room)
		{
			case '1': 
				$room = "时政军事";
				break;
			case '2': 
				$room = "红袖飘香";
				break;
			case '3': 
				$room = "少男少女";
				break;
			case '4': 
				$room = "时尚娱乐";
				break;
			case '5': 
				$room = "科技创新";
				break;
			case '6': 
				$room = "青青校园";
				break;
			default:
				$write_file = "0.txt";
				break;
		}
		$name = str_replace("<", "&lt", $name);
		$name = str_replace(">", "&gt", $name);
		$name = stripslashes(trim($name));
		?>
		
		<table border = 0>
			<form action = "input.php" method = "post">
				<tr>
					<td>
						<input type = "hidden" name = "room" value = "<? echo $room; ?>"> 姓名:
						<font color = blue> <? echo urldecode($name); ?> </font>
						前景颜色: 
						<select name = "fcolor">
							<option value = "red"> 红色 </option>
							<option value = "purple"> 紫色 </option>
							<option value = "pink"> 粉色 </option>
							<option value = "gray"> 灰色 </option>
							<option value = "blue"> 蓝色 </option>
							<option value = "green"> 绿色 </option>
							<option value = "white"> 白色 </option>
						</select>
						对象:
						<select name = "to">
							<?php
							echo "<option select value = \"所有人\">所有人 </option>";
							?>
						</select>
						表情:
						<select name = "face">
							<option select value = "对 #"> 无 </option>
							<option value = "深深地爱着#多年，发誓非#不娶。含情脉脉地对#"> 爱恋 </option>
							<option value = "举着羽毛球拍，对着#高呼：欢迎欢迎，热烈欢迎，口中"> 欢迎 </option>
							<option value = "高喊：造反有理，革命无罪，还振振有词地"> 理直气壮 </option>
							<option value = "看到别人谈情说爱，感到一个人很难堪，于是"> 电灯泡 </option>
							<option value = "看见#就像看见一堆屎；厌恶地"> 憎恨 </option>
							<option value = "对着#大献殷情，高呼：拥立#为日月教主，一统江湖，讨好地"> 拍马屁 </option>
							<option value = "可怜地望着#，一副要哭的样子，"> 难过 </option>
							<option value = "双手抱拳，对#这位大师很眼熟啊，上去"> 招呼 </option>
							<option value = "跪在地上，对#说：以后我尊你为老大，可以饶了我吧，哆嗦着"> 求饶 </option>
						</select>
						<a href = "index.php" target = _parent> 退出 </a>
					</td>
				</tr>
				<tr>
					<td>
						<input type = "hidden" name = "name" value = "<? echo $name ?>">
						内容: <input type = "text" name = "message" size = 60>
						<input type = "submit" value = "发送">
						<input type = "checkbox" name = "whisper"> 
						<font color = red> 私聊 </font>
						<!-- </from> -->
					</td>
				</tr>
			</form>
		</table>
		<?php 
		$t = date("d日 H:i");	// 显示发言时间
		$talk = 100;	// 设置发言的最大长度
		$r = 25;	// 设置聊天室浏览器显示的最大句数
				
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
				
		$max_file_size = $r * ($talk + 15);
		$file_size = filesize($chat_file);
		if ($file_size > $max_file_size)
		{
			$lines = file($write_file);
			$tmp = count($lines);
			$u = $tmp - $r;
			for ($i = $tmp; $i >= $u; $i--)
			{
				$msg_old = $line[$i].$msg_old;
			}
			$deleted = unlink($write_file);
			$fp = fopen($write_file, "a+");
			$fw = fwrite($fp, $msg_old);
			fclose($fp);
		}
		$msg = str_replace("\n", "",$message);
		$msg = str_replace("<", "&lt", $msg);
		$msg = str_replace(">", "&gt", $msg);
		$msg = stripslashes($msg);
		if ($msg != "")
		{
			$fp = fopen($write_file, "a+");
			$face = str_replace("#", $to, $face);
			$fw = fwrite($fp, "\n <font color = $fcolor> <b>".substr($msg, 0, 94)."</b> </font> \n[".$t."]".$name.$face."说：");
					
			if (strlen($msg) > 40)
			{
				$fw = fwrite($fp, "\n <font size = +2> <B> 管理员对".$name."说：年轻人，废话怎么这么多！你还想在这儿混吗? </B> </font>");
			}
			fclose($fp);
					
			$userip = trim(getenv("REMOTE_ADDR"));
			$fp = fopen("back.txt", "a+");
			$fw = fwrite($fp, "\n $room"."里的".$name."[".$userip."]".date("Y/m/d, H:i:s").":".substr($msg, 0, 94));
			fclose($fp);
		}
		switch($room)
		{
			case '时政军事': $room = "1"; break;
			case '红袖飘香': $room = "2"; break;
			case '少男少女': $room = "3"; break;
			case '时尚娱乐': $room = "4"; break;
			case '科技创新': $room = "5"; break;
			case '青春校园': $room = "6"; break;
			default: $write_file = "0.txt"; break; 
		}
		?>
		
	</body>
	<!--  
		程序：
			设置了发言界面，并且处理发言窗口所发送的消息
			发送到服务器的发言经过整理后，以固定格式存储在文件中(文件与聊天室房间一一对应)
			存储聊天记录的文件，达到一定长度时，系统自动删除记录，并同时建立一个新的文件
	-->
</html>