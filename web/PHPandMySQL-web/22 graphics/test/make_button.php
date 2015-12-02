<?php
/*
	make_button.php 
*/
header('Content-type: charset=utf-8');

function getColor($im, $str)
{
	switch ($str)
	{
		case 'red':
			return imagecolorallocate($im, 243, 145, 169);	//#f391a9
		case 'green':
			return imagecolorallocate($im, 101, 194, 148);	//#65c294
		case 'blue':
			return imagecolorallocate($im, 0, 0, 169);	
			
		default:
			return imagecolorallocate($im, 19, 12, 14);	//#afdfe4	#130c0e
			
	}
}

/*print_r($_REQUEST);
exit; */
$button_text = trim($_REQUEST['b_text']);
$color_str = trim($_REQUEST['color']);

if (empty($button_text) || empty($color_str))
{
	echo "<script> alert('Content is empty!'); history.go(-1); </script>";
	exit;
}

$width = 150;
$height = 60;
$im = imagecreate($width, $height);

$color = getColor($im, $color_str);
//$red = imagecolorallocate($im, 200, 50, 0);
imagefill($im, 0, 0, $color);

$width_image_wo_margins = $width - (2*18);
$height_image_wo_margins = $height - (2*18);

$font_size = 33;

//putenv('GDFONTPATH_C:\WINDOWS\Fonts');
//$font_name = 'arial';

do
{
	$font_size--;
	
	$bbox = imagettfbbox($font_size, 0, 'arial.ttf', $button_text);
	
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
	
	imagettftext($im, $font_size, 0, $text_x, $text_y, $white, 'arial.ttf', $button_text);
	
	header('Content-type: image/png');
	imagepng($im);
}

imagedestroy($im);

?>