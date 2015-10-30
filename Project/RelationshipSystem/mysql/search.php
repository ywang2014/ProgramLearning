<?php
require("../include/init.php");

$topic = $_POST['search_topic'];
$keyword = trim($_POST['search_keyword']);

if ($keyword == "")
{
	echo "<p align = center> 对不起，搜索内容不能为空，请填写搜索关键字！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回 </a>";
	exit();
}

switch ($topic)
{
	case "name":
		$sql = "SELECT * from ".$_CFG['table1']." where name = '$keyword'";
		break;
	case "school":
		$sql = "SELECT * from ".$_CFG['table1']." where school = '$keyword'";
		break;
	case "birthday":
		$sql = "SELECT * from ".$_CFG['table1']." where birthday = '$keyword'";
		break;
	case "city":
		$sql = "SELECT * from ".$_CFG['table1']." where city = '$keyword'";
		break;
	case "hobby":
		$sql = "SELECT * from ".$_CFG['table1']." where hobby like '%$keyword%'";
		break;
	default:
		break;
}

//@mysql_select_db($_CFG['dbname'], $conn) or die("数据库设置错误！");
$rows = getALL($sql, $conn);

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> FriendsInformation </title>
	</head>
	
	<body>
		<center>
			<h1 style = "color: red"> Search Result </h1>
			<hr>
			<?php 
			if ($rows == 0)
			{
				echo "<p align = center> 对不起，这里没有任何相关记录！！</p>";
				echo "<a href = \"../index.php\"> 请重新输入关键字！</a>";
				exit;
			}
			else
			{
				echo "共有 ".count($rows)." 记录！";
			}
			
			foreach ($rows as $v)
			{
			?>
				<div>
					<div>
						<table align = center>
							<br>
							<tr >
								<td> 姓名：</td>
								<td> <?php echo $v["name"]; ?> <td>
							</tr>
							<tr >
								<td> 生日：</td>
								<td> <?php echo $v["birthday"]; ?> <td>
							</tr>
							<tr >
								<td> 电话：</td>
								<td> <?php echo $v["tel"]; ?> <td>
							</tr>
							<tr >
								<td> 城市：</td>
								<td> <?php echo $v["city"]; ?> <td>
							</tr>
							<tr >
								<td> 爱好：</td>
								<td> <?php echo $v["hobby"]; ?> <td>
							</tr>
						</table>
					</div>
				</div>
			<?php } 
			require("../include/footer.php");
			?>
			