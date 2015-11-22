<?php
/*
* 动态页面
*/
require('./include/init.php');

$pid = $_GET['pid'] + 0;	// 通过id查询
if ($pid < 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = "select * from projects where pid = '$pid'";

// 此句必须要，否则插入、查找等都会失败！
mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");

$project = getRow($sql, $conn);
if (empty($project))
{
	exit('查找失败，id非法！');
}

// print_r($project);

$sql = "select * from reply where pid = '$pid' order by replytime";

mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");
$replys = getAll($sql, $conn);	// 回复可能有多行记录

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Project Show </title>
	</head>
	
	<body>
		<center>
		<div>
			<h1> <?php echo $project['title']; ?></h1>
		</div>
		
		<table border = 1>
			<tr>
				<td>
					<p> <a href = "#"> <?php echo $project['username']; ?></p>
				</td>
				<td>
					<p> <?php echo $project['title']; ?>
						 <?php echo $project['pubtime']; ?>
					</p>
					<p> <?php echo $project['content']; ?></p>
				</td>
			</tr>
			
			<?php foreach($replys as $v)
			{ ?>
			<!-- ************** 回复开始 ***************** -->
			<tr>
				<td style="height:200px;width:200px;">
					<a href = "#"> <?php echo $v['username']; ?> </a>
					<p> 回复时间：<?php echo date("Y-m-d", $v['replytime']); ?> </p>
				</td> 
				<td style="height:200px;width:200px;">
					<textarea style="width:100%;height:100%;"> <?php echo $v['content']; ?> </textarea>
				</td>
			</tr>
			<?php } ?>
			<!-- ************** 回复结束 ***************** -->
		</table>
		
			<div>
				<form action = "replyaction.php" method = "post">
					<p>
						<input type = "hidden" name = "pid" value = "<?php echo $_GET['pid']; ?>">
					</p>
					<p>
						&nbsp;用户名：<input type = "text" name = "username">
					</p>
					<p>
						&nbsp;<textarea name = "content"> </textarea>
					</p>
					<p>
						&nbsp;<input type = "submit" value = "回复">
					</p>
				</form>
			</div>
	</body>
</html>
