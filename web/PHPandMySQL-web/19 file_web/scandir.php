<?php
/*
	文件名称有序输出
	scandir()
*/
?>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8">
		<title> Broswer Directories inorder </title>
	</head>
	<body>
		<h1> Broswer </h1>
		<?php
			$current_dir = './uploads/';
			$file1 = scandir($current_dir);
			$file2 = scandir($current_dir, 1);
			
			echo "<p> Upload directory is $current_dir </p>";
			echo "<p> Directory listing in alphabetical order: </p> <ul>";
			
			foreach($file1 as $file)
			{
				// strip out the two entries of . and ..
				if ($file != '.' && $file != '..')
				{
					echo '<li> $file </li>';
				}
			}
			echo '</ul>';
			
			echo "<p> Upload directory is $current_dir </p>";
			echo "<p> Directory listing in alphabetical descending: </p> <ul>";
			
			foreach($file2 as $file)
			{
				// strip out the two entries of . and ..
				if ($file != '.' && $file != '..')
				{
					echo '<li> $file </li>';
				}
			}
			echo '</ul>';
		?>
	</body>
</html>