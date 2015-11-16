<?php
/*
	变量调节器：modifier
	| 格式化输出
	实际上，都可以在php中格式化，然后再输出
	
	开发原则：
	php负责取数据，显示操作，尽量前移
		mysql->php->模板->js
	
	比如时间戳:
	mysql存储可以有很多格式，2015-11-14，但是取用不方便，舍去了秒等
	php可以格式化，但是在页面不同地方，不同显示，转换困难
	直接在模板中，想怎么显示，就怎么用。
*/
$id = trim
$sql = "select id,name,reply_time from reply where id = '$id'";
/*
	{$v.reply_time|date_format:"%Y-%m-$d %H:%M:%S"} html中
*/

$smarty->assign('poem', 'This is a poem. AND I LIKE POEM');

/*
	{$poem|upper}<br>
	{$poem|lower}<br>
	{$poem|upper|lower}<br>
*/


?>