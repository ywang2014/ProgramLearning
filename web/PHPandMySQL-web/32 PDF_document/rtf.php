<?php
/*
	rtf.php  产生个性化RTF证书的脚本
*/
$name = $_POST['name'];
$score = $_POST['score'];

if (!$name || !$score)
{
	echo "<h1> Error: </h1>
		<p> This page was called incorrectly </p>";
	exit;
}

header("Content-type: application/msword");
header("Content-Disposition: inline, filename = cert.rtf");

$date = date("F d, Y");

$filename = "PHPCertification.rtf";
$fp = fopen($filename, "r");

$output = fread($fp, filesize($filename));

fclose($fp);

$output = str_replace("<<NAME>>", strtoupper($name), $output);
$output = str_replace("<<Name>>", $name, $output);
$output = str_replace("<<score>>", $score, $output);
$output = str_replace("<<mm/dd/yyyy>>", $date, $output);

echo $output;

?>