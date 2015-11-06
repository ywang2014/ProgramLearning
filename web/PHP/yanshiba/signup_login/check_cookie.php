<?php
/*
	查看cookie
	超级全局数组 $_COOKIE
	这个cookie是客户端浏览器在电脑本地文件中找到的
	
	登录的时候，服务器给浏览器cookie，设置登录信息，比如登录时间，有效时间等
	验证的时候，浏览器给服务器cookie，验证信息
*/

print_r($_COOKIE);
echo "你是".$_COOKIE['username'];

?>