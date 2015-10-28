<?php
// ma_web2.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

$update = "UPDATE book SET lend = lend - 1 WHERE id = $book_id";
$result = mysql_query($update);
if ($result == 0)
{
	echo "对不起，数据库更新失败，您暂时不能还书！";
	exit();
}

$update = "UPDATE reader SET borrowed = borrowed - 1 WHERE id = $book_id";
$result = mysql_query($update);
if ($result == 0)
{
	echo "对不起，数据库更新失败，您暂时不能还书！";
	exit();
}

$query = "DELETE FROM booked WHERE book_id and re_id = $re_id";
$result = mysql_query($query);
if ($result == 0)
{
	echo "对不起，数据库删除失败，您暂时不能还书！";
	exit();		// 若此时 lend已经更新，则出现错误
}

echo "您已经成功归还了书！";

mysql_close();

?>