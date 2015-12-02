<?php
/*
	simplegraph.php	简单图形
*/
$height  = 200;
$width = 200;

$im = imagecreatetruecolor($width, $height);
$white = imagecolorallocate($im, 255, 255, 255);
$blue = imagecolorallocate($im, 0, 0, 64);

imagefill($im, 0, 0, $blue);
imageline($im, 0, 0, $width, $height, $white);
imagestring($im, 5, 50, 150, 'HelloWord', $white);	// 只能是 font-size 1-5

Header('Content-type: image/png');
imagepng($im);

imagedestroy($im);

?>