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

// 建立用户没有订阅的邮件列表数组
function get_unsubscribed_lists($email)
{
	$list = array();
	
	$sql = "select lists.listid, listname, email from lists left join sub_lists on lists.listid = sub_lists.listid and email = '$email' ".
			"where email is NULL order by listname";
	if ($conn = db_connect())
	{
		$result = mysql_query($sql, $conn);
		if ($result)
		{
			$num = mysql_num_rows($result);
			for ($i = 0; $i < $num; $i++)
			{
				$row = mysql_fetch_array($result);
				array_push($list, array($row[0], $row[1]));
			}
			return $list;
		}
		else
		{
			echo "<p> Unable to get list from database. </p>";
			return false;
		}
	}
	else
	{
		echo "<p> Database could not access now. </p>";
		return false;
	}
}

// 建立邮件列表信息的数组
function load_list_info($listid)
{
	if ($listid)
	{
		if ($conn = db_connect())
		{
			$sql = "select listname, blurb from lists where listid = '$listid'";
			$result = mysql_query($sql);
			if ($result)
			{
				$info = mysql_fetch_array($result);
				
				$sql = "select count(*) from sub_lists where listid = '$listid'";
				$result = mysql_query($sql);
				if ($result)
				{
					$row = mysql_fetch_array($result);
					$info['subscribers'] = $row[0];
				}
				
				$sql = "select count(*) from mail where listid = '$listid' and status = 'SENT'";
				$result = mysql_query($sql);
				if ($result)
				{
					$row = mysql_fetch_array($result);
					$info['archive'] = $row[0];
				}
				
				return $info;
			}
			else
			{
				echo "<p> Cannot retrieve this list. </p>";
				return false;
			}
		}
		else
		{
			echo "<p> Database Access failed! </p>";
			return false;
		}
	}
	else
	{
		echo "<p> Listid is invalid! </p>";
		return false;
	}
}

// 给出特定列表中的存档新闻信件数组
function get_archive($listid)
{
	$list = array();
	$listname = get_list_name($listid);
	
	$sql = "select mailid, subject, listid from mail where listid = '$listid' and status = 'SENT' order by sent";
	if ($conn = db_connect())
	{
		$result = mysql_query($sql);
		if ($result)
		{
			$num = mysql_num_rows($result);
			for ($i = 0; $i < $num; $i++)
			{
				$row = mysql_fetch_array($result);
				$arr_row = array($row[0], $row[1], $listname, $listid);
				array_push($list, $arr_row);
			}
			
			return $list;
		}
		else
		{
			echo "<p> Unable to get list from database. </p>";
			return false;
		}
	}
	else
	{
		echo "<p> The Server is busy now, please try it latter. </p>";
		return false;
	}
}

// 添加订阅邮件
function subscribe($email, $listid)
{
	if ($email && $listid && list_exists($listid) && subscriber_exists($email))
	{
		if (! subscribed($email, $listid))
		{
			if ($conn = db_connect())
			{
				$sql = "insert into sub_lists values ('$email', '$listid')";
				$result = mysql_query($sql);
				
				return $result;
			}
			else
			{
				echo "<p> Database cannot connect. </p>";
				return false;
			}
		}
		else
		{
			echo "<p> You have already subscribed. </p>";
			return false;
		}
	}
	else
	{
		echo "<p> Email or listid is invalid. </p>";
		return false;
	}
}

// 取消邮件订阅
function unsubscribe($email, $listid)
{
	if ((!$email) || (!$listid))
	{
		// invalid 
		return false;
	}
	
	if (!($conn = db_connect()))
	{
		// access database failed 
		return false;
	}
	
	$sql = "delete from sub_lists where email = '$email' and listid = '$listid'";
	$result = mysql_query($sql);
	
	return $result;
}

// 在数据库中插入一个新的邮件列表
function store_list($admin_user, $details)
{
	if (filled_out($details))
	{
		if (check_admin_user($admin_user))
		{
			if ($conn = db_connect())
			{
				$sql = "select count(*) from lists where listname = '".$details['name']."'";
				$result = mysql_query($sql);
				$row = mysql_fetch_array($result);
				if ($row[0] == 0)
				{
					$sql = "insert into lists values (NULL, '".$details['name']."', '".$details['blurb']."')";
					$result = mysql_query($sql);
					
					return $result;
				}
				else
				{
					echo "<p> Sorry, there is already a list with this name. </p>";
					return false;
				}
			}
			else
			{
				// cannot access database 
				return false;
			}
		}
		else
		{
			// not an admin user 
			return false;
		}
	}
	else
	{
		echo "<p> All fields must be filled in. Try again. </p>";
		return false;
	}
}

