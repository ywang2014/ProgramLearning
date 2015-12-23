<?php
/*
	评论处理
*/

header('content-type: text/html; charset=utf-8');
require("./include/init.php");

// 第一步接受数据
$bid = addslashes(trim($_POST['bid'])) + 0;
$username = addslashes(trim($_POST['username']));
$content = addslashes(trim($_POST['content']));
$time = time() + 8*3600;

// 第二步，检测数据
if (trim($username) == '')
{
	echo"<script> alert('用户名不能为空！');history.go(-1);</script>";  
	exit;
}

if (trim($content) == '')
{
	echo"<script> alert('评论内容不能为空！');history.go(-1);</script>";  
	exit;
}

// 第三步，拼接sql子句--自动拼接
$sql = "insert into comments (bid, username, content, ptime) values ('".$bid."','"
		.$username."','".$content."',".$time.")";
/*print_r($sql);
exit;*/

// 第四步，执行sql
if (!mysql_query($sql))
{
	echo"<script> alert('评论失败，请稍后再试！！');history.go(-1);</script>";  
	exit;
}
else
{
	
	echo "<script type = \"text/javascript\">".
		"alert('评论成功');".
		"window.location.href = 'blog_page.php?bid=$bid';".
		"</script>";
}


?>