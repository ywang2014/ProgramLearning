<?php
// 网上续借
// re_selfa.php

include "common.php";
		
$link = mysql_connect($hostname, $username, $password);
if($link == 0)
{
	echo "<p align = center> 数据库服务器连接失败！";\
	exit();
}
		
if (mysql_select_db($dbname, $link) == 0)
{
	echo "<p align = center> 激活数据库出错";
	exit();
}

$query = "SELECT book.name, booked.book_id, booked.returnt, booked.able FROM book, booked WHERE booked.re_id = $id and booked.book_id = book_id";
$result = mysql.query($query);	// 查询数据
		
echo "<table border = 1 cellspacing = 0 cellpadding = 0>";	// 开始输出表格
echo "<tr>";
echo "<th width = 25%> 书号 </th> <th width = 25%> 书名 </th> <th width = 25%> 应还日期 </th> <th width = 25%> 是否已续借 </th> <th> 续借 </th>";
echo "</tr>";
		
if ($result != 0)
{
	// 显示数据
	while ($row = mysql_fetch_array($result))
	{
		echo "<tr>";
		echo "<td> $row['book_id'] </td>";
		echo "<td> $row['name'] </td>";
		echo "<td>".date("m-d-Y h:i", $row['returnt'])."</td>";
		if ($row['able'])
		{
			echo "<td> 否 </td>";
		}
		else
		{
			echo "<td> 是 </td>";
		}
		
		echo "<td> <a href = \"ma_web3.php? num0 = $row['book_id'] & $num1 = id\"> 续借 </a> </td>";
		echo "</tr>";
	}
	
	echo "</table>";
			
	// 释放result资源
	mysql_free_result($result) or die("无法释放result资源！");
}
else
{
	echo "目前没有数据！";
}
		
mysql_close($link) or die("无法与服务器断开连接!");
		
?>