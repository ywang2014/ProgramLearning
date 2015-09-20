<?php 

// 文件名: write.php
// 提交留言页面

function function_2($text)
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

// 解析留言
$error = "";
// 若用户点击“提交”，执行下面代码，将留言信息写入数据表中
if ($cmd == "savepost")
{
	if ($txtName == "" || $txtContent == "")
	{
		$error = "请输入您的信息！";
	}
	else
	{
		$txtName = function_2(ereg_replace("'", "''", $txtName));
		$txtFrom = ereg_replace("'", "''", $txtFrom);
		$txtEmail = ereg_replace("'", "''", $txtEmail);
		$txtContent = function_2(ereg_replace("'", "''", $txtContent));
		$date = date(Y."-".m."-".d." ".H.":".i.":".s);
	}
	$txtFrom = $txtFrom.$addr;
	if ($content == "")
	{
		exit();
	}
	
	// 对数据库进行操作
	$sql = "insert into guest_book(name, title, email, content) values('"$sql = $sql.."', ','')";
	$sql = $sql.$date."','".$txtName."','".$title."','".$txtEmail.",".$txtFrom.",".$txtHomePage."','";
	$sql = $sql.$txtContent."')";
	$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
	mysql_select_db($databasename);
	mysql_query($sql);
	mysql_close($connect_id);
	
	echo "<script language = javascript> \n";
	echo "document.location.href = 'guestbook.php'\n";
	echo "</script> \n";
	exit();
}

?>

<html>
<!-- 构造留言表单 -->
	<head>
		<meta charset = 'utf-8'>
		<title> 留言 </title>
	</head>
	
	<body>
		<table border = 0 cellspacing = 1 cellpadding = 4 width = "80%" align = center bgcolor = "#BBDDFF">
			<form method = "post" action = "write.php" name = "frmGstBook">
				<input type = "hidden" name = "cmd" value = "savepost">
				<tr>
					<td bgcolor = "#99ccff" height = 20 align = center colspan = 4>
						<?php require("pageheader.html"); ?>
					</td>
				</tr>
				<tr>
					<td colspan = 4>
						<?php
						if ($error != "")
						{
							echo "<img src = images/user.gif align = absmiddle> &nbsp; <font color = red> <b> 错误：</b> </font>".$error;
						}
						?>
					</td>
				</tr>
				<tr>
					<td align = "right" width = "13%">
						<font color = "#000080"> 姓名：</font>
					</td>
				</tr>
				<tr>
					<td width = "32%"> <b>
						<input class = "smallInput" type = "text" name = "txtFrom" size = 30>
						</b>
					</td>
					<td align = "right" width = "14%">
						<font color = "#000080">
						E-Mail: 
						</font>
					</td>
					<td width = "41%"> <b>
						<input class = "smallInput" type = "text" name = "txtEmail" size = 20 maxlength = 50>
						</b>
					</td>
				</tr>
				<tr>
					<td align = "right" width = "13%">
						<font color = "#000080">
						主题：
						</font>
						<b> 
							<font color = "#000080"> </font>
						</b>
					</td>
				</tr>
				<tr>
					<td width = "32%">
						<b>
						<input class = "smallInput" type = "text" name = "txtFrom" size = 30>
						</b>
					</td>
					<td align = "right" width = "13%">
						<font color = "#000080">
						留言：
						</font>
						<b>
							<font color = "#000080"> </font>
						</b>
					</td>
				</tr>
				<tr>
					<td width = "13%">
					</td>
					<td colspan = "3" align = "left">
						<p> <font color = "#000080">
						<textarea rows = 7 class = "smallArea" name = "txtContent" cols = 60 wrap = "virtual">
						</textarea>
						</font>
					</td>
				</tr>
				<tr>
					<td width = "13%"> </td>
					<td colspan = 4 align = "center">
						<input type = "submit" value = "提交" class = "buttonface" name = "cmdOK" onclick = "return(checkpassword())">
						&nbsp; &nbsp; &nbsp;
						<input type = "reset" value = "重填" name = "cmdReset" class = "buttonface">
					</td>
				</tr>
			</form>
		</table>
	</body>
</html>