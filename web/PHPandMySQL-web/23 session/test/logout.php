<?php
/*
	注销会话，退出登录
*/
session_start();

$old_user = $_SESSION['user'];
unset($_SESSION['user']);
session_destroy();

?>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8"/>
		<title> Logout </title>
	</head>
	<body>
		<h1> Log Out </h1>
		<?php
			if (!empty($old_user))
			{
				echo "Logged out<br>";
			}
			else
			{
				echo "You are not logged in <br>";
			}
		
		?>
		
		<a href = "check_auth.php"> Back to log in page </a>
	</body>
</html>