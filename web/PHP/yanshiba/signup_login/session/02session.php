<?php
/*
	session工作原理：
		服务器将关键信息保存在自己的系统里面，生成一个标签传给浏览器，设置cookie
		因此，用户看见的内容，只是服务器给的标签，虽然也可以修改，但是安全多了！
		用户需要将标签凭证发送给服务器，服务器读取系统中该标签里面的内容，返回给浏览器
		即完成了cookie/session的通信
		
		sessionId 作为唯一标签，用于通信，更加安全！
*/

session_start();	// 开启session

$_SEESION['user'] = 'zhang3';

echo "session start";

/*
	session 自动生成设置cookie，将标签发送给浏览器
	浏览器才能通过这个cookie中的标签，去请求服务器，服务器读取标签里面实际放的内容，再返回给浏览器
	
	session在服务器端
	cookie在浏览器端
	
	sessionid 比较凌乱，很难猜出别人的值，不过可以随意写！
	
	如果cookie泄露了，相当于别人知道你的sessionid了，只需要关闭浏览器，重启即可，此时就会产生新的cookie值。
*/

?>