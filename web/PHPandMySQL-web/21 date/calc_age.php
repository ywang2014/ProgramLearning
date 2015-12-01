<?php
/*
	calc_age.php 计算年龄
*/
$day = 18;
$month = 9;
$year = 1972;

$birthday_unix = mktime(0, 0, 0, $month, $day, $year);
$now = time();
$age_unix = $now - $birthday_unix;
$age = floor($age_unix / (365 * 24 * 3600));

echo 'Age is $age';

?>