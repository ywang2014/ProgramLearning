<?php
include("./fckeditor/fckeditor.php") ;
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
	<head>
		<title>FCKeditor - Test</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<meta name="robots" content="noindex, nofollow">
	</head>
	<body>
		<h1> FCKeditor - PHP - test </h1>
		<hr>
		<form action="test_act.php" method="post" target="_blank">
<?php

$path = $_SERVER['PHP_SELF'] ;
$path = dirname($path);

$editor = new FCKeditor('content') ;
$editor->BasePath	= $path.'/fckeditor/' ;
$editor->Value		= 'test';

$editor->Width = '90%';
$editor->Height = '300';
$editor->ToolbarSet = 'Mybar';


$editor->Create() ;
?>
			<br>
			<input type="submit" value="Submit">
		</form>
	</body>
</html>
