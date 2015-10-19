<?php
// user_defined_exception.php  用户定义Exception类的实例

class myException extends Exception
{
	// final 方法不能被重载
	function __toString()
	{
		return "<table border = 1>".
				"<tr>".
				"<td> <strong>Exception ".$this->getCode().
				"</strong>: ".$this->getMessage()."<br>".
				"in ".$this->getFile()." on line ".$this->getLine().
				"</td>".
				"</tr>".
				"</table> <br>";
	}
}

try 
{
	throw new MyException("A terrible error has occurred", 42);
}
catch (myException $m)
{
	echo $m;
}
?>