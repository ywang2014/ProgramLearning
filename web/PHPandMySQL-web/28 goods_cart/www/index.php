<?php
/*
	网站首页
*/
include('book_sc_fns.php');

session_start();

do_html_header('Welcome to Book-O-Rama');

echo "<p> Please choose a category: </p>";

$category_array = get_categories();

display_categories($category_array);

if (isset($_SESSION['admin_user']))
{
	display_button('admin.php', 'admin-menu', 'Admin Menu');
}

do_html_footer();

?>