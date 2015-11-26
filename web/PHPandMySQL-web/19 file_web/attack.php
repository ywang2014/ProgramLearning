<?php
	$path = './html/index.php';
	$file1 = basename($path);
	$file2 = basename($path, '.php');
	$path2 = './html/index.html';
	$file3 = basename($path2);
	
	print($file1.'<br>');	// index.php 
	print($file2.'<br>');	// index
	print($file3.'<br>');	// index.html

?>