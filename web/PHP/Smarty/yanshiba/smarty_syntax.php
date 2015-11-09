<?php
/*
	模板中逻辑判断：
	{if $smarty.get.today == 0 || $smarty.get.today == 7}
	周日
	{else if $smarty.get.today == 6}
	周六
	{else}
	工作日
	{/if}  //成对出现
	
	逻辑处理尽量放在php中，模板中使用少，但是必须的时候，代码会更加简单
*/

/*
	循环结构：
	{for $i = $start to $end}	// 自能从$start到$end结束，自动加1，只能加
		{$i}&nbsp; {if $i % 3 == 0}<br>{/if}
	{/for}
	
	{for $i = $start to 100 step = 2}
		{$i}&nbsp; {if $i@iteration % 3 == 0}<br>{/if}
	{/for}
		循环{$i@total}次数
		$i@first	// 第一次循环
		$i@last		// 最后一次循环

*/

?>