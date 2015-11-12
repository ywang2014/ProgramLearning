<?
/*
	打印目录--递归
*/

function readDir($path)
{
	$dh = opendir($path);
	
	while (($file = readdir($dh)) !== false)
	{
		echo $file."<br>";
		
		if ($file == '.' || $file == '..')
		{
			continue;
		}
		else
		{
			if (is_dir($path.'/'.$file))
			{
				readDir($path.'/'.$file));
			}
		}
	}
	
	fclose($dh);
}

// test
readDir('./');
?>