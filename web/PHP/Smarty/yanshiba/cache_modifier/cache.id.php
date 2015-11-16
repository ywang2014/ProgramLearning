<?php
/*
	为商品模板设置缓存
	但是goods.php?id = N 缓存后，所有的都一样了，不适合
	
	改进：单模板多缓存  原理：多传入一个参数
	传入id，作为参数，id不同,则缓存不同的文件
	
	缓存id 多个条件，拼接成一个cache_id,当做参数传入即可！
	
	数据量无限增长：此时，写一个脚本，定期清除缓存！
	cache_map 只缓存数据，定期删除过期缓存，更好
	
*/

$id = trim($_GET['id']);

require('Smarty3/lib/Smarty.class.php');
require('./mysmarty.class.php');

$smarty = new Mysmarty();

// 开启缓存
$smarty->caching = true;

// 设置缓存生命周期
$smarty->cache_lifetime = 5;	// 时间5秒

// 设置缓存目录
$smarty->cache_dir = './cache';

if (!$smarty->isCached("02.html", $id))	// 名称一样
{
	$conn = mysql_connect('localhost', 'root', 'wang');
	@mysql_select_db('test', $conn);
	mysql_query('set names utf8');
	
	$sql = 'select id, name, reply_time from users where id = '.$id;
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
$smarty->display("02.html", $id);

?>