<?php
// 创建数据库表SQL语句
CREATE TABLE sales(g_id int(11) DEFAULT '0' NOT NULL auto_increment, g_week tinyint(4)
					DEFAULT '0' NOT NULL, g_item tinytext NOT NULL, g_num int(11)
					DEFAULT '0' NOT NULL, PRIMARY KEY (g_id));
?>

<?php 
$columns = 6;
$max = 95400;

// bcdiv用第二个参数整数第一个参数，返回第三个参数指定的小数位数的值
$xincrement = bcdiv(200, $columns - 1, 0);

$y = bcmul(bcdiv($salesRow[0], $max, 2), 200, 2);
?>

<?php
// 发送头信息和创建初始的空白画布
header("Content-type: image/jpeg");
$image = imagecreate(200, 200);
// 分配一些颜色
$red = imagecolorallocate($image, 255, 0, 0);
$blue = imagecolorallocate($image, 0, 0, 255);
$white = imagecolorallocate($image, 255, 255, 255);
$grey = imagecolorallocate($image, 200, 200, 200);
// 创建灰色矩形用于绘图
imagefilledrectangle($image, 0, 0, 200, 200, $grey);
// 连接MYSQL数据库并选择数据库
$connect = mysql_connect("", "root", "");
mysql_select_db("graphing", $connect);
// 找到结果集中的最大数值
$sql = "SELECT MAX(g_num) FROM sales";
$maxResult = mysql_query($sql, $connect);
$max = mysql_result($maxResult, 0, 0);
// 得到公司A的结果集
$sql = "SELECT g_num FROM sales WHERE g_team = '公司A'ORDER BY g_month";
$salesResult = mysql_query($sql, $connect);
// 找到返回多少列，就是columns的数值
$columns = mysql_num_rows($salesResult);
// $x每次增加的权值
$xincrement = bcdiv(200, $columns - 1, 0);
$x = 0;
// $i将记录行的数值
$i = 0;
// 在所有的数据行中循环
while ($salesRow = mysql_fetch_array($salesResult))
{
	// 计算y的坐标值
	$y = bcmul(bcdiv($salesRow[0], $max, 2), 200, 2);
	// 在$points数组中增加值
	$points[$i][0] = $x;
	$points[$i][1] = $y;
	// 增加x的值用$xincreament
	$x += $xincrement;
	$i++;
}
// 现在在$points数组中循环，此时$i小于$columns-1
for ($i = 0; $i < $columns - 1; $i++)
{
	// 传递$points[$i][0]作为第一个x坐标，$points[$i][1]作为第一个y坐标
	imageline($image, $points[$i][0], 200-$points[$i][1], $points[$i+1][0], 200-$points[$i+1][1], $red);
}

// 网站B的数据
$sql = "SELECT g_num FROM sales WHERE g_team = 'Atlanta'ORDER BY g_week";
$salesResult = mysql_query($sql, $connect);
$columns = mysql_num_rows($salesResult);
$xincrement = bcdiv(200, $columns - 1, 0);
$x = 0;
$i = 0;
while ($salesRow = mysql_fetch_array($salesResult))
{
	// 计算y的坐标值
	$y = bcmul(bcdiv($salesRow[0], $max, 2), 200, 2);
	// 在$points数组中增加值
	$points[$i][0] = $x;
	$points[$i][1] = $y;
	// 增加x的值用$xincreament
	$x += $xincrement;
	$i++;
}
// 现在在$points数组中循环，此时$i小于$columns-1
for ($i = 0; $i < $columns - 1; $i++)
{
	// 传递$points[$i][0]作为第一个x坐标，$points[$i][1]作为第一个y坐标
	imageline($image, $points[$i][0], 200-$points[$i][1], $points[$i+1][0], 200-$points[$i+1][1], $blue);
}

// 输出GIF给浏览器并且释放内存
imagejpeg($image);
imagedestroy($image);
?>