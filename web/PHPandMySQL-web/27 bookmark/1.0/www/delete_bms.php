<?php
/*
	删除书签 delete_bms.php
*/
require_once('bookmark_fns.php');
session_start();

$del_me = $_POST['del_me'];
$username = $_SESSION['valid_user'];

do_html_header('Deleting Bookmarks');
check_valid_user();

if (!filled_out($_POST))
{
	echo '<p> You have not chosen any bookmarks to delete. <br> Please try again. </p>';
	display_user_menu();
	do_html_footer();
	exit;
}
else
{
	if (count($del_me) > 0)
	{
		foreach ($del_me as $url)
		{
			if (delete_bm($username, $url))
			{
				echo "Deleted ".htmlspecialchars($url)."<br>";
			}
			else
			{
				echo "Could not delete ".htmlspecialchars($url)."<br>";
			}
		}
	}
	else
	{
		echo "No bookmarks selected for deletion";
	}
}

if ($url_array = get_user_urls($username))
{
	display_user_urls($url_array);
}

display_user_menu();

do_html_footer();

?>