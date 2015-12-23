<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");

$qid = $_GET['qid'];
// 读取文件
$sql = "select * from questions where qid = '$qid'";
$row = getRow($sql, $conn);

include('../static/template/question_page.html');

?>