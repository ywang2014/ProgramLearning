<?
/*
	配置文件：
	
*/

$smtpserver = "smtp.sina.com";
$smtpport = 25;
$smtpuser = "ywangsh2014";
$smtppassword = "password";
$mailtype = "txt";


/***
$arr = explode('.', $smtpserver);
$email_from = $smtpuser.'@'.$arr[1].'.'.$arr[2];

$arr = explode('@', $email_from);
$smtpserver = 'smtp'.$arr[1];
$smtpuser = $arr;

	发邮件的服务器不能改变，使用用户的，则不知道其邮箱密码，无法发送
	方法：在发件人的地方，显示客户的邮件名即可！
	在数据库，读取客户的邮箱，然后设置email_from
	
*/

	
?>