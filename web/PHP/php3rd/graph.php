<?php
Header("Content-type: image/jpeg");	// 告诉浏览器正在得到一个图像和该图像的类型
$imageHandle = imagecreate(200, 200);	// 创建了一个200*200像素的空白画布
$maroonHandle = imageColorAllocate($imageHandle, 100, 0, 0);	// 创建画图时使用的颜色
$whiteHandle = imageColorAllocate($imageHandle, 255, 255, 255);
?>

<?php
// 将画布涂成白色
imagefilledrectangle($imageHandle, 0, 0, 200, 200, $whiteHandle);
imagerectangle($imageHandle, 10, 10, 190, 190, $maroonHandle);
imagefilledrectangle($imageHandle, 50, 50, 150, 150, $maroonHandle);
?>

<?php
// 输出图形
imagejpeg($imageHandle);
?>

<?php
// 清除内存中的图像
imagedestroy($imageHandle);
?>