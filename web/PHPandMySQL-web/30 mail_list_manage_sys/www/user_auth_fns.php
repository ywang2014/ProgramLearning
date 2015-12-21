<?php
/*
	user_auth_fns.php 
*/

// 检查用户是否是普通用户
function check_normal_user()
{
	// see if user is logged in and notify them if not 
	return isset($_SESSION['normal_user']);
}

function check_admin_user()
{
	// see if user is logged in and notify them if not 
	return isset($_SESSION['admin_user']);
}

function check_logged_in()
{
	// 直接判断，不使用函数调用，效率更高！
	return (isset($_SESSION['normal_user']) || isset($_SESSION['admin_user']));
}

// 检查用户登录函数
function login($email, $password)
{
	$conn = db_connect();
	if (!$conn)
	{
		return false;
	}
	
	$sql = "select admin from subscribers where email = '$email' and password = sha1('$password')";
	
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	if (mysql_num_rows($result) < 1)
	{
		return false;
	}
	
	$row = mysql_fetch_array($result);
	if ($row[0] == 1)
	{
		return 'admin';
	}
	else
	{
		return 'normal';
	}
}

// 获得用户的邮件地址
function get_email()
{
	if (isset($_SESSION['normal_user']))
	{
		return $_SESSION['normal_user'];
	}
	else if (isset($_SESSION['admin_user']))
	{
		return $_SESSION['admin_user'];
	}
	
	return false;
}

// 校验并更新用户密码
function change_password($email, $old_password, $new_password, $new_password_conf)
{
	if (login($email, $old_password))
	{
		if ($new_password == $new_password_conf)
		{
			if ($conn = db_connect())
			{
				$sql = "update subscribers set password = sha1('$new_password') where email = '$email'";
				
				$result = mysql_query($sql);
				return $result;
			}
			else
			{
				// access failed
				echo "<p> Database cannot be accessed now. </p>";
			}
		}
		else
		{
			echo "<p> Password is not the same in two times. </p>";
		}
	}
	else
	{
		echo "<p> The old_password is wrong. </p>";
	}
	return false;
}

?>