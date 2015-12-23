<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");
require_once('../include/file.func.tool.php');

$file = $_FILES['upload'];
/*print_r($file);
exit;
*/

if ($file['error'] != 0)
{
	echo "文件上传失败！";
	exit;
}

$filedir = './data/uploadfile/';

$path = mk_dir($filedir).'/'.randName().'.'.getfileExt($file['name']);
/*print_r($path);
exit;
*/

if (move_uploaded_file($file['tmp_name'], $path))	// 当前目录下的file文件夹中
{
	$msg =  "success"; 
}
else
{
	echo "文件上传失败，请稍后再试";
	exit;
}

$username = trim($_POST['username']);	// session 隐式传入
$filename = $file['name'];
$filepath = $path;
$uptime = time()+8*3600;

$sql = "insert into files (username, filename, filepath, uptime)".
		"values ('$username', '$filename', '$filepath', '$uptime')";
if (!mysql_query($sql, $conn))
{
	echo "上传失败";
	exit;
}
else
{
	
	$fid = mysql_insert_id($conn);
	
	echo "<script type = \"text/javascript\">".
		"alert('上传成功');".
		"window.location.href = 'filesys.php';".
		"</script>";
}

?>