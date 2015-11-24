<?php 
header('content-type: text/html; charset=utf-8');

// print_r($_POST);

include("connection.php");

if(isset($_POST["Submit"])){
	$query="insert into `news` (title) values ('$_POST[content]')";
	mysql_query($query);
	$id = mysql_insert_id();
} 

header('location:news.php');
/*
$sql = "select * from news";
//$sql = "select * from news where id = '$id'";
$result = mysql_query($sql);
while ($row = mysql_fetch_array($result))
{
	print_r($row['title']);
}

*/
?>