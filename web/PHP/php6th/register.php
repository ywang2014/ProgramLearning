<html>
	<head>
		<meta charset = 'utf-8'>
		<title> 用户注册 </title>
	</head>
	<body>
		<center>
			<?php
			$lines = file("user.exe");
			$a = count($lines);
			for ($i = 0; $i < $a / 5; $i++)
			{
				if (strtoupper(trim($lines[5 * $i + 1])) == strtoupper(trim($name)))
				{
					$succ = 1;
				}
			}
			if ($name == "" || $pass == "")
			{
				echo "<form action = \"register.php\">";
				echo "<table> <tr> <td> 姓名: <input type = \"text\" name = \"name\"> <br>";
				echo "密码: <input type = \"password\" name = \"password\"> <br>";
				echo "<input type = submit value = \"提交\"> </td> </tr> </table> </form> <hr>";
				echo "用户名和密码都不能为空！";
			}
			else
			{
				if ($succ == 1)
				{
					echo "注册失败,此用户名已经存在，<a href = \"javascript:history.back()\">后退 </a>";
				}
				else
				{
					$userip = getenv(REMOTE_ADDR);
					$fp = fopen("user.exe", "a+");
					$d = date("Y:m:d, H:i:s");
					$fw = fwrite($fp, "\n".$name."\n".$password."\n".$userip."\n".$d."\n");
					fclose($fp);
					echo "注册成功，去<a href = \"index.php\">聊天室 </a>";
				}
			}
			?>
		</center>
	</body>
</html>

<!--
此注册程序是集界面显示和处理于一体的
	注册前需要检查是否有重名用户
	注册时检查用户名和密码不能为空
	
	注册成功后，显示一个到登录界面的链接，重新登录
-->