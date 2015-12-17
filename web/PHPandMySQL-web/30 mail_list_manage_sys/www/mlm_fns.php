<?php
/*
	mlm_fns.php 
*/
// 添加新用户或者修改数据库中的已有用户
function store_account($normal_user, $admin_user, $details)
{
	if (! filled_out($details))
	{
		echo "<p> All fields must be filled in. Try it again. </p>";
		return false;
	}
	else
	{
		if (subscriber_exists($details['email']))
		{
			// check logged in as the user they are trying to change
			if (get_email() == $details['email'])
			{
				$sql = "update subscribers set realname = '".$details['realname']."' mimetype = '".$details['mimetype']."' ".
						"where email = '".$details['email']."'";
				if ($conn = db_connect())
				{
					if (mysql_query($sql, $conn))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					echo "<p> Could not store changed. </p>";
					return false;
				}
			}
			else
			{
				// 未登录 get_mail()使用了 $_SESSION
				echo "<p> Sorry, that email address is already registered here. </p>".
					"<p> You will need to log in with that address to change its settings. </p>";
				return false;
			}
		}
		else
		{
			// new account
			$sql = "insert into subscribers values ('".$details['email']."', '".$details['realname']."', '".$details['mimetype'].
					"', sha1('".$details['new_password']."'), 0)";
			if ($conn = db_connect())
			{
				if (mysql_query($sql, $conn))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				echo "<p> Could not store new account now. </p>";
				return false;
			}
		}
	}
}

// 


?>