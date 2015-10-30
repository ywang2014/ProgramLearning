<?php

require('../include/init.php');

$cid = $_GET['cid'] + 0;	// 通过id查询
if ($cid <= 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = 'select * from classmates where cid='.$cid;

@mysql_select_db($_CFG['dbname'], $conn) or die("数据库选择失败！");

$classmate = getRow($sql, $conn);
if (empty($classmate))
{
	exit('查找失败，id非法！');
}

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Personal Infomation </title>
	</head>
	
	<body>
		<div>
			<h1> 欢迎，<?php echo $classmate['name']; ?></h1>
			<hr>
		</div>
		<table>
			<tr>
				<td align = "center">
					你<br>的<br>基<br>本<br>信<br>息
				</td>
				<td>
					<p> 邮箱：<?php echo $classmate['email']; ?> </p>
					<p> 学校：<?php echo $classmate['school']; ?> </p>
					<p> 生日：<?php echo $classmate['birthday']; ?> </p>
					<p> 电话：<?php echo $classmate['tel']; ?> </p>
				</td> 
			</tr>
			<tr>
				<td>
					个人爱好：
				</td>
				<td>
					<?php echo $classmate['hobby']; ?>
				</td>
			</tr>
		</table>
		<div>
			<a href = "../index.php"> 首页 </a>
		</div>
	</body>
</html>
