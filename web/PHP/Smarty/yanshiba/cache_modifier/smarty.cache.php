<?php
/*
	通过缓存，使得访问数据库的时间，大大减小，提高性能
	
	显示时间被缓存，股票信息，随机广告等被缓存是错误的
	
	smarty局部不缓存
	1.在标签中控制 {$value nocache} 原理：
	<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vals['time']->value, "%Y-%m-%d %H:%M:%S"); ?>
	不缓存的部分，是php动态解释的，缓存部分，直接被写死了！
	
	2.控制一片标签，不缓存
	{nocache} <p> {$value} <p> {/nocache}
	
	3.在php赋值中，直接设置不缓存
	$smarty->assign('time2', $time, true);	// 第三个参数是nocache，为true说明不缓存
	
	4.insert 原理：调用函数，取得返回值 echo insert_welcome();
	<p> {insert name = "welcome"} </p>
	传入参数
	<p> {insert name = "welcome" age = "28"} </p>
	格式：{insert name = "xxx" param = "value"}
	php页	创建一个函数insert_xxx($param)即可实现不缓存
*/

require('Smarty3/lib/Smarty.class.php');
require('./mysmarty.class.php');

$smarty = new Mysmarty();

// 开启缓存
$smarty->caching = true;

// 设置缓存生命周期
$smarty->cache_lifetime = 5;	// 时间5秒

// 设置缓存目录
$smarty->cache_dir = './cache';

if (!$smarty->isCached("01.html"))	// 名称一样
{
	$conn = mysql_connect('localhost', 'root', 'wang');
	@mysql_select_db('test', $conn);
	mysql_query('set names utf8');
	
	$sql = 'select id, name, reply_time from users limit 5';
	$rs = mysql_query($sql, $conn);
	
	$users = array();
	while ($row = mysql_fetch_array($rs))
	{
		$users[] = $row;
	}
	
	echo "我走的是数据库";
	$smarty->assign('users', $users);
}
// 不缓存的值，一定要放在外面，保证能够从php获得值，放在if里面，则根本找不到这些值！！！！

$time = time();
$smarty->assign('time1', $time);
$smarty->assign('time2', $time, true);	// 第三个参数是nocache，为true说明不缓存

function insert_welcome()
{
	return "你好".rand(100,999);
}

function insert_welcome($param)
{
	return "你好".rand(100,999).'你的年龄是'.$param['age'];
}

function insert_welcome($param)
{
	return "你好".$param['name'];
}

$smarty->display("01.html");
?>