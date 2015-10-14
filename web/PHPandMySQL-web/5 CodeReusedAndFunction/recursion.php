<?php
// recursion.php 使用递归讲一个字符串逆序输出

function reverse_str_recursion($str)
{
	if (strlen($str) > 0)
	{
		reverse_str_recursion(substr($str, 1));
	}
	echo substr($str, 0, 1);
	return ;
}

function reverse_str_non_recursion($str)
{
	for ($i = 1; $i < strlen($str); $i++)
	{
		echo substr($str, -$i, 1);
	}
	return ;
}

reverse_str_recursion("Hello");
reverse_str_non_recursion("Hello");

?>