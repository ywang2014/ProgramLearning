<?php
require("./include/init.php");

// 第一步：接收数据
//print_r($_POST);
$pid = trim($_POST['pid'] + 0);
$username = trim($_POST['username']);
$content = trim($_POST['content']);
$replytime = time();	// 返回当前时间戳

// 第二步：检测数据
if (!$tid || $pid || $username || $content)
{
	echo "有数据项为空，回复失败，请返回重填！";
	// TODO
	
	exit;
}

// 第三步：拼接sql
$sql = "insert into reply (tid, username, content, replytime) values($pid, '$username', '$content', $replytime)";

// 第四步：执行sql
if (mysql_query($sql, $conn))
{
	//echo "回复成功";
	$script = <<<EOT
	<script type = "text/javascript">
		alert('回复成功');
		window.location.href = 'project_page.php?pid=$pid';
	</script>
EOT;
	echo $script;
}
else
{
	echo "回复失败";
}

?>
