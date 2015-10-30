<?php
// 借书续借处理程序 ma_web1.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

// 计算应该还书时间
$date_l = time() + 60 * 60 * 24;

// 构造查询语句
$insert = "INSERT INTO booked(re_id, book_id, returnt, able, endm) values($re_id, $book_id, $date_l, true, false)";
mysql_query($insert) or die("<p align = center> 录入时发生错误");

$update = "UPDATE book set lend = lend + 1 WHERE id = $book_id";
$result = mysql_query($update);
if ($result == 0)
{
	echo "对不起，数据库更新失败，您暂时无法借书！";
	exit();
}

echo "您已经成功借了此书！";

mysql_close();

// 手工填写编号的方法很 low，现在图书馆都是直接扫码器扫条形码读取编号，输入非常迅速。
// 仅仅只是输入设备不同而已，其他一样。
?>