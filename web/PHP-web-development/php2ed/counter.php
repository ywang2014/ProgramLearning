<?php
/* 计数器的设计
*  功能：记录访问页面的人次，每次访问都加1
*  PHP文件只能写入字符串文件，0-9的ASCII码值：48-58
*/

// 以文件counter.txt存储数据
// 若文件不存在，则创建文件
if (!file_exists("counter.txt"))
{
	$file_handle = fopen("counter.txt", "w");	// 建立文件
	fputs($file_handle, "0");	// 有访客之前，访问人数为0
	fclose($file_handle);
}
$file_handle = fopen("counter.txt", "r");
$no = fread($file_handle, 7);	// 读取数据
fclose($file_handle);
$no_1 = $no + 1;	// 访问人数加1，自动转化为数字类型
echo("<h1> 你是本站的第 $no_1 位访问者 </h1>");
$no_string = (string)$no_1;	// 转化为字符串类型
$file_handle = fopen("counter.txt", "w");
fputs($file_handle, $no_string);	// 重新写入数据
fclose($file_handle);
// 需要加锁处理，否则，同时访问时，可能数据混乱！
?>