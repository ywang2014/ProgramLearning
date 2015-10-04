<?php
// create short variable name
$DOCUMENT_ROOT = $_SERVER["DOCUMENT_ROOT"];

echo "<html>";

echo "<head> <title> Bob Auto Parts </title> </head>";

echo "<body>";
echo "<h1> Bob's Audo Parts - View Orders </h1>";
echo "<hr> <h2> Customer Orders </h2>";

@$fp = fopen("SDOCUMENT_ROOT/../orderFile/orders.txt", "rb");
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

echo "</body>";
echo "</html>";
?>
