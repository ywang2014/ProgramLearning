<?php
/*
	论坛首页
*/
include("include_fns.php");
session_start();

if (!isset($_SESSION['expanded']))
{
	$_SESSION['expanded'] = array();
}

if (isset($_GET['expand']))
{
	if ($_GET['expand'] == 'all')
	{
		expand_all($_SESSION['expanded']);
	}
	else
	{
		$_SESSION['expanded'][$_GET['expand']] = true;
	}
}

if (isset($_GET['collapse']))
{
	if ($_GET['collapse'] == 'all')
	{
		$_SESSION['expanded'] = array();
	}
	else
	{
		unset($_SESSION['expanded'][$_GET['collapse']]);
	}
}

do_html_header('Forum Posts');

display_index_toolbar();

display_tree($_SESSION['expanded']);

do_html_footer();

?>