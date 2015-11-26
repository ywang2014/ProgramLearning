<?php
/*
	broswerdir.php 
*/
?>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8">
		<title> Broswer Directories </title>
	</head>
	<body>
		<h1> Broswer </h1>
		<?php
			$current_dir = './uploads/';
			$dir = opendir($current_dir);
			
			echo "<p> Upload directory is $current_dir </p>";
			echo "<p> Directory listing: </p> <ul>";
			
			while (false !== ($file = readdir($dir)))
			{
				// strip out the two entries of . and ..
				if ($file != '.' && $file != '..')
				{
					echo '<li> '.$file.' </li>';
					echo "<li> <a href = \"filedetails.php?file=".$file."\">".$file."</a> </li>";
				}
			}
			echo '</ul>';
			closedir($dir);
			
		?>
	</body>
</html>