<?php
require("../include/common.php");
function getAll($sql, $conn)
{
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	$row_arr = array();
	while ($row = mysql_fetch_assoc($result))
	{
		$row_arr[] = $row;
	}
	
	return $row_arr;
}

$link = mysql_connect($hostname, $username, $hostpassword) or die("数据库服务器连接失败！");
@mysql_select_db($dbname, $link) or die("数据库连接失败！");

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
		$sql = "SELECT * from book where name like = '$keyword'";
		break;
	case "author":
		$sql = "SELECT * from book where author like '%$keyword%'";
		break;
	case "pubtime":
		$sql = "SELECT * from book where time like '%$keyword%'";
		break;
	case "content":
		$sql = "SELECT * from book where memo like '%$keyword%'";
		break;
	default:
		break;
}
//print_r($sql);
$rows = getAll($sql, $link);
//print_r($rows);

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> booksInformation </title>
		<style type="text/css">
			a:link,a:visited{text-decoration:none;}
			a:hover{text-decoration:none; color:gray;}
		</style>
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
					<hr style = "width: 400px;">
						<table align = center>
							<tr >
								<td> 书名：</td>
								<td> <?php echo $v['name']; ?> <td>
							</tr>
							<tr >
								<td> 作者：</td>
								<td> <?php echo $v['author']; ?> <td>
							</tr>
							<tr >
								<td> 出版日期：</td>
								<td> <?php echo $v['time']; ?> <td>
							</tr>
							<tr >
								<td> 出版社：</td>
								<td> <?php echo $v['pub']; ?> <td>
							</tr>
							<tr >
								<td> 总共藏书：</td>
								<td> <?php echo $v['num']; ?> 本 <td>
							</tr>
							<tr >
								<td> 共借出：</td>
								<td> <?php echo $v['lend']; ?> 本 <td>
							</tr>
						</table>
					</div>
				</div>
			<?php } ?>
		</center>
		<div>
			<br> <p align = "right">
					<a href = "book_search.php"> 返回 </a>
				</p>
		</div>
	</body>
</html>