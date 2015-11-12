<?php
/**
	基本函数库
*/

/*
	递归转义数组
*/
function _add_slashes($arr)
{
	foreach ($arr as $k=>$v)
	{
		if (is_string($v))
		{
			$arr[$k] = addslashes($v);
		}
		else if (is_array($v))
		{
			$arr[$k] = _add_slashes($v);
		}	
	}
	return $arr;
} 

?>