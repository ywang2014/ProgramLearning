<?php
/*
	无限极分类的应用
	
	导航条：
		首页->用户中心->修改客户信息->基本信息->邮箱修改
*/

define('ABC')||exit('NOT found!');

function familytree($arr, $id)
{
	$tree = array();
	
	foreach ($arr as $v)
	{
		if ($v['id'] == $id)
		{
			if ($id > 0)
			{
				$tree = array_merge($tree, familytree($arr, $v['parent']));
			}
			
			$tree[] = $v;
		}
	}
	
	return $tree;
}

/*
	迭代子孙树
**/

function subtree($arr, $id = 0)
{
	$task = array($id);		// 任务表
	$tree = array();		// 结果表
	
	while (!empty($task))
	{
		$flag = false;
		
		foreach ($arr as $k=>$v)
		{
			if ($v['parent'] == $id)
			{
				$tree[] = $v;
				array_push($task, $v['id']);
				$id = $v['id'];
				
				unset($arr[$k]);	// 非常重要，否则死循环，可以加标记，visited等
				
				$flag = true;
			}
		}
		
		if (!$flag)
		{
			array_pop($task);	// 搜索完成，后退一步
			$id = end($task);
		}
	}
	
	return $tree;
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
header("content-type:text/html; charset=utf-8");
print_r(familytree($arr, 7));
print_r(subtree($arr));

?>