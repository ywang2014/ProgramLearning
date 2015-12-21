<?php
/*
	upload.php --- 上传新闻信件的处理脚本
	
*/
$max_size = 50000;

include("include_fns.php");
session_start();

if (check_admin_user())
{
	$button = array();
	$button[0] = 'change_password';
	$buttons[1] = 'create_list';
	$buttons[2] = 'create_mail';
	$buttons[3] = 'view_mail';
	$buttons[4] = 'log_out';
	$buttons[5] = 'show_all_lists';
	$buttons[6] = 'show_my_lists';
	$buttons[7] = 'show_other_lists';
	
	do_html_header('Pyramid_MLM - Upload Files');
	
	display_toolbar($buttons);
	
	if ($_FILE['userfile']['name'][0] && $_FILE['userfile']['name'][1] && $_POST['subject'] && $_POST['list'])
	{
		$list = $_POST['list'];
		$subject = $_POST['subject'];
		
		if ($conn = db_connect())
		{
			$sql = "insert into mail values (NULL, '".$_SESSION['admin_user']."', '$subject', '$list', 'STORED', NULL, NULL)";
			$result = mysql_query($sql, $conn);
			if ($result)
			{
				$mailid = mysql_insert_id();
				if ($mailid)
				{
					@mkdir('archive/'.$list, 0700);
					if (mkdir('archive/'.$list.'/'.$mailid, 0700))
					{
						$i = 0;
						while ($_FILES['username']['name'][$i] && $_FILES['username']['name'][$i] != 'none')
						{
							echo "<p> Uploading ".$_FILES['userfile']['name'][$i].' - '.$_FILES['userfile']['size'][$i].'bytes. </p>';
							if ($_FILES['userfile']['size'][$i] == 0)
							{
								echo "<p>.Problem: ".$_FILES['userfile']['name'][$i]." is zero length.";
								$i++;
								continue;
							}
							
							if ($_FILES['userfile']['size'][$i] > $max_size)
							{
								echo "<p> Problem: ".$_FILES['userfile']['name'][$i]." is over ".$max_size." bytes.";
								$i++;
								continue;
							}
							
							if (($i > 1) && (!getimagesize($_FILES['userfile']['tmp_name'][$i])))
							{
								echo "<p> Problem: ".$_FILES['userfile']['name'][$i]." is corrupt, or not a gif, jpeg or png. </p>";
								$i++;
								continue;
							}
							
							if ($i == 0)
							{
								$destination = 'archive/'.$list.'/'.$mailid.'/text.txt';
							}
							else if ($i == 1)
							{
								$destination = 'archive/'.$list.'/'.$mailid.'/index.html';
							}
							else 
							{
								$destination = 'archive/'.$list.'/'.$mailid.'/'.$_FILES['userfile']['name'][$i];
								
								$sql = "insert into images values ('$mailid', '".$_FILES['userfile']['name'][$i]."', '".$_FILES['userfile']['type'][$i]."')";
								$result = mysql_query($sql);
							}
							
							if (!is_uploaded_file($_FILES['userfile']['tmp_name'][$i]))
							{
								echo "<p> Something funny happening with ".$_FILES['userfile']['name']." , not uploading.";
								do_html_footer();
								exit;
							}
							
							move_uploaded_file($_FILES['userfile']['tmp_name'][$i], $destination);
							$i++;
						}
						
						display_preview_button($list, $mailid, 'preview_html');
						display_preview_button($list, $mailid, 'preview_text');
						display_button('send', "&id='$mailid'");
						
						echo "<p style = \"padding-bottom: 50px;\"> &nbsp; </p>";
						do_html_footer();
					}
					else
					{
						do_html_footer();
						exit;
					}
				}
				else
				{
					do_html_footer();
					exit;
				}
			}
			else
			{
				do_html_footer();
				exit;
			}
		}
		else
		{
			echo "<p> Could not connect to db. </p>";
			do_html_footer();
			exit;
		}
	}
	else
	{
		echo "<p> Problem: You did not fill out the form fully. The images are the only optional fields. ".
			"Each message needs a subject, text version, an HTML version. </p>";
			
		do_html_footer();
		exit;
	}
}
else
{
	echo "<p> YOu do not seem to be authorized to use this page. </p>";
	exit;
}



?>