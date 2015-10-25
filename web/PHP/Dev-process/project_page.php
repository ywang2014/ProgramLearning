<?php
/*
* 动态页面
*/
require('./include/init.php');

$tid = $_GET['tid'] + 0;	// 通过id查询
if ($tid <= 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = 'select * from tablename where tid='.$tid;

$project = getRow($sql, $conn);
if (empty($project))
{
	exit('查找失败，id非法！');
}

// print_r($project);

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Project Show </title>
	</head>
	
	<body>
		<div>
			<h1> <?php echo $project['title']; ?></h1>
		</div>
		<table>
			<tr>
				<td>
					<p> <?php echo $project['username']; ?></p>
				</td>
				<td>
					<tr>
						<td>
							<p> <?php echo $project['title']; ?></p>
						</td>
						<td>
							<p> <?php echo $project['pubtime']; ?></p>
						</td>
					</tr>
					<tr>
						<td>
							<p> <?php echo $project['content']; ?></p>
						</td>
					</tr>
				</td>
			</tr>
		</table>
	</body>
</html>

// 添加表单，可以用于评论和回复等！