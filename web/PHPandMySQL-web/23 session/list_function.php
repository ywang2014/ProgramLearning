<?php
/*
	list_function.php 
	列出php中所有可供使用的扩展部件，每一个扩展所包含的函数
*/

echo "Function sets supported in this install are: <br>";
$extensions = get_loaded_extensions();
foreach ($extensions as $each_ext)
{
	echo "$each_ext <br>";
	echo "<ul>";
	$ext_funcs = get_extension_funcs($each_ext);
	foreach($ext_funcs as $func)
	{
		echo "<li> $func </li>";
	}
	echo "</ul>";
}

echo "<br> <br>";
echo get_current_user();	// 确定脚本所有者
echo "<br>";
echo date('g:: a, jS M Y', getlastmod());	// 确定脚本最近修改时间
?>