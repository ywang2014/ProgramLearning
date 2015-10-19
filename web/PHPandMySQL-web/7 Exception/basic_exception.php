<?php
// basic_exception.php  抛出并捕获一个异常

try
{
	throw new Exception('A terrible error has occurred', 42);
}
catch (Exception $e)
{
	echo "Exception ".$e->getCode().": ".$e->getMessage()."<br>".
			" in ".$e->getFile()." on line ".$e->getLine()."<br>";
}
?>