<?php
/*
	订单处理函数库
*/

// 
function process_card($card_details)
{
	// connect to payment gateway or use gpg to encrypt and mail or store in DB if you really want to 
	
	return true;
}

// 将用户订单插入数据库
function insert_order($order_details)
{
	extract($order_details);
	
	if ((!$ship_name) && (!$ship_address) && (!$ship_city) && (!$ship_state) && (!$ship_zip) && (!$ship_country))
	{
		// ? 很奇怪的逻辑
		$ship_name = $name;
		$ship_address = $address;
		$ship_city = $city;
		$ship_state = $state;
		$ship_zip = $zip;
		$ship_country = $country;
	}
	
	$conn = db_connect();
	// $conn->autocommit(FALSE);
	
	$sql = "select customerid from customers where name = '$name' and address = '$address' and city = '$city'".
			" and state = '$state' and zip = '$zip' and country = '$country'";
	$result = mysql_query($sql, $conn);
	$nums = mysql_num_rows($result);
	if ($nums > 0)
	{
		$customer = mysql_fetch_array($result);
		$customerid = $customer['customerid'];
	}
	else
	{
		$sql = "insert into customers (name, address, city, state, zip, country)".
			" values ('$name', '$address', '$city', '$state', '$zip', '$country')";
		$result = mysql_query($sql);
		if (!$result)
		{
			return false;
		}
		// 此句应该在此处，不应该在下一个右花括号外面
		$customerid = mysql_insert_id();
	}
	
	$date = date("Y-m-d");
	
	$sql = "insert into orders values ('$customerid', '".$_SESSION['total_price']."', '$date', '".PARTIAL."', '$ship_name', ".
			"'$ship_address', '$ship_city', '$ship_state', '$ship_zip', '$ship_country')";
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	$sql = "select orderid from orders where customerid = '$customerid' and amount > (".$_SESSION['total_price']." - 0.001) ".
			"and amount < (".$_SESSION['total_price']." + 0.001) and date = '$date' and order_status = ".PARTIAL." and ship_name = '$ship_name' ".
			"and ship_address = '$ship_address' and ship_city = '$ship_city' and ship_state = '$ship_state' and ship_zip = '$ship_zip' ".
			"and ship_country = '$ship_country'";
	$result = mysql_query($sql, $conn);
	$nums = mysql_num_rows($result);
	if ($nums > 0)
	{
		$order = mysql_fetch_array($result);
		$orderid = $order['orderid'];
	}
	else
	{
		return false;
	}
	
	// insert each book
	foreach ($_SESSION['cart'] as $isbn => $quantity)
	{
		$detail = get_book_details($isbn);
		$sql = "delete from order_items where orderid = '$orderid' and isbn = '$isbn'";
		$result = mysql_query($sql, $conn);
		$sql = "insert into order_items values ('$orderid', '$isbn', '".$detail['price']."', '$quantity')";
		$result = mysql_query($sql, $conn);
		if (!$result)
		{
			return false;
		}
	}
	
	//$conn->commit();
	//$conn->autocommit(TRUE);
	
	return $orderid
	
}


?>