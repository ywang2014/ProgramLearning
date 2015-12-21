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

// 显示邮件列表信息
function display_information($listid)
{
	if (!$listid)
	{
		return false;
	}
	
	$info = load_list_info($listid);
	if ($info)
	{
		echo "<h2>".pretty($info['listname'])."</h2>".
				"<p>".pretty($info['blurb'])."</p>".
				"<p> Number of subscribers: ".$info['subscribers']."</p>".
				"<p> Number of messages in archive: ".$info['archive']."</p>";
	}
}

// 显示文件上传表单
function display_mail_form($email, $listid = 0)
{
	global $table_width;
	$list = get_all_lists();
	$lists = sizeof($list);
	?>
	<table cellpadding = "4" cellspacing = "0" border = "0" width = "<?php echo $table_width; ?>" >
		<form enctype = "multipart/form-data" action = "upload.php" method = "post">
			<tr>
				<td bgcolor = "#cccccc"> List: </td>
				<td bgcolor = "#cccccc"> 
					<select name = "list">
					<? php 
						for ($i = 0; $i < $lists; $i++)
						{
							echo "<option value = \"".$list[$i][0]."\" ";
							if ($listid == $list[$i][0])
							{
								echo "selected ";
							}
							echo ">".$list[$i][1]."</option>\n";
						}
					?>
					</select>
				</td>
			</tr>
			<tr>
				<td bgcolor = "#ccc"> Subject: </td>
				<td bgcolor = "#ccc"> 
					<input type = "text" name = "subject" value = "<?php echo $subject; ?>" size = "60" /> 
				</td>
			</tr>
			<tr>
				<td bgcolor = "#ccc"> Text Version: </td>
				<td bgcolor = "#ccc">
					<input type = "file" name = "userfile[]" size = "60" />
				</td>
			</tr>
			<tr>
				<td bgcolor = "#ccc"> HTML Version: </td>
				<td bgcolor = "#ccc">
					<input type = "file" name = "userfile[]" size = "60" />
				</td>
			</tr>	
			<tr>
				<td bgcolor = "#ccc"> Images: (optional) </td>
			</tr>
			
			<?php 
				$max_images = 10;
				for ($i = 0; $i < 10; $i++)
				{
					echo "<tr> <td bgcolor = \"#ccc\" >Image ".($i + 1)." </td> ".
						"<td bgcolor = \"#ccc\"> ".
						"<input type = \"file\" name = \"userfile[]\" size = \"60\" > ".
						"</td> </tr>";
				}
			?>
			<tr>
				<td bgcolor = "#ccc" colspan = "2" align = "center">
					<input type = "hidden" name = "max_images" value = "<?php echo $max_images; ?>" />
					<input type = "hidden" name = "listid" value = "<?php echo $listid; ?>" />
					<?php
						display_form_button('upload_files');
					?>
				</td>
			</tr>
		</form>
	</table>
<?php 
}


?>