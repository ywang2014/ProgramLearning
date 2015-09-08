<?php
// 绘制柱状图
/*
$graphdata：百分比数据(y轴)，数组类型
$label：x轴标题
$data：实际数据(y轴)，数组类型
$width：图像宽度 
$height：图像高度 $height/100
$scale：高度因子 
$font：字体号
$bg：背景颜色
$text：文本颜色 
$grid：边线颜色 
$bar： 柱的颜色
$bz：备注
*/
function image($graphdata, $label, $data, $width, $height, $scale, $font, $bg, $text, $grid, $bar, $bz)
{
	header("Content - type: image/jpeg");
	$image = imagecreate($width + 50, $height + 50);
	$bgcolor = imagecolorallocate($image, $bg[0], $bg[1], $bg[2]);
	$textcolor = imagecolorallocate($image, $text[0], $text[1], $text[2]);
	$gridcolor = imagecolorallocate($image, $grid[0], $grid[1], $grid[2]);
	$barcolor = imagecolorallocate($image, $bar[0], $bar[1], $bar[2]);
	$gridabelwidth = imagefontwidth($fond) * 3 + 1;
	$gridabelheight = imagefontheight($fond);
	
	imageline($image, $gridlabelwidth, 0, $gridlabelwidth, $height-1, $gridcolor);
	imageline($image, 0, $height-1, $width-1, $height-1, $gridcolor);
	
	for ($i = 0; $i < count($graphdata); $i++)
	{
		$bartopx = $gridlabelwidth + (($i + 1) * 20) + ($i * $barwidth);
		$barbottomx = $bartopx + $barwidth;
		$barbottomy = $height - 1;
		$bartopy = $barbottomy - ($graphdata[$i] * $scale);
		// 图形着色
		imagefilledrectangle($image, $bartopx, $bartopy, $barbottomx, $barbottomy, $barcolor);
		$labelx1 = $bartopx;
		$labely1 = $bartopy - 15
		$labelx2 = $bartopx;
		$labely2 = $height;
		// 输出字符串
		imagestring($image, $font, $labelx1, $labely1, "$graphdata[$i]"."%", $textcolor);
		imagestring($image, $font, $labelx2, $labely2, "$label[$i]", $textcolor);
		imagestringup($image, $fond, $labelx1+10, $labely1-$gridabelheight, "$data[$i]", $textcolor);
	}
	imagestring($image, $fond, 1, $height+30, $bz, $textcolor);
	imagejpeg($image);
}
?>

<?php
$graphdata = array(30, 20, 40, 50);
$label = "product";
$data = array(345, 378, 437, 509);
$width = 600;
$height = 200;
$scale = 2;
$font = 5;
$bg = array(255, 255, 255);
$text = array(123, 234, 255);
$grid = array(0, 0, 0);
$bar = array(245, 123, 23);
$bz = "company";
?>