<?php
header('content-type: text/html; charset=utf-8');
require("./include/init.php");
require_once('./include/file.func.tool.php');

/*
	文件太大会有问题！
*/
$file = isset($_FILES['file']) ? $_FILES['file'] : '';
/*print_r($file);
var_dump($file['error']);
exit;
*/

if ($msg = getErrorMsg($file['error']))
{
	echo "<script> alert('$msg'); history.go(-1); </script>";
	exit;
}
else if ((! isImageByExt($file['name'])) || (! isImageByType($file['type'])))
{
	echo "<script> alert('照片格式不正确，请检查！'); history.go(-1); </script>";
	exit;
}

$filedir = './data/images/';

$path = mk_dir($filedir).'/'.randName().'.'.getfileExt($file['name']);

if (! move_uploaded_file($file['tmp_name'], $path))
{
	echo "<script> alert('对不起，服务器繁忙，请稍后再试！'); history.go(-1); </script>";
	exit;
}

$username = trim($_POST['username']);
$imagename = $file['name'];
$imagepath = $path;
$uptime = time()+8*3600;

$sql = "insert into photos (username, imagename, imagepath, uptime)".
		"values ('$username', '$imagename', '$imagepath', '$uptime')";
if (!mysql_query($sql, $conn))
{
	echo "上传失败";
	exit;
}
else
{
	echo "<script type = \"text/javascript\">".
		"alert('上传成功');".
		"window.location.href = 'photo_album.php';".
		"</script>";
}

?>