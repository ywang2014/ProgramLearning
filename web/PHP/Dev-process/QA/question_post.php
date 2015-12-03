<?php

header('Content-type: text/html; charset = utf-8');

include("./fckeditor/fckeditor.php") ;

$path = $_SERVER['PHP_SELF'] ;
$path = dirname($path);

$editor = new FCKeditor('content') ;
$editor->BasePath	= $path.'/fckeditor/' ;
$editor->Value		= '';

$editor->Width = '90%';
$editor->Height = '300';
$editor->ToolbarSet = 'Mybar';


include('../static/template/question_post.html');

?>