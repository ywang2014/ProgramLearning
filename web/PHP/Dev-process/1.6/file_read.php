<?php
/*
	文件预览
	
	改进：使用id传递不够安全，容易被用户自己输入id查看
		使用自己的加密技术
		或者使用md5加密id等,由于加密不可逆，故数据库需要存储此md5值！
		
		window.location更加不安全，把路径名等，全部暴露了，
			需要改进，使用加密技术生成！
*/

header('content-type: text/html; charset=utf-8');
require("./include/init.php");
require_once('./include/file.func.tool.php');

$fid = $_GET['fid'] + 0;	// 安全检查

$sql = "select * from files where fid = '$fid'";
if ($file = getRow($sql, $conn))
{
	echo "<script> window.location=\"".$file['filepath']."\";</script> ";
	// echo nl2br(htmlentities(file_get_contents($file['filepath']))); 乱码，格式也不对
}
else
{
	echo "id 非法!";
}

?>