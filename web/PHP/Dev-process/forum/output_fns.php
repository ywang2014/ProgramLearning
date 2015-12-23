<?php
/*
	output_fns.php 
*/

$table_width = '580';

function reformat_date($datetime)
{
	return date("H:i:s Y/m/d", $datetime);
}

function display_tree($expanded, $row = 0, $start = 0)
{
	// display the tree view of conversations
	global $table_width;
	
	echo "<table width=\"".$table_width."\">";

	// see if we are displaying the whole list or a sublist
	if($start > 0) 
	{
		$sublist = true;
	} 
	else 
	{
		$sublist = false;
	}

	// construct tree structure to represent conversation summary
	$tree = new treenode($start, '', '', '', 1, true, -1, $expanded, $sublist);

	// tell tree to display itself
	$tree->display($row, $sublist);

	echo "</table>";
}

function do_html_header($title = '') 
{
	include_once("../static/template/forum_header.html");
	
	if ($title)
	{
		echo "<div style = \"width: 100%; height: 300px; background: url(./images/bg2.jpg) no-repeat; border: 1px solid #00f; 
				border-radius:20px; text-align: center; 
				filter: alpha(opacity = 50, finishOpacity=0, style=2); opacity: 1;\"> 
					<div style = \"width: 150px; height:50px; margin: 120px auto; color: #3C7ADD; line-height: 50px;
						background:rgba(60, 60, 250, 0.5)!important; \"> <h1 > $title </h1> </div>
				</div>";
	}
}

function do_html_footer() 
{
	include_once("../static/template/forum_footer.html");
}

function display_replies_line() 
{
	global $table_width;
?>
	<table width="<?php echo $table_width; ?>" cellpadding="4"
        cellspacing="0" bgcolor="#cccccc">
		<tr><td><strong>Replies to this message</strong></td></tr>
	</table>
<?php
}

function display_index_toolbar()
{
	global $table_width;
?>
	<table width="<?php echo $table_width; ?>" cellpadding="4" cellspacing="0">
		<tr>
			<td bgcolor="#cccccc" align="right">
				<a href="new_forum.php?parent=0">
					<img src="images/new-post.gif" border="0" width="99" height="39">
				</a>
				<a href="forum.php?expand=all">
					<img src="images/expand.gif" border="0" width="99" height="39" alt="Expand All Threads">
				</a>
				
				<a href="forum.php?collapse=all">
					<img src="images/collapse.gif" border="0" width="99" height="39" alt="Collapse All Threads">
				</a>
			</td>
		</tr>
	</table>
<?php
}

function display_post($post) 
{
	global $table_width;

	if(!$post)
	{
		return;
	}
?>
	<table width="<?php echo $table_width; ?>" cellpadding="4" cellspacing="0">
		<tr>
			<td bgcolor="#cccccc">
				<strong>From: <?php echo $post['author'];?></strong><br />
				<strong>Posted: <?php echo $post['post_time'];?></strong>
			</td>
			<td bgcolor="#cccccc" align="right">
				<a href="new_forum.php?parent=0">
					<img src="images/new-post.gif" border="0" width="99" height="39" />
				</a>
				<a href="new_forum.php?parent=<?php echo $post['postid']; ?>">
					<img src="images/reply.gif" border="0" width="99" height="39" />
				</a>
				<a href="forum.php?expanded=<?php echo $post['postid']; ?>">
					<img src="images/index.gif" border="0" width="99" height="39" />
				</a>
			</td>
		</tr>
		<tr>
			<td colspan="2">
				<?php echo nl2br($post['content']);?>
			</td>
		</tr>
	</table>
<?php
}

function display_new_post_form($parent = 0, $area = 1, $title='', $message='', $author='') 
{
	global $table_width;
?>
	<table cellpadding="0" cellspacing="0" border="0" width="<?php echo $table_width; ?>">
		<form action="store_new_post.php?expand=<?php echo $parent;?>#<?php echo $parent;?>" method="post">
		<tr>
			<td bgcolor="#cccccc">Your Name:</td>
				<td bgcolor="#cccccc">
					<input type="text" name="author" value="<?php echo $author; ?>" size="20" maxlength="20"/>
				</td>
			</tr>
			<tr>
				<td bgcolor="#cccccc">Message Title:</td>
				<td bgcolor="#cccccc"><input type="text" name="title"
					value="<?php echo $title; ?>" size="20" maxlength="20" /></td>
			</tr>
			<tr>
				<td colspan="2">
					<textarea name="content" rows="10" cols="55"> <?php echo stripslashes($content);?> </textarea>
				</td>
		</tr>
		<tr>
			<td colspan="2" align="center" bgcolor="#cccccc">
				<input type="image" name="post" src="images/post.gif" alt="Post Message" width="99" height="39"/>
			</td>
				<input type="hidden" name="parent" value="<?php echo $parent; ?>">
				<input type="hidden" name="area" value="<?php echo $area; ?>">
			</td>
		</tr>
		</form>
	</table>
<?php
}
?>
