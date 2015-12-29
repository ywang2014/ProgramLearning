<?php
/*
	PDFlib 测试程序 "Hello world"
*/
$pdf = pdf_new();
pdf_open_file($pdf, "");

pdf_set_info($pdf, "Author", "MySelf");
pdf_set_info($pdf, "Title", "Hello World (PHP)");
pdf_set_info($pdf, "Creator", "testPDFlib.php");
pdf_set_info($pdf, "Subject", "Test PDF");

pdf_begin_page($pdf, 8.5*72, 11*72);	// 开始一个新页

pdf_add_bookmark($pdf, "Page 1", 0, 0);

$font = pdf_findfont($pdf, "Times-Roman", "host", 0);
pdf_setfont($pdf, $font, 24);
pdf_set_text_pos($pdf, 50, 700);	// 设置文本起始位置

pdf_show($pdf, "Hello World");
pdf_continue_text($pdf, "(says PHP)");

pdf_end_page($pdf);
pdf_close($pdf);
$data = pdf_get_buffer($pdf);

header("Content-type: application/pdf");
header("Content-Disposition: inline; filename=testPDFlib.pdf");
header("Content-Length: ".strlen($data));

echo $data;		// output PDF

?>