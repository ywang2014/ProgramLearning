<?php
/*
	配置邮箱参数：
*/

require("smtp.php");

$smtpserver = "smtp.sina.com";
$smtpserverport = 25;
$smtpuseremail = "ywangsh2014@sina.com";
$smtpuser = "ywangsh2014";
$smtppass = "xxxxxx";

$smtpemailto = "1071512072@qq.com";

$mailsubject = "hello";
$mailbody = "PHP";
$mailtype = "txt";

$smtp = new smtp($smtpserver, $smtpserverport, true, $smtpuser, $smtppass);
$smtp->debug = TRUE;

$smtp->sendmail($smtpemailto, $smtpuseremail, $mailsubject, $mailbody, $mailtype);

?>