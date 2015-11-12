<meta charset = "utf-8">

<?php
/*
	无限极分类
*/

function findson($arr, $id)
{
	$sons = array();
	
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$sons[] = $v;
		}
	}
	
	return $sons;
}

function subtree($arr, $id=0)
{
	// $sub被初始化，刷新了，递归不成功
	$subs = array();
	
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$subs[] = $v;
			subtree($arr, $v['id']);
		}
	}
	
	return $subs;
}


function subtree2($arr, &$subs, $id=0)
{
	// $sub被初始化，刷新了，递归不成功
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$subs[$v['id']] = $v;
			subtree2($arr, $subs, $v['id']);
		}
	}
	
	return $subs;
}


function subtree3($arr, $id=0)
{
	// $sub被初始化，刷新了，递归不成功
	static $subs = array();
	
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$subs[] = $v;
			subtree3($arr, $v['id']);
		}
	}
	
	return $subs;
}

function subtree4($arr, $id=0, $lev = 1)
{
	// $sub被初始化，刷新了，递归不成功
	static $subs = array();
	
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$v['lev'] = $lev;
			$subs[] = $v;
			subtree4($arr, $v['id'], $lev+1);
		}
	}
	
	return $subs;
}

function subtree5($arr, $id=0)
{
	// $sub被初始化，刷新了，递归不成功
	$subs = array();
	
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$subs[] = $v;
			$subs += subtree5($arr, $v['id']);
		}
	}
	
	return $subs;
}

function subtree6($arr, $id=0)
{
	$subs = array();
	foreach ($arr as $v)
	{
		if ($v['parent'] == $id)
		{
			$subs[$v['id']] = $v;
			$subs = array_merge($subs, subtree6($arr, $v['id']));
		}
	}
	return $subs;
}




$arr = array(
			array('id'=>1, 'name'=>'江苏' ,'parent'=>0),
			array('id'=>2, 'name'=>'海淀' ,'parent'=>8),
			array('id'=>3, 'name'=>'昌平' ,'parent'=>8),
			array('id'=>4, 'name'=>'朝阳' ,'parent'=>8),
			array('id'=>5, 'name'=>'无锡' ,'parent'=>1),
			array('id'=>6, 'name'=>'锡山' ,'parent'=>5),
			array('id'=>7, 'name'=>'中关村' ,'parent'=>2),
			array('id'=>8, 'name'=>'北京' ,'parent'=>0),
			);
			
//print_r(findson($arr, 0));
$subs = array();
print_r(subtree6($arr));

echo "<br> subtree4 <br>";
$tree = subtree4($arr);
foreach ($tree as $v)
{
	echo str_repeat('&nbsp;', $v['lev']).$v['name'].'<br>';
}

?>