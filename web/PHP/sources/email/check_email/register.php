<?php
header("Content-type: text/html; charset=utf-8"); 

include_once("connect.php");
include_once("../smtp.php");
include_once('../config.email.php');

//$email_from = "admin@oulin"; 无法发送
$arr = explode('.', $smtpserver);
$email_from = $smtpuser.'@'.$arr[1].'.'.$arr[2];

$username = stripslashes(trim($_POST['username']));
$result = mysql_query("select id from email_user where username = '$username'");
// print_r($result);
$num = mysql_num_rows($result);
if ($num > 0)
{
	echo "用户名已存在，请换其他的用户名";
	exit;
}

$email_to = trim($_POST['email']); 
$password = md5(trim($_POST['email']));
$regtime = time();

$token = md5($username.$password.$regtime);	// 创建激活码
$token_exptime = time() + 24*60*60;

$sql = "insert into email_user(username, password, email, token, token_exptime, regtime)".
		" values('$username', '$password', '$email_to', '$token', $token_exptime, $regtime)";
//print_r($sql);
mysql_query($sql) or die("录入失败!");

$mailtype = "HTML";

$subject = "Active email";
$message = "亲爱的".$username."：<br>感谢您注册我们网站新用户！请点击下面的链接，激活您的账号。<br>".
	"<a href = 'http://127.0.0.1/127.0.0.100/file/email/check_email/active.php?verify=".$token."' target='_blank'>"
	."http://www.oulin.com/register/active.php?verify=".$token."</a> <br>".
	"如果以上链接无法点击，请将它复制到您的浏览器地址栏中，直接访问，本链接24小时有效。";
	
$smtp = new smtp($smtpserver, $smtpport, true, $smtpuser, $smtppassword);
//$smtp->debug = TRUE;
$smtp->sendmail($email_to, $email_from, $subject, $message, $mailtype);

$msg = "恭喜您，注册成功！<br> 请登录到您的邮箱，及时激活您的账号！24小时有效！<br>".$email_to;

echo $msg;

?>