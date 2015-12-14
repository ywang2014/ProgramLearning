<?php
/*
	add_bm_form.php 提供一个添加书签的表单
	add_bms.php 添加书签到用户的个人页面
*/
require_once('bookmark_fns.php');
session_start();

$new_url = trim($_POST['new_url']);
do_html_header('Adding bookmarks');

try
{
	check_valid_user();
	
	if (!filled_out($_POST))
	{
		throw new Exception('Form not completely filled out.');
	}
	
	if ((strstr($new_url, "http://") === false) && (strstr($new_url, "https://") === false))
	{
		$new_url = "http://".$new_url;
	}
	//print_r($new_url);
	if (!(@fopen($new_url, 'r')))
	{
		throw new Exception('Not a valid URL');
	}
	
	add_bm($new_url);
	
	echo "Bookmark added successfully.";
	
	if ($url_array = get_user_urls($_SESSION['valid_user']))
	{
		display_user_urls($url_array);
	}
}
catch (Exception $e)
{
	echo $e->getMessage();
}

display_user_menu();
do_html_footer();

?>