<?php
/*
	缓存日志文件
	
		filesize > 1M
			此时必须考虑缓存问题！
		重命名日志文件 cur.log --> 20151104.bak
		新建一个cur.log文件
*/

for ($file = './cur.txt', $i = 0; $i < 100; $i++)
{
	echo filesize($file).'<br>';	// 注意：filesize 会缓存
	$fh = fopen($file, 'ab');
	fwrite($fh, $i."\r\n");
	fclose($fh);
}

for ($file = './cur.txt', $i = 0; $i < 100; $i++)
{
	clearstatcache(true, $file);	// 清除缓存
	echo filesize($file).'<br>';	// 注意：filesize 会缓存
	$fh = fopen($file, 'ab');
	fwrite($fh, $i."\r\n");
	fclose($fh);
}

echo "end";

?>