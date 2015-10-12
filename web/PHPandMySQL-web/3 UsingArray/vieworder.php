<?php
// vieworder.php 显示订单内容

// create a short variable name 
$DOCUMENT_ROOT =$_SERVER["DOCUMENT_ROOT"];

// file() 函数将整个文件再入一个数组，文件的每一行对应数组的一个元素
$orders = file("$DOCUMENT_ROOT/../orders/orders.txt");

$number_of_order = count($orders);
if ($number_of_order == 0)
{
	echo "<p> <strong> No orders pending. Please try again later. </strong> </p>"
}

for ($i = 0; $i < $number_of_order; $i++)
{
	echo $orders[$i]."<br>";
}

?>