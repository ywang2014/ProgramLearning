<?php
/*
	与数据库交互的函数库
*/

// 注册功能
function register($username, $email, $password)
{
	$conn = db_connect();
	
	$sql = "select * from users where username = '$username'";
	$result = mysql_query($sql);
	if (!$result)
	{
		throw new Exception('could not execute query');
	}
	else if (mysql_num_rows($result) > 0)
	{
		throw new Exception('That username is taken, go back and choose another one.');
	}
	else
	{
		$rtime = time();
		$password = md5($password.$username);
		/*$sql = "insert into users (username, password, email, rtime) values".
			" ('".$username."', '".$password"', '".$email."', ".$rtime.")";*/
		$sql = "insert into users (username, password, email, rtime) values ('$username', '$password', '$email', $rtime)";
		$result = mysql_query($sql);
		if (!$result)
		{
			throw new Exception('Could not register you in database, please try again later.');
		}
	}
	
	return true;
}


// 用户登录处理函数
function login($username, $password)
{
	$conn = db_connect();
	
	$password = md5($password.$username);
	$sql = "select * from users where username = '$username' and password = '$password'";
	// print_r($sql);
	$result = mysql_query($sql);
	if (!$result)
	{
		throw new Exception('Could not access the database.');
		return false;
	}
	else if (mysql_num_rows($result) > 0)
	{
		return true;
	}
	else
	{
		throw new Exception('Could not log you in.');
		return false;
	}
}

// 检查用户是否是已登录
function check_valid_user()
{
	if (! isset($_SESSION['valid_user']))
	{
		do_html_heading('Problem: ');
		
		echo "You are not logged in. <br>";
		
		do_html_url('login.php', 'Login');
		
		do_html_footer();
		
		exit;
	}
	else
	{
		echo "<p> Logged in as ".$_SESSION['valid_user']."</p>";
	}
}


// 修改用户密码
function change_password($username, $old_password, $new_password)
{
	try
	{
		login($username, $old_password);
	}
	catch (Exception $e)
	{
		/*
			登录失败，则说明密码错误(不考虑服务器、数据库异常，因为用户名验证正确)
			因此，修改提示语句，否则不和谐！不允许你登录，但是用户已经登录了！
		*/
		throw new Exception('Old password is wrong. Try again.');
	}
	
	$conn = db_connect();
	
	$password = md5($new_password.$username);
	$sql = "update users set password = '$password' where username = '$username'";
	
	$result = mysql_query($sql);
	if (!$result)
	{
		throw new Exception('Password could not be changed. Try it latter.');
	}
	else
	{
		return true;
	}
}

// 重置密码
function reset_password($username)
{
	$new_password = get_random_word();
	
	if ($new_password == false)
	{
		throw new Exception('Could not generate new password.');
	}
	
	$conn = db_connect();
	$password = md5($new_password.$username);
	$sql = "update users set password = '$password' where username = '$username'";
	$result = mysql_query($sql);
	
	if (!$result)
	{
		throw new Exception('Could not change password.');
	}
	else
	{
		return $new_password;
	}
}

// 获得随机单词，文件中随机读取
function get_random_word_file($min_len, $max_len)
{
	$word = '';
	
	$dictionary = '/usr/dict/words';
	$fp = @fopen($dictionary, 'r');
	if (!$fp)
	{
		return false;
	}
	$size = filesize($dictionary);
	
	$rand_location = rand(0, $size);
	fseek($fp, $rand_location);
	
	while ((strlen($word) < $min_len) || (strlen($word) > $max_len) || (strstr($word, "'")))
	{
		if (feof($fp))
		{
			fseek($fp, 0);
		}
		$word = fgets($fp, 80);
		$word = fgets($fp, 80);
	}
	
	$word = trim($word);
	return $word;
}

// 获得随机密码，随机函数
function get_random_word($len = 8)
{
	static $charset = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
	
	$word = substr(str_shuffle($charset), 0, $len);
	
	return $word;
}

// 将新密码，以电子邮件的形式发送给用户
function notify_password($username, $password)
{
	$conn = db_connect();
	$sql = "select email from users where username = '$username'";
	$result = mysql_query($sql);
	if (!$result)
	{
		throw new Exception('Could not find email address!');
	}
	else if (mysql_fetch_row($result) == 0)
	{
		throw new Exception('The user does not exist.');
	}
	else
	{
		$row = mysql_fetch_array($result);
		$email = $row['email'];
		$from = "From: suppport@phpbookmark \r\n";
		$msg = "Your PHPBookmark password has been changed to ".$password."\r\n".
			"Please change it next time you log in.\r\n";
			
		/*
			mail() [function.mail]: Failed to connect to mailserver at "localhost" port 25, verify your "SMTP" and "smtp_port" setting in php.ini or use ini_set() 
		*/
		/*
		if (mail($email, 'PHPBookmark login information', $mag, $from))
		{
			return true;
		}
		else
		{
			throw new Exception('Could not send email.');
		}
		*/
		print_r("<p>".$msg."</p>");
		return true;
	}
}

?>