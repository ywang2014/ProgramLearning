<?php
// 文件名：reply.php
function function_1($text)
{
	// 对字符串进行处理
	$text = ereg_replace("C_J", "<", $text);
	$text = ereg_replace("C_I", ">", $text);
	
	return $text;
}

function_2($text)
{
	$text = htmlspecialchars($text);
	// 对$text中的字符串进行解析
	$text = preg_replace("/ \ \t/is", "", $text);
	$text = preg_replace("/ \[h1\](.+?)\[\ /h1\]/is", "<h1> \ \1</h1>", $text);
	$text = preg_replace("/ \[h2\](.+?)\[\ /h2\]/is", "<h2> \ \1</h2>", $text);
	$text = preg_replace("/ \[h3\](.+?)\[\ /h3\]/is", "<h3> \ \1</h3>", $text);
	$text = preg_replace("/ \[h4\](.+?)\[\ /h4\]/is", "<h4> \ \1</h4>", $text);
	$text = preg_replace("/ \[h5\](.+?)\[\ /h5\]/is", "<h5> \ \1</h5>", $text);
	$text = preg_replace("/ \[h6\](.+?)\[\ /h6\]/is", "<h6> \ \1</h6>", $text);
	$text = preg_replace("/ \[url\](.+?)\[\ /url\]/is", "<a href = \ \1> \ \1</a>", $text);
	$text = preg_replace("/ \[url = (.+?)\](.*)\[\ /url\]/is", "<a href = \ \1> \ \2</a>", $text);
	$text = preg_replace("/ \[img\](.+?)\[\ /img\]/is", "<img src = \ \1>", $text);
	$text = preg_replace("/ \[b\](.+?)\[\ /b\]/is", "<b> \ \1 </b>", $text);
	$text = preg_replace("/ \[email\](.+?)\[\ /email\]/is", "<a href = \ \1> \ \1 </a>", $text);
	$text = preg_replace("/ \[i\](.+?)\[\ /i\]/is", "<i> \ \1 </i>", $text);
	
	return $text;
}

// 检查管理员是否已经登录
if (! isset($password))
{
	exit()
}
else if ($password != "password")
{
	exit();
}

if ($cmd == "reply")
{
	$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
	mysql_select_db($databasename);
	$replyname = ereg_replace("'", "''", $replyname);
	$txtReply = ereg_replace("'", "''", $txtReply);
	$date = date(Y."-".m."-".d." ".H.":".i.":".s);
	$ip = $REMOTE_ADDR;
	$result_id = mysql_query("select *from guest_book where postid = ".$postid, $connect_id);
	$myarray = mysql_fetch_row($result_id);
	
	if ($myarray[8] != "")
	{
		$txtReply = $myarray[8]."C_J br C_I C_J font color = #397AFFC".$replyname.":回复 C_J /font C_I C_J br C_I".$txtReply;
		$replyname = $myarray[9];
	}
	$txtReply = function_2($txtReply);
	$txtReply = $txtReply."C_J br C_I 时间:".$date."'$sql = '"."'update guest_book set replyname = '".$replyname."',reply = '".$txtReply."'where postid = '".$postid;
	
	$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
	mysql_select_db($databasename);
	mysql_query($sql);
	mysql_close($connect_id);
	
	echo "<script language = javascript> \n";
	echo "window.alert('回复成功！');";
	echo "document.location.href = 'guest_book.php' \n";
	echo "</script> \n"
	exit()
}
$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
mysql_select_db($databasename);
if (isset($postid))
{
	$result_id = mysql_query("SELECT * FROM guest_book WHERE postid = ".$postid, $connect_id);
	if ($result_id == false)
	{
		$error = "没有该记录！";
	}
	else
	{
		$myarray = mysql_fetch_row($result_id);
	}
}
mysql_free_result($result_id);
mysql_close($connect_id);
?>

<html>
	<head>
		<meta charset = 'utf-8'>
		<title> 回复留言 </title>
	</head>
	<body>
		<table border = 0 cellspacing = 1 cellpadding = 4 width = "80%" align = "center" bgcolor = "#bbddff">
		<tr>
			<td bgcolor = "#99ccff" height = 20 align = "center" colspan = 3>
				回复留言
			</td>
		</tr>
		<form method = "post" action = "reply.php" name = "frmGstBook">
			<input type = "hidden" name = "postid" value = <?php echo $postid?> >
			<input type = "hidden" name = "cmd" value = "reply">
			<tr>
				<td colspan = 3>
					<?php 
					if ($error != "")
					{
						echo "<b>错误：</b>".$error;
					}
					?>
				</td>
			</tr>
			<tr>
				<td>
				<font color = "000080">
					<?php 
					echo "<td align = right> 第 ".$myarray[11]." 条留言</td>";
					echo "<tr> <td colspan = 2> \n";
					echo function_2($myarray[5]);
					echo "</td> </tr> \n";
					echo "<tr> <td align = left colspan = 2> \n";
					if (trim($myarray[3]) != "")
					{
						echo "E-mail: <a href = mailto:".$myarray[3]."> border = 0 align = absmiddle> </a> &nbsp";
					}
					echo "<tr> <td> \n";
					echo "留言人姓名：";
					echo $myarray[0];
					echo "<font color = $color> <br>时间：$myarray[6]";
					echo "</font> </td> </tr> \n";
					
					if (trim($myarray[8] != ""))
					{
						echo "<tr> <td colspan = 2>";
						echo "<font color = red> $myarray[9] 回复：</font> <br>".function_1($myarray[8]);
						echo "</td> </tr>";
					}
					echo "<tr> <td colspan = 2> <hr size = 1> </td> </tr>";
					?>
				</font>
				</td>
			</tr>
			<tr>
				<td colspan = 3 align = "left" > 回复留言：</td>
			</tr>
			<tr>
				<td colspan = 3 align = "left">
					<p>
					<font color = "#000080">
						<textarea rows = 7 class = "smallArea" name = "txtReply" cols = 60 wrap = "virtual">
							<?php echo $myarray ?>
						</textArea>
					</font>
				</td>
			</tr>
			<tr>
				<td colspan = 3 align = center>
					<input type = "submit" value = "提交" class = "buttonface" name = "cmdOK">
					&nbsp;&nbsp;&nbsp;
					<input type = "reset" value = "重填" name = "cmdReset" class = "buttonface">
				</td>
			</tr>
		</form>
		</table>
	</body>
	<!--
		留言回复，实际上就是发表留言的重复
		但是在数据库中的位置不同
		注意SQL不同
	-->
</html>


