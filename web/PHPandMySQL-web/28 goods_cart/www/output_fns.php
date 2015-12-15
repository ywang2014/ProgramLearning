<?php
/*
	输出函数库，显示html
*/

// 显示目录链接
function display_categories($cats)
{
	if (!is_array($cats))
	{
		echo "<p> No categories currently available </p>";
		return ;
	}
	
	echo "<ul>";
	foreach ($cats as $cat)
	{
		$url = "show_cat.php?catid=".$cat['catid'];
		$title = $cat['catname'];
		echo "<li>";
		do_html_url($url, $title);
		echo "</li>";
	}
	echo "</ul>";
	echo "<hr>";
}

// 打印购物车内容
function display_cart($cart, $change = true, $images = 1)
{
	?>
	<table border = "0" width = "100%" cellpadding = "0">
		<form action = "show_cart.php" method = "post">
			<tr>
				<th colspan = "<?php echo (1 + $images); ?>" bgcolor = "#ccc"> Item </th>
				<th bgcolor = "#ccc"> Price </th>
				<th bgcolor = "#ccc"> Quantity </th>
				<th bgcolor = "#ccc"> Total </th>
			</tr>
			
			<?php
			foreach ($cart as $isbn => $qty)
			{
				$book = get_book_details($isbn);
				echo "<tr>";
				if ($images == 1)
				{
					// 有照片
					echo "<td align = \"left\">";
					if (file_exists("images/".$isbn.".jpg"))
					{
						$size = GetImageSize("images/".$isbn.".jpg");
						if ($size[0] > 0 && $size[1] > 0)
						{
							echo "<img src = \"images/".$isbn.".jpg\" style = \"border: 1px solid black;\" width = \"".
							($size[0]/3)."\" height = \"".($size[1]/3)."\" />";
						}
					}
					else
					{
						echo "&nbsp;";
					}
					echo "</td>";
				}
				
				?>
				<td align = "left"> 
					<a href = "show_book.php?isbn=<?php echo $isbn; ?>" > <?php echo $book['title']; ?> </a>
					by <?php echo $book['author']; ?>
				</td>
				<td align = "center" > $<?php echo number_format($book['price'], 2); ?> </td>
				<td align = "center" >
				<?php 
				if ($change == true)
				{
					echo "<input type = \"text\" name = \"".$isbn."\" value = \"".$qty."\" size = \"3\" >";
				}
				else
				{
					echo $qty;
				}
				
				echo "</td> <td align = \"center\" > \$".number_format($book['price'] * $qty, 2)."</td> </tr> \n";
			}
			?>
			<tr>
				<th colspan = "<?php echo (2 + $images); ?>" bgcolor = "#ccc" > &nbsp; </td>
				<th align = "center" bgcolor = "#ccc"> <?php echo $_SESSION['items']; ?> </th>
				<th align = "center" bgcolor = "#ccc"> <?php echo number_format($_SESSION['total_price'], 2); ?> </th>
			</tr>
			<?php
			// display save change button
			if ($change == true)
			{	?>
				<tr>
					<td colspan = "<?php echo (2 + $images); ?>" > &nbsp; </td>
					<td align = "center" >
						<input type = "hidden" name = "save" value = "true" />
						<input type = "image" src = "images/save-changes.gif" border = "0" alt = "Save Change" />
					</td>
					<td> &nbsp; </td>
				</tr>
				<?php 
			}
	echo "</form> </table>";
	
}

?>