<?php

require('../include/init.php');

$cid = $_GET['cid'] + 0;	// 通过id查询
if ($cid <= 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = 'select * from tablename where cid='.$cid;

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
		</div>
		<table>
			<tr>
				<td align = "center">
					<p> 你<br>的<br>基<br>本<br>信<br>息 </p>
				</td>
				<td>
					<tr>
						<td>
							邮箱：
						</td>
						<td>
							<?php echo $classmate['email']; ?>
						</td>
					</tr>
					<tr>
						<td>
							学校：
						</td>
						<td>
							<?php echo $classmate['school']; ?>
						</td>
					</tr>
					<tr>
						<td>
							生日：
						</td>
						<td>
							<?php echo $classmate['birthday']; ?>
						</td>
					</tr>
					<tr>
						<td>
							电话：
						</td>
						<td>
							<?php echo $classmate['tel']; ?>
						</td>
					</tr>
				</td>
			</tr>
			<tr>
				<td>
					爱好：
				</td>
				<td>
					<?php echo $classmate['hobby']; ?>
				</td>
			</tr>
		</table>
	</body>
</html>
