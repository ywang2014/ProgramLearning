<?php
// 使用POP3邮件类，接收邮件
include "pop3.php";
// 新浪免费邮箱：接收服务器：pop3.sina.com.cn 发送服务器：smtp.sina.com.cn
$host = "pop3.sina.com.cn";
$user = "wood";
$pass = 12345678;
$rec = new POP3_mail($host, 110, 2);
if (! $rec->open())
{
	die($rec->err_str);
}
echo "open";
if (! $rec->login($user, $pass))
{
	die($rec->err_str);
}
echo "login";
if (! $rec->stat())
{
	die($rec->err_str);
}
echo("共有".$rec->message."封信件，共".$rec->size."字节大小<br>");
if ($rec->message > 0)
{
	if (! $rec->listmail())
	{
		die($rec->err_str);
	}
	echo "有以下信件：<br>";
	for ($i = 1; $i <= count($rec->mail_list); $i++)
	{
		echo("信件".$rec->mail_list[$i][num]."大小：".$rec->mail_list[$i][size]."<br>");
	}
	$rec->getmail(1);
	echo("邮件头的内容：<br>");
	for ($i = 0; $i < count($rec->head); $i++)
	{
		echo htmlspecialchars($rec->body[$i])."<br>\n";
	}
}
$rec->close();

?>