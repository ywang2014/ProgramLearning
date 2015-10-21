<?php
// file_exceptions.php  文件IO相关的异常

class FileOpenException extends Exception
{
	function __toString()
	{
		return "FileOpenException ".$this->getCode().
			": ".$this->getMessage()."<br>".
			"in ".$this->getFile()." on Line ".$this->getLine().
			"<br>";
	}
}

class FileWriteException extends Exception
{
	function __toString()
	{
		return "FileWriteException ".$this->getCode().
			": ".$this->getMessage()."<br>".
			"in ".$this->getFile()." pn Line ".$this->getLine().
			"<br>";
	}
}

class FileLockException extends Exception
{
	function __toString()
	{
		return "FileLockException ".$this->getCode().
		": ".$this->getMessage()."<br>".
		"in ".$this->getFile()." on Line ".$this->getLine().
		"<br>";
	}
}

?>

?>