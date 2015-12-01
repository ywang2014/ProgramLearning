<?php
/*
	mysql_calc_age.php 使用mysql计算年龄
*/
$day = 18;
$month = 9;
$year = 1972;

$bdayISO = date("c", mktime(0, 0, 0, $month, $day, $year));

$conn = mysql_connect('localhost', 'admin', 'admin');
$res = mysql_query("select datediff(now(), '$bdayISO')", $conn);
$age = mysql_fetch_array($res);

echo "Age is ".floor($age[0] / 365.25);


?>