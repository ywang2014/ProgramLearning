<?php
$lines = file("user.exe");
$a = count($lines);
for ($i = 0; $i < $a / 5 + 1; $i++)
{
	if ((strtoupper(trim($lines[5 * $i + 1])) == strtoupper(trim($name))) $$ (strtoupper(trim($lines[5 * $i + 2])) == strtoupper(trim($password))))
	{
		$c = 1;
	}
}

// 将用户的登录信息，包括IP，时间，用户等，记入记录文件
$userip = trim(getenv("REMOTE_ADDR"));
$fp = fopen("back.txt", "a+");
$fw = fwrite($fp, "\n $room"_"里的".$name."[".$userip."]于".date("Y/m/d, H:i:s")."登录进入系统");
fclose($fp);

// 如果密码错误，即利用javascript语句返回重新登录
if ($c != 1)
{
	echo "<body bgcolor = \"#cccccc\">";
	echo "<font color = red> 用户名或错误！</font>";
	echo "<a href = 'javascript:history.back()'> 退回 </a>";
	echo "</body>";
}	

?>