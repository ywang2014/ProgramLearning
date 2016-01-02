<?php
/*
	index.php -- 核心应用程序文件
	事件驱动方法
*/
session_start();

require_once("constants.php");
require_once("Product.php");
require_once("AmazonResultSet.php");
require_once("utilityfunctions.php");
require_once("bookdisplayfunctions.php");
require_once("cartfunctions.php");
require_once("categoryfunctions.php");

$external = array("action", "ASIN", "mode", "browseNode", "page", "search");

foreach ($external as $v)
{
	if (@$_REQUEST[$v])
	{
		$$v = $_REQUEST[$v];
	}
	else
	{
		$$v = '';
	}
	
	$$v = trim($$v);
}

// default value for global variables
if ($mode == '')
{
	$mode = "Books";
}

if ($browseNode == '')
{
	$browseNode = 53;	// 53 is bestselling non-fiction books
}

if ($page == '')
{
	$page = 1;	// First page there are 10 items per page 
}

if (!eregi('^[A-Z0-9]+$', $ASIN))
{
	// invalidate
	$ASIN = '';
}

if (!eregi('^[a-zA-Z]+$', $mode))
{
	$mode = 'Books';
}

$page = intval($page);
$browseNode = intval($browseNode);

$search = safeString($search);

if (!isset($_SESSION['cart']))
{
	session_register('cart');
	$_SESSION['cart'] = array();
}

// tasks that need to be done before the top bar is shown
switch ($action)
{
	case "addtocart":
		addToCart($_SESSION['cart'], $ASIN, $mode);
		break;
		
	case "deletefromcart":
		deleteFromCart($_SESSION['cart'], $ASIN);
		break;
		
	case "emptycart":
		$_SESSION['cart'] = array();
		break;
		
	default:
		echo "Undefined!";
		break;
}

require_once("topbar.php");

switch ($action)
{
	case "detail":
		showCategories($mode);
		showDetail($ASIN, $mode);
		break;
		
	case "addtocart":
	case "deletefromcart":
	case "emptycart":
	case "showcart":
		echo "<hr /> <h1> Your Shopping Cart </h1>";
		showCart($_SESSION['cart'], $mode);
		break;
		
	case "image":
		showCategories($mode);
		echo "<h1> Large Product Image </h1>";
		showImage($ASIN, $mode);
		break;
		
	case "search":
		showCategories($mode);
		echo "<h1> Search Result For ".$search." </h1>";
		showSearch($search, $page, $mode);
		break;
		
	case "browsenode":
	
	default:
		showCategories($mode);
		$category = getCategoryName($browseNode);
		if (!$category || ($category == 'Best Selling Books'))
		{
			echo "<h1> Current Best Sellers </h1>";
		}
		else
		{
			echo "<h1> Current Best Sellers in ".$category."</h1>";
		}
		showBrowseNode($browseNode, $page, $mode);
		break;
}

require_once("bottom.php");






?>