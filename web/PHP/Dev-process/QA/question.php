<?php
header('content-type: text/html; charset=utf-8');
require("../include/init.php");

// 读取文件
$sql = "select * from questions order by ptime desc limit 5";
$rows = getAll($sql, $conn);

include('../static/template/question.html');

?>