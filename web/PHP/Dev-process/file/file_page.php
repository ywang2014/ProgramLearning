<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");
require_once('../include/file.func.tool.php');

$fid = $_GET['fid'];	// 安全检查

$sql = "select * from files where fid = '$fid'";
if (!($file = getRow($sql, $conn)))
{
	echo "id非法！";
}

/*
// 读取文件
$path = $file['filepath'];
$content = file_get_contents($path);
print_r($content);
*/

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> file system </title>
		
		<link rel = "apple-touch-icon" href = "#">
		<link rel = "shortcut-icon" href = "#">
		<link rel = "stylesheet" href = "#">
		
		<style>
			header, footer, section, article, aside, nav, figure{
				display:block;
				margin:0;
				padding:0;
				border:0;
			}
			
			a {text-decoration:none; color: #000; font-size: 20px;}
			a:hover{text-decoration:none; color: #ef7a82}
			
		</style>
	</head>
	
	<body>
		<div id = ""> 
			<div class = "nav">
				<a href = "filesys.php"> 文件系统 </a>
			<div>
			<table width = "80%" style = "border: 1px solid #ddd; margin: 10px auto;">
				<tr>
					<td>
						<p>	
							<strong> <?php echo $file['filename']; ?> </strong>
							&nbsp; <?php echo $file['username']; ?>
							&nbsp; <?php echo date('Y-m-d H:i:s', $file['uptime']); ?>
							
						</p>
					</td>
				</tr>
				<tr>
					<td>
						<p>	
						<?php
							if (isImageByExt($file['filename']))
							{
								echo "<img src = ".$file['filepath']." width = 100% height = 100%>";
							}
							else
							{  ?>
								<hr>
								<a href = "file_read.php?fid=<?php echo $file['fid']; ?>"> 阅读全文 </a>
						<?php	} ?>
						</p>
					</td>
				</tr>
			</table>
		</div>
	</body>
</html>