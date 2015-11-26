<?php
/*
	windows 可能不支持一些函数
	posix_getpwuid()
	fileowner()
	filegroup()
	
*/


?>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8">
		<title> File Details </title>
	</head>
	
	<body>
		<?php
			$file = $_GET['file'];
			$current_dir = './uploads/';
			$file = basename($file);
			//print_r(stat($file));
			
			echo '<h1> Details of file info: $file </h1>';
			
			echo '<h2> File Data </h2>';
			echo 'File last accessed: '.date('j F Y H:i', fileatime($file)+8*3600).'<br>';
			echo 'File last modified: '.date('j F Y H:i', filemtime($file)+8*3600).'<br>';
			
			//$user = posix_getpwuid(fileowner($file));
			$user['name'] = 'root';
			echo 'File owner: '.$user['name'].'<br>';
			
			//$group = posix_getgrgid(filegroup($file));
			$group['name'] = 'root';
			echo 'File group: '.$group['name'].'<br>';
			
			echo 'File permissions: '.decoct(fileperms($file)).'<br>';
			
			echo 'File type: '.filetype($file).'<br>';
			
			echo 'File size: '.filesize($file).' bytes<br>';
			
			echo '<h2> File tests </h2>';
			
			echo 'is_dir: '.(is_dir($file)? 'true' : 'false').'<br>';
			echo 'is_executable: '.(is_executable($file)? 'true' : 'false').'<br>';
			echo 'is_file: '.(is_file($file)? 'true' : 'false').'<br>';
			echo 'is_link: '.(is_link($file)? 'true' : 'false').'<br>';
			echo 'is_readable: '.(is_readable($file)? 'true' : 'false').'<br>';
			echo 'is_writable: '.(is_writeable($file)? 'true' : 'false').'<br>';
		
		?>
	</body>
</html>