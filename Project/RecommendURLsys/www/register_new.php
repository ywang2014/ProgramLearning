<?php
/*
	验证新用户数据，并将其存入数据库
*/

require_once('bookmark_fns.php');

$email = trim($_POST['email']);
$username = trim($_POST['username']);
$password = $_POST['password'];		// 密码应该允许两端使用空格
$password2 = $_POST['password2'];

session_start();
/*print_r($_POST);
exit;*/

try
{
	if (!filled_out($_POST))
	{
		throw new Exception('You have not filled the form out correctly, please go back and try again.');
	}
	
	if (!valid_email($email))
	{
		throw new Exception('That is not a valid email address, please go back and try again.');
	}
	
	if ($password != $password2)
	{
		throw new Exception('The passwords you entered do not match, please go back and try again.');
	}
	
	if ((strlen($password) < 6 || (strlen($password) > 32)))
	{
		throw new Exception('Your password must be between 6 and 32 characters, please go back and try again.');
	}
	
	register($username, $email, $password);
	
	$_SESSION['valid_user'] = $username;
	
	do_html_header('Registration successful');
	
	echo "Your registration was successful. Go to the members page to start setting up your bookmarks!";
	
	do_html_url('member.php', 'Go to members pages');
	
	do_html_footer();
}
catch (Exception $e)
{
	do_html_header('Error');
	do_html_err($e->getMessage());
	do_html_footer();
	exit;
}

?>