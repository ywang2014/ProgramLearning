<?php
/*
	数据库交互的函数库
*/

function get_categories()
{
	$conn = db_connect();

	$sql = "select catid, catname from categories";
	$result = @mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}

	$cat_nums = mysql_num_rows($result, $conn);
	if ($cat_nums == 0)
	{
		return false;
	}

	$rows = getAll($result);

	return $rows;
}

function get_category_name($catid)
{
	$conn = db_connect();
	
	$sql = "select catname from categories where catid = '$catid'";
	$result = mysql_query($sql);
	if (!$result)
	{
		return false;
	}
	
	$nums_cat = mysql_num_rows($result);
	if ($nums_cat == 0)
	{
		return false;
	}
	
	$row = mysql_fetch_array($result);
	return $row['catname'];
}

// 计算购物车中物品总价
function calculate_price($cart)
{
	$price = 0.0;
	if (is_array($cart))
	{
		$conn = db_connect();
		foreach ($cart as $isbn => $qty)
		{
			$sql = "select price from books where isbn = '$isbn'";
			$result = mysql_query($sql, $conn);
			if ($result)
			{
				$row = mysql_fetch_array($result);
				$item_price = $row['item_price'];
				$price += $item_price * $qty;
			}
		}
	}
	return $price;
}

// 计算购物车物品总数
function calculate_items($cart)
{
	$items = 0;
	if (is_array($cart))
	{
		foreach ($cart as $isbn => $qty)
		{
			$items += $qty;
		}
	}
	return $qty;
}



?>