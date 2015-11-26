<?php
/*
	自动验证功能
	
	首先定义验证规则：
	0 有则验证
	1 必须有的
	2 有且非空，则验证，满足一定条件
*/

/*
	定义需要验证的字段，封装在数组中
	args:
		1.字段名
		2.验证规则
		3.错误的时候，报错信息
		4.验证规则 
		5.辅助的参数
*/
$valid = array(
			array('username', 1, '用户名不能为空', 'required'),
			array('bid', 1, '博客id必须为正整形值', 'number'),
			array('gender', 0, '性别只能是男/女', 'in', '男/女'),
			array('age', 2, '年龄必须合理', 'between', '18,120'),
			array('introduce', 2, '自我介绍不能太短20-100字符', 'length', '20,100')
			);
			
/*
	验证函数
*/

function auto_check($arr, $valid, $error)
{
	if (empty($valid))
	{
		// 验证数组为空，即不需要验证
		return true;
	}
	
	foreach ($valid as $k=>$v)
	{
		switch ($v[1])
		{
			case 1: // 为1，说明必须有，非空
				if (!isset($arr[$v[0]]))
				{
					// 没有定义，或者为空，肯定错误
					$error = $v[2];
					return false;
				}
				
				if (!check($arr[$v[0]], $v[3]))
				{
					$error = $v[2];
					return false;
				}
				break;
				
			case 0:	// 若有，则检查
				if (isset($arr[$v[0]]))
				{
					if (!check($arr[$v[0]], $v[3], $v[4]))
					{
						$error = $v[2];
						return false;
					}
				}
				break;
				
			case 2:
				if (isset($arr[$v[0]]) && (!empty($arr[$v[0]])))
				{
					if (!check($arr[$v[0]], $v[3], $v[4]))
					{
						$error = $v[2];
						return false;
					}
				}
				break;
		}
	}
	
	return true;
}

function check($value, $rule='', $parm = '')
{
	switch ($rule)
	{
		case 'required':
			return !empty($value);
			
		case 'number':
			return is_numeric($value);
			
		case 'in':
			$tmp = explode(',', $parm);
			return in_array($value, $tmp);
			
		case 'between':
			list($min, $max) = explode(',', $parm);
			return $value >= $min && $value <= $max;
			
		case 'length':
			list($min, $max) = explode(',', $parm);
			return strlen($value) >= $main && strlen($value) <= $max;
			
		default:	// 其他规则没有定义，直接错误
			return false;
	}
}
?>