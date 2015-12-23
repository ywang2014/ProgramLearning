<?php
// 接受用户提交的项目表单
header('content-type: text/html; charset=utf-8');

require("../include/init.php");

/*
print_r($_POST);
var_dump(isset($_POST['notice']));
exit; 
//*/
if (isset($_POST['notice']))
{
	$username = '匿名';
}
else
{
	$username = addslashes('Alice');	// session获得
}

$content = trim($_POST['content']);

$qid = $_POST['qid'] + 0;
$ptime = time()+8*3600;

// 第二步，检测数据

if (trim($content) == '')
{
	echo "回答内容不能为空";
	exit;
}

// 第三步，拼接sql子句--自动拼接
$sql = "insert into answers (qid, username, content, ptime) values (".$qid.",'".
	$username."','".$content."',".$ptime.")";

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
		"window.location.href = 'question_page.php?qid=".$qid."';".
		"</script>";
}

?>