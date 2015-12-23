<?php
/*
	store_new_post.php
*/
	include ('include_fns.php');
	
	if($id = store_new_post($_POST)) 
	{
		include ('index.php');
	} 
	else  
	{
		$error = true;
		include ('new_forum.php');
	}

?>
