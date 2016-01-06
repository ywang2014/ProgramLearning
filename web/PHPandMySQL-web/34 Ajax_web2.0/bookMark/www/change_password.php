<?php
/*
	change_password_form.php 提供用户修改密码的表单
	change_password.php 负责处理表单，完成修改
*/
require_once('bookmark_fns.php');
session_start();

do_html_header('Changing password');

$old_password = $_POST['old_password'];
$new_password = $_POST['new_password'];
$new_password2 = $_POST['new_password2'];

try
{
	check_valid_user();
	if (!filled_out($_POST))
	{
		throw new Exception('You have not filled out the form completely. Please try again.');
	}
	else if ($new_password != $new_password2)
	{
		throw new Exception('Passwords entered were not the same. Try again.');
	}
	else if (strlen($new_password) > 32 || strlen($new_password) < 6)
	{
		throw new Exception('New password must be between 6 and 16 characters. Try again.');
	}
	
	change_password($_SESSION['valid_user'], $old_password, $new_password);
	
	echo "Password changed successfully.";
}
catch (Exception $e)
{
	echo $e->getMessage();
}

display_user_menu();
do_html_footer();

?>