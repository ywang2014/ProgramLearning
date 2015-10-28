<?php
/*
* 时间函数集
*/

// 设置当地时区 - 上海
date_default_timezone_set("Asia/Shanghai");

// 显示时分秒
function show_His_Time()
{
	echo date("H:i:s");		// H 24h
}

function show_his_Time()
{
	echo date("h:i:sa");	// h 12h   a am/pm
}

// 显示年月日
function show_Ymd_time()
{
	echo date("Y-m-d");
}

// 显示全部时间
function showWholeTime()
{
	echo date("Y-m-d H:i:s");
}

// 显示星期
function show_week()
{
	echo date("l");
}

function showSetTime(hour, minute, second, month, day, year)
{
	$time = mktime(hour, minute, second, month, day, year);
	echo date("Y-m-d H:i:s", $d);
}

?>