<meta charset = "utf-8">

<?php
// 接受用户提交的项目表单

require("./include/init.php");

//print_r($_POST);	// 直接打印看看接受的数据
/*
* 拆分步骤，细化，如果有错误，立即知道
* 可以直接知道实际效果，增强自信
*
*/
$username = $_POST['username'];
$title = $_POST['title'];
$content = $_POST['content'];
$time = date("Y-m-d");
// 第一步接受数据

// 第二步，检测数据
if (trim($username) == '')
{
	echo "用户名不能为空";
	// 返回上一步
	
}
if (trim($title) == '')
{
	echo "项目名称不能为空";
	// 返回上一步
	
}
if (trim($content) == '')
{
	echo "项目内容不能为空";
	// 返回上一步
	
}

// 第三步，拼接sql子句--自动拼接
$sql = "insert into projects (username, title, content, pubtime) values ('".$username."','"
		.$title."','".$content."',".$time.")";
//echo $sql;

/*
* 一个有用的函数
* mysql_insert_id();
* 返回表中auto_increment列刚刚产生的最大值
* 插入后，需要立即使用该函数，否则可能得到奇怪的结果
*/
mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");
//mysql_query("set names gb2312");

// 第四步，执行sql
if (!mysql_query($sql))
{
	echo "发布失败";
	// TODO
}
else
{
	// 跳转到项目发布界面
	/*
	* script 代码：
	*	添加了弹出效果
	*	也可以使用header()
	*/
	
	$pid = mysql_insert_id($conn);
	//echo $pid;
	
	
	echo "<script type = \"text/javascript\">".
		"alert('发布成功');".
		"window.location.href = 'index.php';".
		"</script>";
	
}


?>