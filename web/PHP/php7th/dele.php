<html>
<!-- 
删除留言
	1. 留言太多，存储是问题，太旧的留言也没有存在的价值
	2. 有些留言内容是垃圾，需要删除
	3. 删除留言，属于管理员的权限，需要验证管理员身份
-->
	<head>
		<meta charset = "utf-8">
	</head>
</html>

<?php
$error = "";

$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
mysql_select_db($databasename);
if (isset($postid))
{
	$result_id = mysql_query("SELECT * FROM guest_book WHERE postid = ".$postid, $connect_id);
	if (result_id == false)
	{
		$error = "没有该记录";
	}
	else
	{
		$myarray = mysql_fetch_row($result_id);
	}
}
mysql_free_result($result_id);
mysql_close($connect_id);
if ($cmdOK)
{
	// 删除留言
	if ($deleormodi == "dele")
	{
		if ($password != $adminpassword)
		{
			$error = "密码错误！只有管理员有权限删除留言";
		}
		else
		{
			mysql_query("DELETE FROM guest_book WHERE postid = ".$postid, $connect_id);
			echo "window.alert('留言已被删除')";
			echo "document.location.href = 'guestbook.php' \n";
			echo "</script> \n";
			exit();
		}
	}
}

?>

<html>
	<link rel = "STYLESHEET" type = "text/css" href = "DEFAULT.CSS">
	<title> 删改留言 </title>
	<body>
	<table border = 0 cellspacing = 1 cellpadding = 4 width = "80%" align = "center" bgcolor = "#bbddff">
		<tr>
			<td align = "left" colspan = 4 height = 25>
				<?php
				if ($error != "")
				{
					echo "<img src = images/user.gif align = absmiddle> &nbsp; <b> 错误：</b>".$error;
				}
				?>
			</td>
		</tr>
		<form method = "post" action = "deleormodi.php" name = "frmGstBook">
			<input type = "hidden" name = "postid" value = <?php echo $postid ?>>
			<input type = "hidden" name = "deleormodi" value = <?php echo $deleormodi ?> >
			<tr>
				<td align = "right" width = "15%">
					<font color = "#000080"> 姓名：</font>
				</td>
				<td width = "17%">
					<input class = "smallInput" type = "text" name = "txtName" size = "30" value = <?php echo $myarray[0] ?>>
					<b> </b>
				</td>
			</tr>
			<tr>
				<td align = "right" width = "16%">
					<div align = "left">
					<font color = "#000080">
						密码
					</font>
					<b>
					<font color = "#000080"> : 
					</font>
					</b>
					</div>
				</td>
				<td width = "32%">
				<input class = "smallInput" type = "password" name = "password" size = 10>
				</td>
			</tr>
			<tr>
				<td width = "16%">
					<?php 
					$modi_checked = "";
					$dele_checked = "";
					if ($deleormodi == "modi")
					{
						$modi_checked = "checked";
					}
					else
					{
						$dele_checked = "checked";
					}
					?>
					<input type = "radio" name = "deleormodi" <?php echo $dele_checked ?> value = "dele">
					删除留言
				</td>
			</tr>
			<tr>
				<td align = "left" height = "35" width = "32%"> &nbsp; </td>
			</tr>
			<tr>
				<td align = "right" width = "15%">
					<font color = "#000080"> 留言: </font>
					<b>
					<font color = "#000080">
					</font>
					</b>
				</td>
				<td align = "left" width = "37%">
				&nbsp;
				</td>
				<td width = "16%"> </td>
				<td width = "32%"> </td>
			</tr>
			<tr>
				<td width = "15%"> </td>
				<td colspan = 3 align = "left">
					<p> <font color = "#000080">
						<textarea rows = 7 class = "smallArea" name = "txtContent" cols = 60 wrap = "virtual">
							<?php echo $myarray[5] ?>
						</textarea>
					</font>
					<p align = "left"> &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; 
				</td>
			</tr>
		</form>
	</table>
	</body>
</html>