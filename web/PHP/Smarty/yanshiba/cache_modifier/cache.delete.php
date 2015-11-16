<?php
/*
	删除缓存
	
*/
$id = trim($_GET['id']);

require('Smarty3/lib/Smarty.class.php');
require('./mysmarty.class.php');

$smarty = new Mysmarty();

$smarty->clearCache();	// 全部清除，危险，有notice
$smarty->clearCache('02.html');	// 删除某个模板的所有缓存
$smarty->clearCache('02.html', $id);	// 删除某个模板的某个缓存

echo "删除缓存成功！";

// 强制不缓存
$smarty->force_cache = true;	// 多用于调试的时候
?>