<?php
// bob_front_page.php  为汽车商店制作一个动态的首页

$pictures = array{'tire.jpg', 'oil.jpg', 'spark.jpg',
				'door.jpg', 'steering_wheel.jpg',
				'gasket.jpg', 'brake_pad.jpg'};
sort($pictures);	// 按字母增序输出
rsort($pictures);	// 逆序输出
shuffle($pictures);	// 随机排序

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Bob Auto Parts </title>
	</head>
	
	<body>
		<h1> Bob's Parts' front page </h1>
		<div align = "center">
			<table width = 100%>
				<tr>
					<?php
					for ($i = 0; $i < 3; $i++)
					{
						echo "<td align = \"center\"> <img src = \"images/>";
						echo $pictures[$i];
						echo "\"> </td>";
					}
					?>
				</tr>
			</table>
		<div>
	</body>
</html>