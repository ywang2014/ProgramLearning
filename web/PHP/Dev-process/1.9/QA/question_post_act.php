<?php
// 接受用户提交的项目表单
header('content-type: text/html; charset=utf-8');

require("../include/init.php");

/*
print_r($_POST);
exit; 
*/
$username = addslashes(trim($_POST['username']));
$title = addslashes(trim($_POST['topic']));
$content = trim($_POST['content']);
$notice = trim($_POST['notice']);
$wealth = trim($_POST['wealth']);
$ptime = time()+8*3600;

// 第二步，检测数据
if ($username == '')
{
	echo "用户名不能为空";
	exit;
}
if ($title == '')
{
	echo "题目简介不能为空";
	exit;
}
if (trim($content) == '')
{
	echo "题目描述不能为空";
	exit;
}

// 第三步，拼接sql子句--自动拼接
$sql = "insert into questions (username, title, content, notice, wealth, ptime) values ('".
	$username."','".$title."','".$content."','".$notice."',".$wealth.",".$ptime.")";
/*print_r($sql);
exit;*/

// 第四步，执行sql
if (!mysql_query($sql))
{
	echo "提交失败";
	exit;
}
else
{
	$pid = mysql_insert_id($conn);
	
	echo "<script type = \"text/javascript\">".
		"alert('提交成功');".
		"window.location.href = 'question.php';".
		"</script>";
}

?>