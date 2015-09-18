<?php

// 建立数据库

// 以只读方式打开文件
$file_handle = fopen("infor.txt", "r");

// 读取文件信息
$information = fread($file_handle, 1);	// 0表示尚未创建数据库，1表示已创建

// 关闭文件：防止文件破坏，应及时关闭文件
fclose($file_handle);

$info_num = ord($information);

if ($info_num == 48)	// 1 的序数值，即ord("1")的值为48
{
	exit();	// 已创建，跳出
}
	
$databasename = "mydb";	// 数据库名称
$tablename = "guest_book";	// 数据表名

// 创建表的SQL语句
// 姓名、电子信箱、留言标题、留言内容、留言时间、回复内容、回复时间、留言序号
$create_sql = "CREATE TABLE %s(
								name varchar(30) null,
								email varchar(30) null,
								title varchar(200) null,
								content text not null,
								date datetime null,
								reply text null,
								replydate datetime null,
								postno int(11) not null, 
								default(),
								primary key auto_increment
								)";

// 输出错误信息函数
function printerror($errormessage)
{
	printf("<br> %s <br> \n", $errormessage);
}

// 连接数据库，若连接出错，则跳出
$hostname = "127.0.0.1";
$username = "root";
$password = "root";
if (! ($link = mysql_connect($hostname, $username, $password)))
{
	printerror(sprintf("error connecting to host %s, by user %s", $hostname, $username));
	exit();
}

// 创建数据库，若创建出错则跳出
if (! mysql_create_db($databasename, $link))
{
	printerror(sprintf("错误创建数据库 %s", $databasename));
	printerror(sprintf("错误：%d %s", mysql_errno($link), mysql_error($link)));
	exit();
}

printf("<br> 已创建了数据库 %s <br> \n", "mydb");
// 把创建的数据库设为当前激活的数据库
if (! mysql_select_db($databasename, $link))
{
	printerror(sprintf("设置数据库 %s 为当前激活的数据库出错", $databasename));
	printerror(sprintf("错误：%d %s", mysql_errno($link), mysql_error($link)));
}

// 创建表
if (! mysql_query(sprintf($create_sql, $tablename), $link))
{
	printerror(sprintf("执行错误 %s create_sql", $create_sql));
	printerror(sprintf("错误: %d %s", mysql_errno($link), mysql_error($link)));
	exit();
}

printf("<br> 已创建表 %s.%s <br> \n", $databasename, $tablename);

// 更改文件信息
$file_handle = fopen("infor.txt", "w");
fputs($file_handle, "1");
fclose($file_handle);

?>