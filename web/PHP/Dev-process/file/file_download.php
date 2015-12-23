<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");
require_once('../include/file.func.tool.php');

$fid = $_GET['fid']+0;	// 安全检查

$sql = "select * from files where fid = '$fid'";
if ($file = getRow($sql, $conn))
{
	download($file['filepath'], $file['filename']);
}
else
{
	die('id非法，请检查！');
}
?>