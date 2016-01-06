<?php
/*
	servertime.php 代码
	
	利用date()函数调用获得服务器的当前时间，并以XML编码的字符串返回
*/

header("Content-Type: text/xml");

echo "<?xml version = \"1.0\" ?>
		<clock>
			<timestring> It is ".date("H:i:s")." on ".date('M d, Y').". </timestring>
		</clock> ";




?>