<?php
/*
	文件处理函数
*/
function mk_dir($filedir)
{
	$dir = $filedir.date('ym/d', time());
	if (! is_dir($dir))
	{
		mkdir($dir, 0777, true);	// true级联创建法
	}
	
	return $dir;
}

function getfileExt($file)
{
	return end(explode('.', $file));
}

function randName()
{
	$str = 'abcdefghijklmnopqrstuvwxyz123456789';
	return substr(str_shuffle($str), 0, 8);
}

function isImageByType($type)
{
	switch ($type)
	{ 
		case 'image/pjpeg':
		case 'image/jpeg':
		case 'image/gif':
		case 'image/png':
			$ret = true; 
			break;
		default: 
			$ret = false;
			break;
	} 
	return $ret;
}

function isImageByExt($filename)
{
	$ext = strtolower(getfileExt($filename));
	$types = "gif|jpg|jpeg|png|bmp";
	if ($ext == 'gif' || $ext == 'jpg' || $ext == 'jpeg' || $ext == 'png' || $ext == 'bmp')
	{
		return true;
	}
	return false;
}

function getErrorMsg($error)
{
	switch ($error)
	{ 
		case 0:
			return false;
		case 1:
			$msg = '对不起，文件太大，系统无法上传！';
			break;
		case 2:
			$msg = '对不起，文件太大，html无法上传！';
			break;
		case 3:
			$msg = '对不起，文件有问题！';
			break;
		case 4:
			$msg = '文件不能为空，请选择文件！';
			break;
		default: 
			$msg = '错误！！！！！！！';
			break;
	} 
	return $msg;
}

function download($file, $filename)
{
	if (! file_exists($file))
	{
		die('对不起，您想下载的文件不存在，可能已被删除！');
	}
	
	$fp = fopen($file, "r");
	$file_size = filesize($file);
	
	//下载文件需要用到的头
	header("Content-type: application/octet-stream");
	header("Accept-Ranges: bytes");
	header("Accept-Length:".$file_size);
	header("Content-Disposition: attachment; filename=".$filename);
	
	$buffer = 1024;
	$file_count = 0;
	//向浏览器返回数据 
	while(!feof($fp) && $file_count < $file_size)
	{
		$file_con = fread($fp,$buffer);
		$file_count += $buffer;
		echo $file_con;
	} 
	fclose($fp);
}

function getfileContents($file)
{
	if (! file_exists($file))
	{
		die('对不起，该文件不存在，可能已被删除！');
	}
	
	$fp = fopen($file, "r");
	$file_size = filesize($file);
	
	$buffer = 1024;
	$file_count = 0;
	$content = '';
	while(!feof($fp) && $file_count < $file_size)
	{
		$file_con = fread($fp,$buffer);
		$file_count += $buffer;
		$content += $file_con;
	} 
	fclose($fp);
	
	return $content;
}


?>