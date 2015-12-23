<?php
/*
	new_post.php
*/
	include ('include_fns.php');

	$title = isset($_POST['title']) ? $_POST['title'] : '';
	$author = isset($_POST['author']) ? $_POST['author'] : '';
	$content = isset($_POST['content']) ? $_POST['content'] : '';
	
	$error = isset($error) ? $error : false;
	
	if(isset($_GET['parent'])) 
	{
		$parent = $_GET['parent'];
	} 
	else 
	{
		$parent = $_POST['parent'];
	}

	if(!isset($area)) 
	{
		$area = 1;
	}

	if(! $error) 
	{
		if(!$parent) 
		{
			$parent = 0;
			if(!$title) 
			{
				$title = 'New Post';
			}
		} 
		else 
		{
			// get post name
			$title = get_post_title($parent);

			// append Re:
			if(strstr($title, 'Re: ') == false) 
			{
				$title = 'Re: '.$title;
			}

			//make sure title will still fit in db
			$title = substr($title, 0, 100);

			//prepend a quoting pattern to the post you are replying to
			$content = add_quoting(get_post_message($parent));
		}
	}
	
	do_html_header($title);

	display_new_post_form($parent, $area, $title, $content, $author);

	if($error) 
	{
		echo "<p>Your message was not stored.</p>
           <p>Make sure you have filled in all fields and try again.</p>";
	}

	do_html_footer();
?>
