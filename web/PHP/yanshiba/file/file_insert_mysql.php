<?php
/*
	文件内容插入数据库
*/

// 1.一次读完，大文件不可取
$file = './a.txt';
$content = file_get_contents($file);
print_r(explode("\n", $contents));	// 换行符和具体系统有关 win "\r\n" Unix "\n" Linux "\r"

// 2.一次一次读
$fh = fopen($file, 'rb');	// 2进制，不受编码影响
while (!feof($fh))
{
	echo fgets($fh).'<br>';
}

// 3.一次读取
$arr = file($file);
print_r($arr);

/*
	file_exists($file)
	filemtime($file)
*/

?>