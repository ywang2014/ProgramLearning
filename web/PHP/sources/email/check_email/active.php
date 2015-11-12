<?php
/*
	激活邮件处理
*/
header("Content-type: text/html; charset=utf-8"); 

include_once('connect.php');

$verify = stripslashes(trim($_GET['verify']));
$nowtime = time();

$sql = "select id, token_exptime from email_user where status = 0 and token = '$verify'";
$result = mysql_query($sql);
$row = mysql_fetch_array($result);
if ($row)
{
	if ($nowtime > $row['token_exptime'])
	{
		$msg = '您的激活有效期已过，请您再次注册，重新发送激活邮件。';
	}
	else
	{
		mysql_query('update email_user set status = 1 where id = '.$row['id']);
		if (mysql_affected_rows($conn) != 1)
		{
			die(0);
		}
		else
		{
			$msg = '激活成功！';
		}
	}
}
else
{
	$msg = 'error';
}

echo $msg;

?>