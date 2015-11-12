<?php

/*
	递归与迭代的区别
*/

/*
	n 为整数，且大于0.
*/
function recur_sum($n)
{
	if ($n < 0)
	{
		return 0 - recur_sum(-$n);
	}
	if ($n == 0)
	{
		return 0;
	}
	
	return recur_sum($n - 1) + $n;
}

function iter_sum($n)
{
	$sum = 0;
	for ($i = 0; $i <= $n; $i++)
	{
		$sum += $i;
	}
	
	return $sum;
}

echo recur_sum(100);


/**
	迭代创建级联目录
*/
function mk_dir($path)
{
	$arr = array();
	
	while (!is_dir($path))
	{
		// 不是目录的意思：即当前文件夹中，没有该目录，需要创建的，因此都压入数组中！
		array_push($arr, $path);
		
		$path = dirname($path);
	}
	
	print_r($arr);
	
	if (empty($arr))
	{
		// 说明有该目录了，不需要创建
		return true;
	}
	
	foreach ($arr as $v)
	{
		mkdir($v)
	}
	/*
	等价于：
	while (count($arr))
	{
		mkdir(array_pop($arr));
	}
	*/
	return true;
}
?>