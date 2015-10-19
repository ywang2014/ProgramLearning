<?php
// reflection.php  显示关于Page类的信息

require_once("page_class.inc");

$class = new ReflectionClass("Page");
echo "<pre>".$class."</pre>";

?>