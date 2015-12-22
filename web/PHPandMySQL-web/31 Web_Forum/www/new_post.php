<?php
/*
	new_post.php
	对已有的帖子创建新文章
*/

include("include_fns.php");

$title = $_POST['title'];
$author = $_POST['author'];
$content = $_POST['content'];

if (isset($_GET['parent']))
{
	$parent = $_GET['parent'];
}
else
{
	$parent = $_POST['parent'];
}

if (!$area)
{
	$area = 1;
}

if (!$error)
{
	if (!$parent)
	{
		$parent = 0;
		if (!$title)
		{
			$title = 'New Post';
		}
	}
	else
	{
		$title = get_post_title($parent);
		
		// append Re:
		if (strstr($title, 'Re:') == false)
		{
			$title = "Re: ".$title;
		}
		
		$title = substr($title, 0, 100);
		
		$content = add_quoting(get_post_content($parent));
	}
}

do_html_header($title);

display_new_post_form($parent, $area, $title, $content, $author);

if ($error)
{
	echo "<p> Your message was not stored. </p>".
		"<p> Make sure you have filled in all fields and try again. </p>";
}

do_html_footer();

?>