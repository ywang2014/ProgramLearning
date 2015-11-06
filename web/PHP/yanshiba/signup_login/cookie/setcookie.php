<?php
/*
	设置cookie
	在PHP中，服务器设置cookie，使用setcookie
	
	读取cookie
	服务器读取浏览器发送过去的cookie，不需要特殊方法
	php直接将cookie信息放进了超级全局数组$_COOKIE中，直接读取即可，类：$_POST
	
	cookie的作用域：
		同级目录和其子目录下生效，但是其上的或者平级目录不可见
		
	cookie不能跨域名生效
	
*/

/***********************************************************************
	设置setcookie()参数
	2,3,4,5个参数
		1.cookie 名
		2.cookie值
		3.有效时间
		4.有效路径
		5.有效域名
************************************************************************/

/* 2
	2个参数设置cookie，此时关闭浏览器，cookie就消失了
	如果只是刷新，则一直存在
*/
setcookie('value', 1);


/* 3
	3个参数设置cookie，第3个参数设置cookie存活时间，单位：s
	关闭浏览器，不影响该cookie，但是时间到了，自动消失，刷新可见cookie消失
*/
setcookie('username', 'wang', time()+60);

/* 4
	
	让cookie整个网站生效方法：
	1.根目录下生成cookie
	
	第4个参数，指定cookie生效路径
*/
setcookie('global_user', 'global', time()+3600, '/');

/* 5
	
	让cookie整个网站生效方法：
	
	第5个参数，指定cookie有效的域名，二级子域名
		setcookie('key', 'value', time()+15, '/', '.sina.com.cn');
		cookie可以在所有的*.sina.com.cn二级子域名下使用，如：'book.sina.com.cn'
		setcookie('key', 'value', time()+15, '/', 'www.sina.com.cn');
		cookie只能在www.sina.com.cn域名下使用
*/
setcookie('key', 'value', time()+3600, '/', '.sina.com');

?>