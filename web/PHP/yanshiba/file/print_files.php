<?php
/*
	文件操作
*/

/*
	第一步，找到所有.txt文件
*/
print_r(glob('./*.php'));	// 路径和文件名

/*
	opendir		打开目录，返回资源列表
	closedir	关闭目录
	readdir
	mkdir
	rmdir
	is_dir
*/
$
$dh = opendir($path);	// 句柄

while (($filename = readdir($dh)) !== false)	// 否则不能读为名 0 的目录或文件
{
	echo $filename."<br>";	// 读取目录的子目录或文件名
}

closedir($dh);

?>