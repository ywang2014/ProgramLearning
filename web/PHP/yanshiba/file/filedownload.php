<?php
/*
客户端从服务端下载文件的流程分析： 

浏览器发送一个请求，请求访问服务器中的某个网页（如：down.php），该网页的代码如下。 
服务器接受到该请求以后，马上运行该down.php文件 
运行该文件的时候，必然要把将要被下载的文件读入内存当中（这里是圣诞狂欢.jpg这张图片），这里通过fopen()函数完成该动作 
注意：任何有关从服务器下载的文件操作，必然需要先在服务端将文件读入内存当中 

现在文件已经在内存当中了，这是需要从内存当中读取文件，通过fread()函数完成该动作 
需要注意的是，如果文件较大，文件应该是被分成多段返回给客户端的，并不是等文件在服务端全部读取完毕后，一次性返回给客户端，因为这样子会增加服务器的负荷。 
所以我们需要在php代码中设置一次读取的字节数,比如我在下面的代码中通过$buffer=1024设置一次读取的字节数，每读取一次，就输出数据（即返回给浏览器） 

*/

// 告诉浏览器编码格式：utf-8 使用该编码格式显示内容
header("Content-type:text/html; charset = utf-8");

$filename = "cookie.jpg";

// 解决中文不能显示的问题：file_exists()函数不能识别中文文件名，使用iconv()函数进行编码转换 
$filename = iconv("utf-8", 'gb2312', $filename);
// 使用绝对路径，执行效率更高
$file_subpath = $_SERVER['DOCUMENT_ROOT']."php/download/";
$filepath = $file_subpath.$filename;

// 验证文件是否存在
if (!file_exists($filepath))
{
	echo "no file!";
	exit;
}

$fp = fopen($filepath, 'r');
$filesize = filesize($filepath);

/*
	下载文件需要的header
*/
// 告诉客户端浏览器，服务器返回文件的文件形式
header("Content-type: application/octet-stream");
// 告诉浏览器，返回的文件，按照字节计算大小的
header("Accept-Ranges: bytes");
// 告诉浏览器，返回文件的大小
header("Accept-Length: ".$filesize);
// 告诉浏览器，返回文件的名称
header("Content-Disposition: attachment; filename = ".$filename);

$buffer = 1024;
$filecount = 0;

// 向浏览器返回数据
while (!feof($fp) && $file_count < $filesize)
{
	$file_con = fread($fp, $buffer);
	$filecount += $buffer;
	echo $file_con;
}

// 关闭文件，并使得缓冲区剩余内容输出完成
fclose($fp);

?>

<?php
public function downloads($name)
{
	$name_tmp = explode("_",$name);
	$type = $name_tmp[0];
	$file_time = explode(".",$name_tmp[3]);
	$file_time = $file_time[0];
	$file_date = date("Y/md",$file_time;
	$file_dir = SITE_PATH."/data/uploads/$type/$file_date/"; 
	
	header("Content-type: text/html; charset=utf-8");
	
	if (!file_exists($file_dir.$name))
	{
		echo "File not found!";
		exit; 
	} 
	else
	{
		$file = fopen($file_dir.$name,"r"); 
		
		Header("Content-type: application/octet-stream");
		Header("Accept-Ranges: bytes");
		Header("Accept-Length: ".filesize($file_dir . $name));
		Header("Content-Disposition: attachment; filename=".$name);
		
		echo fread($file, filesize($file_dir.$name));
		
		fclose($file);
	}
}

?>

<?php

	$file_name = trim($_GET['FileName']);
	$file_dir = trim($_GET['FileDir']);
	$file_id = trim($_GET['FileId']);

	if ( empty($file_name)|| empty($file_dir)|| empty($file_id))
	{
		echo'<script> alert("非法连接 !"); location.replace ("index.php") </script>'; 
		exit;
	}
	
	$file_dir = trim($file_dir."/");
	
	if (!file_exists($file_dir.$file_name))		//检查文件是否存在  
	{
		echo "no file";  
		exit;    
	}
	else
	{  
		$file = fopen($file_dir . $file_name, "r"); // 打开文件
		
		// 输入文件标签
		Header("Content-type: application/octet-stream");
		Header("Accept-Ranges: bytes");
		Header("Accept-Length: ".filesize($file_dir . $file_name));
		Header("Content-Disposition: attachment; filename=" . $file_name);
		
		// 输出文件内容
		echo fread($file, filesize($file_dir . $file_name));
		
		fclose($file);
		exit;
	}
?>