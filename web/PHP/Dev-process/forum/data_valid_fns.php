<?php

function filled_out($form_vars) 
{
	// test that each variable has a value
	foreach ($form_vars as $key => $value)   
	{
		if (!isset($key) || ($value === '')) 
		{
			return false;
		}
	}
	
	return true;
}

function clean($string) 
{
	$string = trim($string);
	$string = htmlentities($string);	// htmlentities() 函数把字符转换为 HTML 实体 --- 要把 HTML 实体转换回字符，请使用 html_entity_decode() 函数
	$string = strip_tags($string);	// strip_tags() 函数剥去字符串中的 HTML、XML 以及 PHP 的标签
	return $string;
}

function clean_all($form_vars) 
{
	foreach ($form_vars as $key => $value)   
	{
		$form_vars[$key] = clean($value);
	}
	
	return $form_vars;
}

// 检查postid的合法性，为整数，在数据库中
function valid_postid($postid)
{
	// 简单处理
	return (is_numeric($postid) && ($postid > 0));
}
?>
