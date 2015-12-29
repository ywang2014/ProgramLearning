<?php
/*
	score.php  评阅检测的脚本，给用户打分
*/
if (! isset($_POST['q1']))
{
	echo "<script> alert('Hacker, please go away!'); window.location.href=\"index.html\"; </script>";
	exit;
}

foreach ($_POST as $k => $v)
{
	if (trim($v) == '')
	{
		echo "<h1>
				<p align = \"center\"> 
				<img src = \"rosette.gif\" alt = \" \">
				Sorry!
				<img src = \"rosette.gif\" alt = \" \" >
				</p>
			</h1>
			<p>You need to fill in your name and answer all questions. </p>";
			exit;
	}
	
	$$k = $v; 
}

$score = 0;
if ($q1 == 1)
{
	$score++;
}

if ($q2 == 1)
{
	$score++;
}

if ($q3 == 1)
{
	$score++;
}

$score = $score * 100 / 3;

if ($score < 50)
{
	echo "<h1>
			<p align = \"center\">
			<img src = \"rosette.gif\" alt = \" \">
			Sorry!
			<img src = \"rosette.gif\" alt = \" \" >
			</p>
		  </h1>
		  <p> You need to score at least 50% to pass the test. </p>";
}
else
{
	$score = number_format($score, 1);
	echo "<h1>
			<p align = \"center\">
			<img src = \"rosette.gif\" alt = \" \">
			Congratulations!
			<img src = \"rosette.gif\" alt = \" \" >
			</p>
		  </h1>
		  <p> Well done ".$name.", with a score of ".$score."%, you have passed the exam. </p>";
		  
	echo "<p> Please click here to download your certificate as a Microsoft Word (RTF) file.</p>
			<form action = \"rtf.php\" method = \"post\">
				<div align = \"center\">
					<input type = \"image\" src = \"certificate.gif\" border = \"0\" >
				</div>
				<input type = \"hidden\" name = \"score\" value = \"".$scroe."\">
				<input type = \"hidden\" name = \"name\" value = \"".$name."\">
			</form>
			
			<p> Please click here to download your certificate as a Portable Document Format (PDF) file.</p>
			<form action = \"pdf.php\" method = \"post\" >
				<div align = \"center\">
					<input type = \"image\" src = \"certificate.gif\" border = \"0\">
				</div>
				<input type = \"hidden\" name = \"score\" value = \"".$score."\" />
				<input type = \"hidden\" name = \"name\" value = \"".$name."\" />
			</form>
			
			<p> Please click here to download your certificate as a Portable Document Format (PDF) file
				generated with PDFlib.</p>
			<form action = \"pdflib.php\" method = \"post\" >
				<div align = \"center\">
					<input type = \"image\" src = \"certificate.gif\" border = \"0\">
				</div>
				<input type = \"hidden\" name = \"score\" value = \"".$score."\" />
				<input type = \"hidden\" name = \"name\" value = \"".$name."\" />
			</form>
			";
}

?>