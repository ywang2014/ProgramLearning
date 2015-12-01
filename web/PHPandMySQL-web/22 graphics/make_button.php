<?php
/*
	make_button.php 
*/
$button_text = trim($_REQUEST['b_text']);
$color = trim($_REQUEST['color']);

if (empty($button_text) || empty($color))
{
	echo "<script> alert('请设置按钮格式，不能为空！'); history.go(-1); </script>";
	exit;
}

$im = imagecreatefrompng($color.'-button.png');

$width = imagesx($im);
$height = imagesy($im);

$width_image_wo_margins = $width - (2*18);
$height_image_wo_margins = $height - (2*18);

$font_size = 33;

putenv('GDFONTPATH_C:\WINDOWS\Fonts');
$font_name = 'arial';

do
{
	$font_size--;
	
	$bbox = imagettfbbox($font_size, 0, $font_name, $button_text);
	
	$right_text = $bbox[2];
	$left_text = $bbox[0];
	$width_text = $right_text - $left_text;
	$height_text = abs($bbox[7] - $bbox[1]);
	
}while ($font_size > 8 && ($height_text > $height_image_wo_margins || $width_text > $width_image_wo_margins));

if ($height_text > $height_image_wo_margins || $width_text > $width_image_wo_margins)
{
	echo "Text given will not fit on button. <br>";
}
else
{
	$text_x = $width/2.0 - $width_text/2.0;
	$text_y = $height/2.0 - $height_text/2.0;
	
	if ($left_text < 0)
	{
		$text_x += abs($left_text);
	}
	
	$above_line_text = abs($bbox[7]);	// how far above the baseline
	$text_y += $above_line_text;	// add baseline factor
	
	$text_y -= 2; 	// adjustment factor for shape of our template
	
	$white = imagecolorallocate($im, 255, 255, 255);
	
	imagettftext($im, $font_size, 0, $text_x, $text_y, $white, $font_name, $button_text);
	
	header('Content-type: image/png');
	imagepng($im);
}

imagedestroy($im);

?>