<?php
/*
	php触发基本http基本身份验证
*/

/*
	if we are using IIS, we need to set $_SERVER['PHP_AUTH_USER']
	and $_SERVER['PHP_AUTH_PW'].
*/
if ((substr($_SERVER['SERVER_SOFTWARE'], 0, 9) == 'Microsoft') && (!isset($_SERVER['PHP_AUTH_USER'])) &&
		(!isset($_SERVER['PHP_AUTH_PW'])) && (substr($_SERVER['HTTP_AUTHORIZATION'], 0, 6) == 'Basic'))
		{
			list($_SERVER['PHP_AUTH_USER'], $_SERVER['PHP_AUTH_PW']) = explode(':', base64_decode(
					substr($_SERVER['HTTP_AUTHORIZATION'], 6)));
		}
// replace this if statement with a database query or similar 
if (($_SERVER['PHP_AUTH_USER'] != 'user') || ($_SERVER['PHP_AUTH_PW'] != 'pass'))
{
	// invalid user
	header('WWW-Authentical: Basic realm="Realm-Name"');
	if (substr($_SERVER['SERVER_SOFTWARE'], 0, 9) == 'Microsoft')
	{
		header('Status: 401 Unauthorized');
	}
	else
	{
		header('HTTP/1.0 401 Unauthorized');
	}
	
	echo '<h1 align = "center"> 404 Not Found! </h1>';
}
else
{
	// valid user
	echo '<h1 align = "center"> Success, you can access! </h1>';
}

?>