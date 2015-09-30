<?php
// 续借功能实现
// ma_web3.php

include "common.php";

// connection
$link = mysql_connect($hostname, $username, $password) or die("数据库服务器连接失败！");

// 选择数据库library, 在函数前加"@"符号，将会抑制错误信息的显示
// 使用 mysql_select_db 函数激活数据库表，后面的操作不需要专门添加表名
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

// 计算续借后的时间戮，即应归还时间
$date_l = time() + 60 * 60 * 24 * $max_lend_days;

// 构造SQL查询语句
$query = "UPDATE booked SET able = false, returnt = $date_l WHERE num0 = $book_id and num1 = $re_id";
$result = mysql_query($query);
if ($result == 0)
{
	echo "对不起，数据库更新失败，暂时无法续借此书。";
	exit();
}

echo "您已经成功续借了此书！";

mysql_close();

?>