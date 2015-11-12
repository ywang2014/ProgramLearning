<?php
/*
	递归转义数组
	
	array_map($_GET, 'rec');
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

$arr = array('a"b', array("c'd", array('e"f')));

print_r(_add_slashes($arr));
print_r($arr);

?>