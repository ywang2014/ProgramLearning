<?php
/*
	文件删除页面 del_file.php
*/
$filePath = "..".trim($_GET['filePath']);
if ($filePath)
{
	@unlink($filePath);
	echo "<script> alert('删除成功'); </script>";
}
else
{
	echo "<script> alert('删除错误，可能文件不存在或者已删除！'); </script>";
}

?>