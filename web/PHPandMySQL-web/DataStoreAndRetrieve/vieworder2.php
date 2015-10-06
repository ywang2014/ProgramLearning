<?php
// create short variable name
$DOCUMENT_ROOT = $_SERVER["DOCUMENT_ROOT"];

echo "<html>";

echo "<head> <title> Bob Auto Parts </title> </head>";

echo "<body>";
echo "<h1> Bob's Audo Parts - View Orders </h1>";
echo "<hr> <h2> Customer Orders </h2>";

@$fp = fopen("SDOCUMENT_ROOT/../orderFile/orders.txt", "rb");
flock($fp, LOCK_SH);
if (!$fp)
{
	echo "<p style = 'color: red'> <strong> NO orders pending. Please try again later. </strong> </p>";
	exit();
}

while (!feof($fp))
{
	$order = fgets($fp, 1000);
	echo $order."<br>";
}

// 读取文件指针当前位置
echo "Final positon of the file pointer is ".(ftell($fp));
echo "<br>";
// 将文件指针回复到文件的开始
rewind($fp);
echo "After rewind, the position is ".(ftell($fp));
echo "<br>";
flock($fp, LOCK_UN);
fclose($fp);

echo "</body>";
echo "</html>";
?>
