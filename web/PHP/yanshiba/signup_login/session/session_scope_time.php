<?php
/*
	session生命周期
	
	session有效性的影响因素：
	1.客户端的cookie
	2.服务器端session文件
	
	php.ini里面，session_cookie_lifetime = 15 控制sessionid的cookie的生命周期，秒为单位
	此时：如果用户篡改cookie，自己设置cookie的有效期，服务器是不知道的
	
	严格设置session的有效时间，设置方法：
	$_SESSION['time'] = time() 登录时间
	检查session的开启时间！逻辑判断
	
*/

/*
	session的路径
	
	session_cookie_path = / 设置了session的cookie在根目录，因此session的cookie整站可见
*/

/*
	cookie只能存储数字、字符串
	session可以存储数字、字符串、数组、对象，不能存储资源型
	
	注意：如果session中存入了对象，则读取session的页面，必须有该对象的声明，否则类不完整。
*/

/*
	http协议：
	cookie是在头信息中，因此cookie之前不能有任何主体信息的输出
	
	如果有错误，没有输出，检查bom信息

*/
?>