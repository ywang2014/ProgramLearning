<?php
/*
	控制购物车
*/
include('book_sc_fns.php');

session_start();

//@$new = $_GET['new'];
//if ($new)
if (isset($_GET['new']))
{
	$new = $_GET['new'];
	
	if (!isset($_SESSION['cart']))
	{
		$_SESSION['cart'] = array();
		$_SESSION['items'] = 0;
		$_SESSION['total_price'] = 0.00;
	}
	
	if (isset($_SESSION['cart'][$new]))
	{
		$_SESSION['cart'][$new]++;
	}
	else
	{
		$_SESSION['cart'][$new] = 1;
	}
	
	$_SESSION['total_price'] = calculate_price($_SESSION['cart']);
	$_SESSION['item'] = calculate_items($_SESSION['cart']);
	
	$details = get_book_details($new);
	if ($details['catid'])
	{
		$target = "show_cat.php?catid=".$details['catid'];
	}
}

if (isset($_POST['save']))
{
	foreach ($_SESSION['cart'] as $isbn => $qty)
	{
		if ($_POST['$isbn'] == '0')
		{
			unset($_SESSION['cart'][$isbn]);
		}
		else
		{
			$_SESSION['cart'][$isbn] = $_POST[$isbn];
		}
	}
	
	$_SESSION['total_price'] = calculate_price($_SESSION['cart']);
	$_SESSION['items'] = calculate_items($_SESSION['cart']);
}

do_html_header('Your shopping cart');

if (($_SESSION['cart']) && (array_count_values($_SESSION['cart'])))
{
	display_carts($_SESSION['cart']);
}
else
{
	echo "<p> There are no items in your cart </p> <hr>";
}

//$target = "index.php";
// if ($new)
if (! isset($target))
{
	$target = "index.php";
}

display_button($target, 'continue-shopping', "Continue Shopping");

/*
	use this if SSL is set up
	$path = $_SERVER['PHP_SELF'];
	$server = $_SERVER['SERVER_NAME'];
	$path = str_replace('show_cart.php', '', $path);	// str_replace(A, B, C) 把C中的A替换为B
	display_button("http://".$server.$path."checkout.php", 'go-to-checkout', 'Go To Checkout');
	
	if not SSL use below code
*/
display_button("checkout.php", "go-to-checkout", "Go To Checkout");

do_html_footer();

?>