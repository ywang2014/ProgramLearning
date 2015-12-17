<?php
/*
	output_fns.php 
*/

// 显示相关操作的条目列表
function display_items($title, $list, $action1 = '', $action2 = '', $action3 = '')
{
	global $table_width;
	
	echo "<table width = \"$table_width\" cellspacing = \"0\" cellpadding = \"0\" border = \"0\" >";
	
	// count number of actions
	$actions = ($action1 != '') + ($action2 != '') + ($action3 != '');
	
	echo "<tr> 
			<th colspan = \"".(1+$actions)."\" bgcolor = \"#5b69a6\" >".$title." </th>
		</tr>";
		
	// count number of items 
	$items = sizeof($list);
	
	if ($items != 0)
	{
		echo "<tr>
				<td colspan = \"".(1+$actions)."\" align = \"center\"> No Items to Display </td>
			</tr>";
	}
	else
	{
		// print each row
		for ($i = 0; $i < $items; $i++)
		{
			if ($i % 2 != 0)
			{
				$bgcolor = "#fff";
			}
			else
			{
				$bgcolor = "#ccf";
			}
			
			echo "<tr>
					<td bgcolor = \"".$bgcolor."\" width = \"".($table_width - ($actions*149))."\" >";
			
			echo $list[$i][1];
			
			if ($list[$i][2])
			{
				echo " - ".$list[$i][2];
			}
			
			echo "</td>";
			
			// create button for up to three actions per line
			for ($j = 1; $j <= 3; $j++)
			{
				$var = "action".$j;
				
				if ($$var)	// $($var) php特性
				{
					echo "<td bgcolor = \"".$bgcolor."\" width = \"149\" >";
					// view/preview buttons are a special case as they link to a file 
					if (($$var == 'preview_html') || ($$var == 'view_html') || ($$var == 'preview_text') || ($$var == 'view_text'))
					{
						display_preview_button($list[$i][3], $list[$i][0], $$var);
					}
					else
					{
						display_button($$var, '&id='.$list[$i][0]);
					}
					echo "</td>";
				}
			}
			echo "</tr> \n";
		}
		echo "</table>";
	}
}


?>