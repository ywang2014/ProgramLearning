<?php
/*
	output_fns.php 
	显示HTML
*/

// 建立树形结构根节点
function display_tree($expanded, $row = 0, $start = 0)
{
	global $table_width;
	
	echo "<table width = \"".$table_width."\">";
	
	if ($start > 0)	// 直接使用sublist作为参数
	{
		$sublist = true;
	}
	else
	{
		$sublist = false;
	}
	
	$tree = new treenode($start, '', '', '', 1, true, -1, $expanded, $sublist);
	$tree->display($row, $sublist);
	
	echo "</table>";
}





?>