<?php
/*
	pdflib.php --- 用PDFlib生成证书
*/
$name = $_POST['name'];
$score = $_POST['score'];

if (!$name || $score)
{
	echo "<h1> Error: </h1>
			<p> This page was called incorrectly </p>";
	exit;
}

$date = date("F d Y");

$pdf = pdf_new();
pdf_open_file($pdf, "");

$width = 11 * 72;
$height = 8.5 * 72;
pdf_begin_page($pdf, $width, $height);

$inset = 10;
$border = 10;
$inner = 2;

pdf_rect($pdf, $inset-$inner, $inset-$inner, $width-2*($inset-$inner), $height-2*($inset-$inner));
pdf_stroke($pdf);

pdf_setlinewidth($pdf, $border);
pdf_rect($pdf, $inset+$border/2, $inset+$border/2, $width-2*($inset+$border/2), $height-2*($inset+$border/2));
pdf_stroke($pdf);
pdf_setlinewidth($pdf, 1.0);

pdf_rect($pdf, $inset+$border+$inner, $inset+$border+$inner, $width-2*($inset+$border+$inner), $height-2*($inset+$border+$inner));
pdf_stroke($pdf);

$fontname = "Times-Roman";
$font = pdf_findfont($pdf, $fontname, "host", 0);
if ($font)
{
	pdf_setfont($pdf, $font, 48);
}
$startx = ($width - pdf_stringwidth($pdf, "PHP Certification", $font, "12")) / 2;
pdf_show_xy($pdf, "PHP Certification", $startx, 490);

$font = pdf_findfont($pdf, $fontname, "host", 0);
if ($font)
{
	pdf_setfont($pdf, $font, 26);
}
$startx = 40;
pdf_show_xy($pdf, "This is to certify that: ", $startx, 430);
pdf_show_xy($pdf, strtoupper($name), $startx + 90, 391);

$font = pdf_findfont($pdf, $fontname, "host", 0);
if ($font)
{
	pdf_setfont($pdf, $font, 20);
}

pdf_show_xy($pdf, "has demonstrated that they are certifiable by passing a rigorous test", $startx, 340);
pdf_show_xy($pdf, "consisting of three multiple choice questions.", $startx, 310);

pdf_show_xy($pdf, "$name obtained a score of $score".'%.', $startx, 260);
pdf_show_xy($pdf, "The test was set and overseen by the ", $startx, 210);
pdf_show_xy($pdf, "Fictional Institute of PHP Certification", $startx, 180);
pdf_show_xy($pdf, "on $date.", $startx, 150);
pdf_show_xy($pdf, "Authorised by: ", $startx, 100);

$signature = pdf_load_image($pdf, "png", "/Program Files/chapter32/signature.png", "");
pdf_fit_image($pdf, $signature, 200, 75, "");
pdf_close_image($pdf, $signature);

pdf_setcolor($pdf, "both", "cmyk", 43/255, 49/255, 1/255, 67/255);	// dark
pdf_setcolor($pdf, "both", "cmyk", 1/255, 1/255, 1/255, 1/255);	// black

// draw ribbon
pdf_moveto($pdf, 630, 150);
pdf_lineto($pdf, 610, 55);
pdf_lineto($pdf, 632, 69);
pdf_lineto($pdf, 646, 49);
pdf_lineto($pdf, 666, 150);
pdf_closepath($pdf);
pdf_fill($pdf);

// outline ribbon
pdf_moveto($pdf, 630, 150);
pdf_lineto($pdf, 610, 55);
pdf_lineto($pdf, 632, 69);
pdf_lineto($pdf, 646, 49);
pdf_lineto($pdf, 666, 150);
pdf_closepath($pdf);
pdf_stroke($pdf);

// draw ribbon
pdf_moveto($pdf, 660, 150);
pdf_lineto($pdf, 680, 49);
pdf_lineto($pdf, 695, 69);
pdf_lineto($pdf, 716, 55);
pdf_lineto($pdf, 696, 150);
pdf_closepath($pdf);
pdf_fill($pdf);

// outline ribbon
pdf_moveto($pdf, 660, 150);
pdf_lineto($pdf, 680, 49);
pdf_lineto($pdf, 695, 69);
pdf_lineto($pdf, 716, 55);
pdf_lineto($pdf, 696, 150);
pdf_closepath($pdf);
pdf_stroke($pdf);
pdf_setcolor($pdf, "both", "cmyk", 1/255, 81/255, 81/255, 20/255);	//red

draw_star(665, 175, 32, 57, 10, $pdf, true);

draw_star(655, 175, 32, 57, 10, $pdf, false);

pdf_end_page($pdf);
pdf_close($pdf);
$data = pdf_get_buffer($pdf);

header("Content-type: application/pdf");
header("Content-disposition: inline; filename=test.pdf");
header("Content-length: ".strlen($data));

echo $data;

function draw_star($centerx, $centery, $points, $radius, $point_size, $pdf, $filled)
{
	$inner_radius = $radius - $point_size;
	for ($i = 0; $i <= $points * 2; $i++)
	{
		$angle = ($i*2*pi()) / ($points*2);
		
		if ($i % 2 == 0)
		{
			$x = $inner_radius * cos($angle) + $centerx;
			$y = $inner_radius * sin($angle) + $centery;
		}
		else
		{
			$x = $radius * cos($angle) + $centerx;
			$y = $radius * sin($angle) + $centery;
		}
		
		if ($i == 0)
		{
			pdf_moveto($pdf, $x, $y);
		}
		else if ($i == $points * 2)
		{
			pdf_closepath($pdf);
		}
		else
		{
			pdf_lineto($pdf, $x, $y);
		}
	}
	if ($filled)
	{
		pdf_fill_stroke($pdf);
	}
	else
	{
		pdf_stroke($pdf);
	}
}

?>