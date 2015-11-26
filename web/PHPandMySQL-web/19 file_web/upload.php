<?php
/*
	upload.php 
*/
?>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8">
		<title> Uploading... </title>
	</head>
	<body>
		<h1> uploading file... </h1>
		<?php
		
			print_r($_POST);
			print_r($_FILES);
			exit;
			if ($_FILES['userfile']['error'] > 0)
			{
				echo Problem: ;
				switch ($_FILES['userfile']['error'])
				{
					case 1: echo 'File exceeded upload_max_filesize'; break;
					case 2: echo 'File exceeded max_file_size'; break;
					case 3: echo 'File only partially uploaded'; break;
					case 4: echo 'No file uploaded'; break;
					case 6: echo 'Cannot upload file: No temp directory specified'; break;
					case 7: echo 'upload failed: Cannot write to disk'; break;
				}
				exit;
			}
			
			if ($_FILES['suerfile']['type'] != 'text/plain')
			{
				echo 'Problem: file is not plain text';
				exit;
			}
			
			$upfile = '/uploads/'.$_FILES['userfile']['name'];
			
			if (is_uploaded_file($_FILES['username']['tmp_name']))
			{
				if (!move_uploaded_file($_FILES['userfile']['tmp_name'], $upfile))
				{
					echo 'Problem: Could not move file to destination directory';
					exit;
				}
			}
			else
			{
				echo 'Problem: Possible file upload attack. Filename:';
				echo $_FILES['userfile']['name'];
				exit;
			}
			
			echo 'File uploaded successfully<br><br>';
			
			$contents = file_get_contents($upfile);
			$contents = strip_tags($contents);
			file_put_contents($_FILES['username']['name'], $contents);
			
			// show file contents
			echo '<p> Preview of uploaded file contents:<br><br>';
			echo nl2br($contents);
			echo '<br><br>';
		?>
	</body>
</html>