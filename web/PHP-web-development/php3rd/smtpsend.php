<?php
// 实现SMTP_mail类的文件名为：smtp.php
include "smtp.php";
$to = 'ywangsh2011@163.com';	//收件人的邮箱
$str = "Newsletter for".date('M Y', time());
$html_data = "<html> <head> <title> '. $str.' </title> </head> <body bgcolor = "#ffffff"> 你好！</body> </html>";

// 创建SMTP_mail类的对象
// 此文件包含了mime邮件类的实现
include "mime_mail.php";
$mime = new mime_mail("ywangsh2011@163.com", $to, $str);
// 调用mime_mail类方法
$mime->attach($html_data, "", HTML, BASE64);	// 添加HTML附件
$mime->gen_email();	// 生成邮件
// 显示邮件信息
echo($mime->email."<br>");
// 包含sendmail文件
include "SMTP_mail.php";
// 创建SMTP_mail类的对象
// 网易163免费邮箱：接收服务器：pop.163.com 发送服务器：smtp.163.com
$sendmail = new SMTP_mail("smtp.163.com", "hello", true);
// 发送邮件
$sendmail->send("ywangsh2011@163.com", "ywangsh2011@163.com", $str, $mime->email);

?>