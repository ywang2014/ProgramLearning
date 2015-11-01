<?php
/* 
	处理文件上传：
	
		必须使用post提交，默认使用get
		声明enctype选项，提示服务器，上传的是文件，二进制信息，不是普通的文件名字符串信息
	
	直接上传到服务器
	
	生成临时文件：$_FILES超级全局数组
	
	数组中保存着文件相关信息
	[name]			文件名
	[type]			文件类型
	[tmp_name]		临时文件
	[error]			错误代码：0代表文件无错误
	[size]			文件大小

*/

//print_r($_POST);
//print_r($_FILES);

/*
// 移动文件到指定地址  move_uploaded_file()
if (move_uploaded_file($_FILES['pic']['tmp_name'], './file/'.$_FILES['pic']['name']))	// 当前目录下的file文件夹中
{
	echo "success"; 
}
else
{
	echo "fail";
}
*/

/************
*	按日期分目录存储：创建目录
*	获取文件后缀名
*	判断文件大小
*/

function mk_dir()
{
	$dir = date('ym/d/i', time());
	if (is_dir('./'.$dir))
	{
		return $dir;
	}
	else
	{
		mkdir('./'.$dir, 0777, true);	// true级联创建法
		return $dir;
	}
}

// 获取后缀名
function getExt($file)
{
	$tmp = explode('.', $file);
	return end($tmp);
}

function randName()
{
	$str = 'abcdefghijklmnopqrstuvwxyz123456789';
	return substr(str_shuffle($str), 0, 6);	// 随机生成6个字符长的文件名
}

if ($_FILES['pic']['error'] != 0)
{
	echo "fail";
	exit;
}

// $file_name = $_POST['pic'];
$myfile = $_FILES['pic'];

// 处理文件上传

$path = './'.mk_dir().'/'.randName().'.'.getExt($myfile['name']);

if (move_uploaded_file($myfile['tmp_name'], $path))	// 当前目录下的file文件夹中
{
	echo "success"; 
}
else
{
	echo "fail";
}

/*
	文件存储在硬盘
	文件路径存储在数据库.
*/
?>