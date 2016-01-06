<?php
/*
	与数据库交互的函数库
*/

// 注册功能
function register($username, $email, $password)
{
	$conn = db_connect();
	
	$sql = "select * from users where username = '$username'";
	$result = $conn->query($sql);
	if (!result)
	{
		throw new Exception('could not execute query');
	}
	else if ($result->num_rows > 0)
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
		/*print_r($sql);
		exit;*/
		$result = $conn->query($sql);
		if (!result)
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
	
	$result = $conn->query($sql);
	if (!result)
	{
		throw new Exception('Could not log you in.');
	}
	else if ($result->num_rows > 0)
	{
		return true;
	}
	else
	{
		throw new Exception('Could not log you in.');
	}
}

// 检查用户是否是已登录
function check_valid_user()
{
	if (isset($_SESSION['valid_user']))
	{
		echo "Logged in as ".$_SESSION['valid_user']."<br>";
	}
	else
	{
		do_html_heading('Problem: ');
		
		echo "You are not logged in. <br>";
		
		do_html_url('login.php', 'Login');
		
		do_html_footer();
		
		exit;
	}
}


// 修改用户密码
function change_password($username, $old_password, $new_password)
{
	login($username, $old_password);
	
	$conn = db_connect();
	
	$password = md5($new_password.$username);
	$sql = "update users set password = '$password' where username = '$username'";
	
	$result = $conn->query($sql);
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
	$new_password = get_random_word(6, 16);
	
	if ($new_password == false)
	{
		throw new Exception('Could not generate new password.');
	}
	
	$rand_number = rand(0, 9999);
	$new_password .= $rand_number;
	
	$conn = db_connect();
	$password = md5($new_password.$username);
	$sql = "update users set password = '$password' where username = '$username'";
	$result = $conn->query($sql);
	
	if (!$result)
	{
		throw new Exception('Could not change password.');
	}
	else
	{
		return $new_password;
	}
}

// 获得随机单词
function get_random_word($min_len, $max_len)
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

// 将新密码，以电子邮件的形式发送给用户
function notify_password($username, $password)
{
	$conn = db_connect();
	$sql = "select email from users where username = '$username'";
	$result = $conn->query($sql);
	if (!result)
	{
		throw new Exception('Could not find email address!');
	}
	else if ($result->num_rows == 0)
	{
		throw new Exception('The user does not exist.');
	}
	else
	{
		$row = $result->fetch_object();
		$email = $row->email;
		$from = "From: suppport@phpbookmark \r\n";
		$mag = "Your PHPBookmark password has been changed to ".$password."\r\n".
			"Please change it next time you log in.\r\n";
			
		if (mail($email, 'PHPBookmark login information', $mag, $from))
		{
			return true;
		}
		else
		{
			throw new Exception('Could not send email.');
		}
	}
}

?>