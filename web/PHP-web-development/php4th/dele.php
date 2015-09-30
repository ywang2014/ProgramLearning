<?php
// 删除记录
	// 4.4 文件dele.php
$link = mysql_select_db("teach", $link_us);
if ($id > 0)
{
	mysql_query("DELETE FROM classmates WHERE id = $id", $link_us);
}
?>

<html>
	<body>
		<b> 祝贺你，已经成功删除! </b>
	</body>
</html>