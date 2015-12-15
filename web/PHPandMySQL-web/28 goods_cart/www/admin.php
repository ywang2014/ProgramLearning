<?php
/*
	验证管理员身份，并允许管理员访问管理功能
*/

require_once('book_sc_fns.php');
session_start();

if (($_POST['username']) && ($_POST['password']))
{
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	if (login($username, $password))
	{
		$_SESSION['admin_user'] = $suername;
	}
	else
	{
		do_html_header('Problem:');
		echo "<p> You could not be logged in.<br> You must be logged in to view this page. </p>";
		
		do_html_url('login.php', 'Login');
		
		do_html_footer();
		
		exit;
	}
}

do_html_header('Administration');
if (check_admin_user())
{
	display_admin_menu();
}
else
{
	echo "<p> You are not authorized to enter the administration area. </p>";
}

do_html_footer();

?>