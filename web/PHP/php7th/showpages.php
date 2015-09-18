<?php

// 设置显示记录的页数

if (! isset($page))
{
	$inPage = 1;
}
else
{
	$inPage = $page;
}

$intRecordCount = 0;
$intPageCount = 0;

// 连接数据库
$connect_id = mysql_connect($dbserver, $dbusername, $dbpassword);
if ($connect_id == false)
{
	echo "连接到数据库失败";
	exit();
}

if (mysql_select_db($databasename, $connect_id))
{
	// 设置显示页面的标题，从表中读取记录
	$result_id = mysql_query("select * from guest_book order by postdate desc");
	$title = "查看留言";
	$color = "#000000";
	
	// 获取表中记录数，并保存在变量$intRecordCount中
	$intRecordCount = mysql_num_rows($result_id);
	if ($intRecordCount == 0)
	{
		// 转向留言页
		echo "<center> <b> 还没有留言，请您<a href = write.php> 留言 </a> </b> </center>";
	}
	else
	{
		// 计算显示留言页数，并显示定位页
		$intPageCount = ceil($intRecordCount / $intPagesize);
		$intStartNum = ($intPage - 1) * $intPageSize + 1;
		if ($intPage > $intPageCount)
		{
			$intPage = $intPageCount;
		}
		if ($intPage == $intPageCount)
		{
			$intEndNum = $intRecordCount - ($intPage - 1) * $intPagesize;
		}
		else
		{
			$intEndNum = $intPage * $intPagesize;
		}
	}
}
?>

<html>
<!-- 显示留言 -->
	<head>
		<meta charset = 'utf-8'>
		<title> <? echo "$title" ?> </title>
	</head>
	
	<body>
		<? require("pageheader.html"); ?>

		<?php
		for ($i = 0; $i < $intPagesize; $i++)
		{
			if ($myarray = mysql_fetch_row($result_id))
			{
				echo "<td align = right> 共有 $intRecordCount 条留言 </td>";
				echo " ";
				echo "<td align = aight> 这是第.$myarray[11].条留言 </td>";
				
				echo "<tr> <td colspan = 2> \n";
				echo "function_2($myarray[5])";		// 此函数在guestbook.php中
				echo "</td> </tr> \n";
				
				echo "<tr> <td align = left colspan = 2> \n";
				
				echo "<tr> <td> \n";
				echo $myarray[0];
				echo "<font color = $color> <br> 时间: $myarray[6]";
				echo $myarray[7];
				echo "</font> </td> </tr> \n";
			
				echo "<tr> <td colspan = 2> <hr size = 1> </td> </tr>";
			}
			else
			{
				break;
			}
		}
		mysql_free_result($result_id);
		}	// 书中代码错误
		else
		{
			echo("连接到数据库失败");
		}
		mysql_close($connect_id);
		?>
		
		<br>
			<!-- 建立表格 -->
			<table border = 0 cellspacing = 1 cellpedding = 4 width = "80%" align = center bgcolor = "#bbddff">
				<form method = "post" action = "write.php" name = "frmCstBook">
				<input type = "hidden" name = "cmd" value = "savepost">
				<tr> 
					<td colspan = 4>
						<?php
						if ($error != "")
						{
							echo "<img src = images/user.jpg align = absmiddle> $nbsp; <font color = red> <b> 错误：</b> </font>".$error;
						}
						?>
					</td>
				</tr>
				<tr>
					<td align = right width = "13%">
						<font color = "#000080"> 姓名：</font>
					</td>
					<td width = "32%"> 
						<b>
							<input class = "smallInput" type = "text" name = "txtName" size = 30>
						</b>
					</td>
				</tr>
				<tr>
					<td width = "32%">
						<b>
							<input class = "smallInput" type = "text" name = "txtFrom" size = 30>
						</b>
					</td>
					<td align = "right" width = "14%">
						<font color = "#000080">
						E-Mail:
						</font>
					</td>
					<td width = "41%">
						<b>
							<input class = "smallInput" type = "text" name = "txtEmail" size = 20 maxlength = 50>
						</b>
					</td>
				</tr>
				<tr>
					<td align = "right" width = "13%"> 
						<font color = "#000080">
						留言：
						</font>
						<b>
							<font color = "#000080">
							</font>
						</b>
					</td>
					<td align = "left" colspan = "3">
						<b>
							<font color = "#000080">
							</font>
						</b>
						<b> </b>
						<b>
							<input type = "checkbox" name = "ip" value = "hideip">
						</b>
						<b> </b>
					</td>
				</tr>
				
				<?php
				if (trim($myarray[8]) != "")
				{
					echo "<td> 回复时间：</td>";
					echo "<tr> <td colspan = 2>";
					echo "<ul> <font color = #397AFF> $myarray[9]: 回复 </font> <hr> function_1($myarray[8])";
					echo "</ul> </td> </tr>";
				}
				?>
				<tr>
					<td width = "13%"> </td>
					<td colspan = 3 align = left>
						<p> 
							<font color = "#000080">
								<textarea rows = 7 class = "smallArea" name = "txtContent" cols = 60 wrap = "virtual">
								</textarea>
							</font>
						</p>
					</td>
				</tr>
				<tr>
					<td width = "13%"> </td>
					<td colspan = 4 align = center>
						<input type = "submit" value = "提交" class = "buttonface">
					</td>
				</tr>
				</form>
			</table>
			
	</body>
</html>
