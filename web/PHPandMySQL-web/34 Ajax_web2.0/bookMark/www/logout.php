<?php
/*
	结束会话
*/
require_once('bookmark_fns.php');
session_start();

$old_user = isset($_SESSION['valid_user']) ? $_SESSION['valid_user'] : '' ;

unset($_SESSION['valid_user']);
$result_dest = session_destroy();

do_html_header('Logging Out');

if (!empty($old_user))
{
	if ($result_dest)
	{
		echo "Logged out. <br>";
		do_html_url('login.php', 'Login');
	}
	else
	{
		echo "Could not log you out. <br>";
	}
}
else
{
	echo "You were not logged in, and so have not been logged out. <br>";
	do_html_url('login.php', 'Login');
}

do_html_footer();

?>