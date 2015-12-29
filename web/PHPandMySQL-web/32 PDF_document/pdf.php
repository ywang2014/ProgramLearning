<?php
/*
	pdf.php---- 通过模板产生个性化PDF证书脚本程序
*/
set_time_limit(180);	// this script can be slow

function pdf_replace($pattern, $replacement, $string)
{
	$len = strlen($pattern);
	$regexp = '';
	
	for ($i = 0; $i < $len; $i++)
	{
		$regexp .= $pattern[$i];
		if ($i < $len - 1)
		{
			$regexp .= '(\)\-{0, 1}[0-9]*\(){0, 1}';
		}
	}
	
	return ereg_replace($regexp, $replacement, $string);
}

$name = $_POST['name'];
$score = $_POST['score'];
if (!$name || !$score)
{
	echo "<h1> Error: </h1>
			<p> This page was called incorrectly </p>";
	exit;
}

header("Content-Disposition: filename=cert.pdf");
header("Content-type: application/pdf");

$date = date("F d Y");

$filename = "PHPCertification.pdf";
$fp = fopen($filename, "r");
$output = fread($fp, filesize($filename));
fclose($fp);

$output = pdf_replace("<<NAME>>", strtoupper($name), $output);
$output = pdf_replace("<<Name>>", $name, $output);
$output = pdf_replace("<<score>>", $score, $output);
$output = pdf_replace("<<mm/dd/yyyy>>", $date, $output);

echo $output;

?>