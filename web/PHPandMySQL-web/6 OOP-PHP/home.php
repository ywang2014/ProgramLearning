<?php
// home.php  首页使用Page类完成生成页面内容的大部分工作

require("page_class.inc");

$homepage = new Page();

$homepage->content = "<p> Welcome to the home of TLA Consulting.".
						"Please take some time to get to know us.</p>".
						"<p> We specialize in serving your business needs and hope to hear from you soon.</p>";
						
$homepage->Display();

?>