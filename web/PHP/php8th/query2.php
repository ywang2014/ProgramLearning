<?php

// query2.php

/*

定义和用法

mysql_pconnect() 函数打开一个到 MySQL 服务器的持久连接。

mysql_pconnect() 和 mysql_connect() 非常相似，但有两个主要区别：

    1.当连接的时候本函数将先尝试寻找一个在同一个主机上用同样的用户名和密码已经打开的（持久）连接，如果找到，则返回此连接标识而不打开新连接。
    2.当脚本执行完毕后到 SQL 服务器的连接不会被关闭，此连接将保持打开以备以后使用（mysql_close() 不会关闭由 mysql_pconnect() 建立的连接）
*/

// 连接数据库
$link = mysql_pconnect($localhost, $username, $password);
if ($link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库连接错误！')";
	echo "</script>";
	exit();
}

// 激活数据库
if (mysql_select_db(exam, $link) == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库exam激活失败！')";
	echo "</script>";
	exit();
}

function make_query()
{
	if (isset($mark))
	{
		$query = "mark = $mark";
	}
	else
	{
		$query = "mark >= 0";
	}
	
	if (isset($name))
	{
		$query .= " AND name = $name";
	}
	
	if (isset($password))
	{
		$query .= " AND password = $password";
	}
	
	if (isset($sex))
	{
		$query .= " ANd sex = $sex";
	}
	
	if (isset($address))
	{
		$query .= " AND address = $address";
	}
	
	if (isset($tele))
	{
		$query .= " AND tele = $tele";
	}
	
	$query .= ";";
	
	return $query;
}
// 根据不同的情况，决定查询的字符串

$query_right = make_query();
$query_left = "SELECT COUNT FROM exam WHERE ";
$query = $query_left.$query_right;
$count_link = mysql_query($query, $linnk);
if ($count_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}
$count = mysql_fetch_row($count_link);
if ($count == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}

$query_left = "SELECT * FROM exam WHERE ";
$query = $query_left.$query_right;
$whole_link = mysql_query($query, $link);
if ($whole_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}
$whole= mysql_fetch_row($whole_link);
if ($whole == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库查询操作失败！')";
	echo "</script>";
	exit();
}

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> New Page 1 </title>
	</head>
	<body>
		<div align = "center">
		<center>
			<table border = 1 width = "73%" height = 192>
				<tr>
					<td width = "25%" align = center height = 30> 姓名 </td>
					<td width = "25%" align = "center" height = 30> 
						<?php echo("$whole[name]"); ?>
					</td>
					<td width = "25%" align = center height = 30> 考分 </td>
					<td width = "25%" align = "center" height = 30> 
						<?php echo("$whole[mark]"); ?>
					</td>
				</tr>
				<tr>
					<td width = "25%" align = center height = 30> 性别 </td>
					<td width = "25%" align = "center" height = 30> 
						<?php echo("$whole[sex]"); ?>
					</td>
					<td width = "25%" align = center height = 30> 电话 </td>
					<td width = "25%" align = "center" height = 30> 
						<?php echo("$whole[tele]"); ?>
					</td>
				</tr>
				<tr>
					<td width = "25%" align = center height = 30> 联系地址 </td>
					<td width = "75%" align = "center" height = 61 colspan = 3> 
						<?php echo("$whole[address]"); ?>
					</td>
				</tr>
			</table>
		</center>
		</div>
	</body>
</html>