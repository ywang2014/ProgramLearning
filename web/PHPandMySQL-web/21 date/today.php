<?php
/*
	打印今日时间
*/
print_r(getdate());

/*
	检查日期是否合法
*/
echo checkdate(2, 29, 2008); // 月、日、年

/*
	格式化时间
*/
echo strftime('%A<br>');
echo strftime('%x<br>');
echo strftime('%c<br>');
echo strftime('%Y<br>');

?>