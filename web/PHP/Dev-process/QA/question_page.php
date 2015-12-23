<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");
include("./fckeditor/fckeditor.php") ;

$qid = $_GET['qid'];
// 读取文件
$sql = "select * from questions where qid = '$qid'";
$row = getRow($sql, $conn);

$sql = "select * from answers where qid = '$qid' order by ptime";
$list = getAll($sql, $conn);

/******* fckeditor *******/
$path = $_SERVER['PHP_SELF'] ;
$path = dirname($path);

$editor = new FCKeditor('content') ;
$editor->BasePath	= $path.'/fckeditor/' ;
$editor->Value		= '';

$editor->Width = '90%';
$editor->Height = '300';
$editor->ToolbarSet = 'Answer';

include('../static/template/question_page.html');

?>