<?php
/*
	输出显示函数库
*/

// 显示账户详细信息函数
function display_account_setup($auth_user)
{
	// display empty new account form
	
	display_account_form($auth_user);
	$list = get_accounts($auth_user);
	$accounts = sizeof($list);
	
	// display each stored account 
	foreach ($list as $key => $account)
	{
		// 应该直接传入数组即可！
		display_account_form($auth_user, $account['accountid'], $account['server'], $account['remoteuser'], $account['remotepassword'], $account['type'], $account['port']);
	}
}

// 显示邮箱消息函数
function display_list($auth_user, $accountid)
{
	// show the list of messages in this mailbox
	global $table_width;
	
	if (!$accountid)
	{
		echo "<p style = \"padding-bottom:100px;\" > No mailbox selected. </p>";
	}
	else
	{
		$imap = open_mailbox($auth_user, $accountid);
		
		if ($imap)
		{
			echo "<table width = \"".$table_width."\" cellspacing = \"0\" cellpadding = \"6\" border = \"0\" >";
		
			$headers = imap_headers($imap);
			
			$messages = sizeof($headers);
			for ($i = 0; $i < $messages; $i++)
			{
				echo "<tr> <td bgcolor = \"";
				if ($i % 2)
				{
					echo "#fffff";
				}
				else 
				{
					echo "#ffffcc";
				}
				echo "\"> < a href = \"index.php?action=view_message&messageid=".($i + 1)."\">";
				echo $headers[$i];
				echo "</a> </td> </tr>\n";
			}
			echo "</table>";
		}
		else
		{
			$account = get_account_settings($auth_user, $acocuntid);
			echo "<p style = \"padding-bottom:100px; \"> Could not open mailbox ".$account['server'].". </p>";
		}
	}
}




?>