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

// 连接到用户邮箱的函数
function open_mailbox($auth_user, $accountid)
{
	// select mailbox if there is only one 
	if (number_of_accounts($auth_user) == 1)
	{
		$accounts = get_account_list($auth_user);
		$_SESSION['selected_account'] = $accounts[0];
		$accountid = $accounts[0];
	}
	
	// connected to the pop3 or IMAP server the user has selected 
	$settings = get_account_settings($auth_user, $accountid);
	if (!sizeof($settings))
	{
		return 0;
	}
	
	$mailbox = '{'.$settings['server'];
	if ($settings['type'] == 'POP3')
	{
		$mailbox .= '/POP3';
	}
$mailbox .= ':'.$settings['port'].'}INBOX';
	
	// suppress warning, remember to check return value 
	@$imap = imap_open($mailbox, $settings['remoteuser'], $settings['remotepassword']);
	
	return $imap;
}

// 从邮箱中取得指定的消息
function retrieve_message($auth_user, $accountid, $messageid, $fullheaders)
{
	$message = array();
	
	if (!($auth_user && $messageid && $accountid))
	{
		return false;
	}
	$imap = open_mailbox($auth_user, $accountid);
	if (!$imap)
	{
		return false;
	}
	
	$header = imap_header($imap, $messageid);
	if (!$header)
	{
		return false;
	}
	$message['body'] = imap_body($imap, $messageid);
	if (!$message['body'])
	{
		$message['body'] = "[This message has no body]\n\n\n\n\n\n";
	}
	if ($fullheaders)
	{
		$message['fullheaders'] = imap_fetchheader($imap, $messageid);
	}
	else
	{
		$message['fullheaders'] = '';
	}
	
	$message['subject'] = $header->subject;
	$message['fromaddress'] = $header->fromaddress;
	$message['toaddress'] = $header->toaddress;
	$message['ccaddress'] = $header->ccaddress;
	$message['date'] = $header->date;
	
	// note we can get more detailed information by using from and to rather than fromaddress and toaddress, but these are easier 
	
	imap_close($imap);
	
	return $message;
}

// 从邮箱中删除一个指定消息的函数
function delete_message($auth_user, $accountid, $message_id)
{
	$imap = open_mailbox($auth_user, $accountid);
	if ($imap)
	{
		imap_delete($imap, $message_id);	// 删除邮件标记
		imap_expunge($imap);				// 真正删除消息
		imap_close($imap);
		
		return true;
	}
	
	return false;
}

// 发送用户键入的消息函数
function send_message($to, $cc, $subject, $message)
{
	// send one email via PHP
	
	if (!$conn = db_connect())
	{
		return false;
	}
	
	$username = $_SESSION['auth_user'];
	$sql = "select address from users where username = '$username'";
	
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	else if (mysql_num_rows($result) == 0)
	{
		return false;
	}
	else
	{
		$row = mysql_fetch_array($result);
		$other = "From: ".$row['address'];
		if (!empty($cc))
		{
			$other .= "\r\nCc: ".$cc;
		}
		
		if (mail($to, $subject, $message, $other))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


?>