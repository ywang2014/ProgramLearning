<?php
/*
	forgot_form.php 忘记密码
	forgot_password.php 帮助用户重置密码
*/
require_once('bookmark_fns.php');
do_html_header('Resetting password');

$username = trim($_POST['username']);

try
{
	$password = reset_password($username);
	notity_password($username, $password);
	echo 'Your new password has been emailed to you. <br>';
}
catch (Exception $e)
{
	echo "Your password could not be reset. Please try again later.";
}

do_html_url('login.php', 'Login');
do_html_footer();


?>