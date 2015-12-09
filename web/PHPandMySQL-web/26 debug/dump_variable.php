<?php
/*
	调试方法：
	将特定变量的值打印出来
*/

echo "\n<!-- Begin variable dump -->\n\n";

echo "<!-- Begin get vars -->\n";
echo "<!-- ".dump_array($_GET)." -->\n";

echo "<!-- Begin post vars -->\n";
echo "<!-- ".dump_array($_POST)." -->\n";

echo "<!-- Begin session vars -->\n";
echo "<!-- ".dump_array($_SESSION)." -->\n";

echo "<!-- Begin cookie vars -->\n";
echo "<!-- "dump_array($_COOKIE)." -->\n";

echo "\n<!-- End variable dump -->\n";

// dump_array() takes one array as a parameter
function dump_array($array)
{
	if (is_array($array))
	{
		$size = count($array);
		$string = '';
		if ($size)
		{
			$count = 0;
			$string .= "( ";
			
			foreach ($array as $k => $v)
			{
				$string .= $k."=>".$v;
				if ($count++ < ($size - 1))
				{
					$string .= ", ";
				}
			}
			$string .= " )";
		}
		
		return $string;
	}
	else
	{
		return $array;
	}
}

?>