<?php
/*
	文件删除
	
	用户删除，不删除文件，仅修改数据库文件状态，伪删除，可恢复
	管理员删除，彻底删除，不可恢复
*/

header('content-type: text/html; charset=utf-8');
require("../include/init.php");
require_once('../include/file.func.tool.php');

$fid = $_GET['fid'] + 0;	// 安全检查

function del_file($fid, $user=0)
{
	$del_time = time() + 8 * 3600;
	
	if ($user == 1) // 彻底删除 admin 0代表普通用户
	{
		$sql = "select filepath from files where fid = '$fid'";
		if ($file = getRow($sql))
		{
			$path = $file['filepath'];
			if (file_exists($path))
			{
				unlink($path);	// 彻底删除
			}
			else
			{
				$err_msg = "对不起，该文件不存在，请检查文件名！";
			}
			
			/*
				删除成功，才能修改数据库，否则数据将发生不完整性！此逻辑有些问题
				如果文件不存在，但是找到了，说明数据库有记录，此时也应该删除该记录，因为此记录是无效记录
			*/
			$sql = "delete from files where fid = '$fid'";	// 彻底删除
		}
		else
		{
			$err_msg =  "对不起，删除失败，该文件可能不存在，请检查文件名，或者稍后再试！";
		}
	}
	else
	{
		$sql = "update files set status = 2, del_time = $del_time where fid = '$fid'";
	}
	
	/*print_r($sql);
	exit;*/
	$result = mysql_query($sql);
	if (!$result)
	{
		$err_msg =  "对不起，删除失败，数据库繁忙，请稍后再试！";
	}
	else if (mysql_affected_rows() == 0)
	{
		$err_msg =  "对不起，删除失败，该文件可能不存在，请检查文件名，或者稍后再试！";
	}
	
	if (isset($err_msg))
	{
		//echo $err_msg;
		return $err_msg;
	}
	
	return true;
}

// 根据用户身份，控制删除 默认值0 普通用户， 1管理员
if (is_string($err_msg = del_file($fid, 1)))
{
	 
	include("../error/error.php");
	exit;
}
else
{
	echo "<script> alert('文件删除成功！'); window.location.href=\"filesys.php\"; </script>";
	//echo "<script> alert('文件删除成功！'); history.go(-1); </script>";
	// history.go(-1) 不能刷新页面！
	exit;
}

?>