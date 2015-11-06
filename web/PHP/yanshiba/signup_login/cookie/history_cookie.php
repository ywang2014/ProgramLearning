<?php
/*
	浏览历史
*/

//echo $_SERVER['REQUEST_URI'];
uri = $_SERVER['REQUEST_URI'];
// setcookie('history', array($uri)); cookie只能存储字符串
if (!isset($_COOKIE['history']))
{
	$his[] = $uri;
	implode('|', $his);
	setcookie('history', $his);
}
else
{
	$his = explode('|', $_CCOKIE['history']);
	// $his[] = $uri;
	array_unshift($his, $url);	// 最新的浏览放在上面
	
	$his = array_unique($his);	// 去掉重复的记录
	
	if (count($his) > 10)	// 只记录10条历史记录
	{
		array_pop($his);
	}
	
	implode('|', $his);
	setcookie('history', $his);
}
setcookie('history', $uri);

$id = isset($_GET['id']) ? $_GET['id'] : 0;

?>

<P>
	<a href = "counter_advance.php?id=<?php echo $id-1;?>">上一页</a>
<p>
<P>
	<a href = "counter_advance.php?id=<?php echo $id+1;?>">下一页</a>
<p>

<ul>
	<li>浏览历史</li>
	<?php
		foreach ($this as $v)
		{ ?>
		<li> <?php echo $v; ?> </li>
		
	<?php } ?>
</ul>