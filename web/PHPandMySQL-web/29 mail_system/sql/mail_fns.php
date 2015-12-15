<?php
/*
	mail_fns.php
*/

// 检索用户所有的账户
function get_accounts($auth_user)
{
	$list = array();
	if ($conn = db_connect())
	{
		$sql = "select * from accounts where username = '$auth_user'";
		$result = mysql_query($sql, $conn);
		if ($result)
		{
			while ($settings = mysql_fetch_array($result))
			{
				array_push($list, $settings);
			}
		}
		else
		{
			return false;
		}
	}
	return $list;
}

// 保存新账户详细信息函数
function store_account_settings($auth_user, $settings)
{
	if (!filled_out($settings))
	{
		echo "<p> All fields must be filles in. Try again.</p>";
		return false;
	}
	else
	{
		$server = $settings['server'];
		$port = $settings['port'];
		$type = $settings['type'];
		$remoteuser = $settings['remoteuser'];
		$remotepassword = $settings['remotepassword'];
		$accountid = $settings['account'];
		
		if ($settings['account'] > 0)
		{
			$sql = "update accounts set server = '$server', port = '$port', type = '$type', remoteuser = '$remoteuser', remotepassword = '$remotepassword'".
					" where accountid = '$accountid' and username = '$auth_user'";
		}
		else
		{
			$sql = "insert into accounts values (NULL, '$auth_user', '$server', '$port', '$type', '$remoteuser', '$remotepassword')";
		}
		
		if ($conn = db_connect())
		{
			$result = mysql_query($sql, $conn);
			if ($result)
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
			echo "<p> Could not access the database. Try it latter, please. </p>";
			return false;
		}
	}
}

// 删除一个账户详细信息函数
function delete_account($auth_user, $accountid)
{
	// delete one of this user's accounts from the DB
	$sql = "delete from accounts where accountid = '$accountid' and username = '$auth_user'";
	
	if ($conn = db_connect())
	{
		$result = mysql_query($sql, $conn);
	}
	
	return $result;
}


// 计算某个用户注册了多少个邮箱账户函数
function number_of_accounts($auth_user)
{
	// get the number of accounts that belong to this user 
	$sql = "select count(*) from accounts where username = '$auth_user'";
	
	if ($conn = db_connect())
	{
		$result = mysql_query($sql, $conn);
		if ($result)
		{
			$row = mysql_fetch_array($result);
			return $row[0];
		}
	}
	return 0;
}


?>