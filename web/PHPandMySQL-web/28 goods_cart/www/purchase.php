<?php
/*
	保存用户订单详细信息，获取付款细节
*/
include("book_sc_fns.php");

session_start();

do_html_header("Checkout");

$name = $_POST['name'];
$address = $_POST['address'];
$city = $_POST['city'];
$zip = $_POST['zip'];
$country = $_POST['country'];

if (($_SESSION['cart']) && ($name) && ($address) && ($city) && ($zip) && ($country))
{
	if (insert_order($_POST) != false)
	{
		display_cart($_SESSION['cart'], false, 0);
		
		display_shipping(calculate_shipping_cost());
		
		// get credit card details
		display_card_form($name);
		
		display_button("show_cart.php", "continue-shopping", "Continue Shopping");
	}
	else
	{
		echo "<p> Could not store data, please try again.</p> <hr>";
		display_button("checkout.php", "back", "Back");
	}
	
	do_html_footer();
}


?>