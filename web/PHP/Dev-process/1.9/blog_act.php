<?php
// 接受用户提交的项目表单
header('content-type: text/html; charset=utf-8');

require("./include/init.php");

/*
print_r($_POST);
exit; 
*/

$title = addslashes(trim($_POST['title']));
$username = addslashes(trim($_POST['username']));
$types = addslashes(trim($_POST['types']));
$content = addslashes(trim($_POST['content']));
$ptime = time()+8*3600;

// 第二步，检测数据
if ($title == '')
{
	echo "主题不能为空";
	exit;
}
if ($username == '')
{
	echo "用户名不能为空";
	exit;
}
if ($types == '')
{
	echo "类型不能为空";
	exit;
}
if (trim($content) == '')
{
	echo "内容不能为空";
	exit;
}

// 第三步，拼接sql子句--自动拼接
$sql = "insert into blogs (username, title, types, content, ptime) values ('".
	$username."','".$title."','".$types."','".$content."',".$ptime.")";

// 第四步，执行sql
if (!mysql_query($sql))
{
	echo "发布失败";
	exit;
}
else
{
	$pid = mysql_insert_id($conn);
	
	echo "<script type = \"text/javascript\">".
		"alert('发布成功');".
		"window.location.href = 'blog.php';".
		"</script>";
}

?>