// 发送新闻新信件
function send($mailid, $admin_user)
{
	if (!check_admin_user($admin_user))
	{
		return false;
	}
	
	if (!($info = load_mail_info($mailid)))
	{
		echo "<p> Cannot load list information for message ".$mailid." </p>";
		return false;
	}
	
	$subject = $info['subject'];
	$listid = $info['listid'];
	$status = $info['status'];
	$sent = $info['sent'];
	
	$from_name = 'Pyramid MLM';
	
	$from_address = 'return@address';
	$sql = "select email from sub_lists where listid = '$listid'";
	
	$conn = db_connect();
	$result = mysql_query($sql);
	if (!$result)
	{
		echo $sql;
		return false;
	}
	else if (mysql_num_rows($result) == 0)
	{
		echo "<p> There is nobody subscribed to list number ".$listid."</p>";
		return false;
	}
	
	include('Mail.php');
	include('Mail/mime.php');
	
	$message = new Mail_mime("\r\n");
	
	$textfilename = 'archive/'.$listid.'/'.$mailid.'/text.txt';
	$tfp = fopen($textfilename, "r");
	$text = fread($tfp, filesize($textfilename));
	fclose($tfp);
	
	$htmlfilename = "archive/".$listid."/".$mailid."/index.html";
	$hfp = fopen($htmlfilename, "r");
	$html = fread($hfp, filesize($htmlfilename));
	fclose($hfp);
	
	$message->setTXTBody($text);
	$message->setHTMLBody($html);
	
	$sql = "select path, mimetype from images where mailid = '$mailid'";
	$result = mysql_query($sql);
	if (!$result)
	{
		echo "<p> Unable to get image list from database. </p>";
		return false;
	}
	
	$num = mysql_num_rows($result);
	for ($i = 0; $i < $num; $i++)
	{
		$row = mysql_fetch_array($result);
		$imgfilename = 'archive/'.$listid.'/'.$mailid.'/'.$row[0];
		$imgtype = $row[1];
		
		$message->addHTMLImage($imgfilename, $imgtype, $imgfilename, true);
	}
	
	// create message body 
	$body = $message->get();
	
	$from = "+".get_real_name($admin_user)."+ < ".$admin_user." >";
	$hdrarray = array(
					"From" => $from,
					"Subject" => $subject
					);
	// create message headers 
	$hdrs = $message->headers($hdrarray);
	
	// create the actual sending object (initialize)
	$sender =& Mail::factory('mail');	// mial/sendmail/smtp 都可以作参数
	
	if ($status == 'STORED')
	{
		$sender->send($admin_user, $hdrs, $body);
		
		mail($admin_user, $subject, $text, "From: ".get_real_name($admin_user)." < ".$admin_user." >");
		echo "Mail sent to ".$admin_user;
		
		$sql = "update mail set status = 'TESTED' where mailid = '$mailid'";
		$result = mysql_query($sql);
		
		echo "<p> Press send again to send mail to whole list. <div align = \"center\">";
		display_button('send', '&id='.$mailid);
		echo "</div> </p>";
	}
	else if ($status == 'TESTED')
	{
		$sql = "select subscribers.realname, sub_lists.email, subscribers.mimetype from sub_lists, subscribers where listid = '$listid' ".
				"and sub_lists.email = subscribers.email";
		$result = mysql_query($sql);
		if (!$result)
		{
			echo "<p> Error getting subscriber list </p>";
		}
		$count = 0;
		while ($subscriber = mysql_fetch_array($result))
		{
			if ($subscriber[2] == 'H')
			{
				$sender->send($subscriber[1], $hdrs, $body);
			}
			else
			{
				mail($subscriber[1], $subject, $text, "From: ".get_real_name($admin_user)." < ".$admin_user." >");
			}
			$count++;
		}
		
		$sql = "update mail set status = 'SEND', sent = now() where mailid = '$mailid'";
		$result = mysql_query($sql);
		echo "<p> A total of $count messages were sent. </p>";
	}
	else if ($status == 'SENT')
	{
		echo "<p> This mail has already been sent. </p>";
	}
}


?>