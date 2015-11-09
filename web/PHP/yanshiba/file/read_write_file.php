<?php
/*
	读取文件内容
*/

$file = "./a.txt";
echo file_get_contents($file);
$str = file_get_contents($file);

file_put_contents('./b.txt', $str);
/*
	此两个函数是非常强大的函数，但是一次读取全部文件内容，比较恐怖。10M以上不好了
	
	fopen
	fread
	fwrite
	fclose
*/

$fh = fopen($file, 'r');
echo fread($fh, 100);
var_dump(fwrite($fh, 'aaaaaaa'));	// 只读不能写

fclose($fh);

$fh = fopen($file, 'r+');	// 文件头写入内容！覆盖相同长度内容
var_dump(fwrite($fh, 'bbbbbb'));

?>