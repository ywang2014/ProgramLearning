<?php

// 查看留言板模块 guestbook.php

/*
	每页显示一个留言以及它的回复
	用户看完一条留言，可以继续查看，页面显示下一条留言
	显示时，需要PHP生成动态的HTML文档
	
	选择性阅读留言，则可以提供搜索功能，实现复杂
*/
function function_1($text)
{
	// 对变量$text中的字符串解析
	$text = ereg_replace("C_J", "<", $test);
	$text = ereg_replace("C_I", ">", $text);
	// 将换行字符转换成<br>
	$text = nl2br($text);
	
	return $text;
}

function function_2($text)
{
	$text = htmlspecialchars($text);
	$text = nl2br($text);
	// 字符串解析
	$text = preg_replace("/\ \t/is", "", $text);
	$text = preg_replace("/\[h1\](.+?)\[\/h1\]/is", "<h1> \ \ 1</h1>", $text);
	$text = preg_replace("/\[h2\](.+?)\[\/h2\]/is", "<h2> \ \ 1</h2>", $text);
	$text = preg_replace("/\[h3\](.+?)\[\/h3\]/is", "<h3> \ \ 1</h3>", $text);
	$text = preg_replace("/\[h4\](.+?)\[\/h4\]/is", "<h4> \ \ 1</h4>", $text);
	$text = preg_replace("/\[h5\](.+?)\[\/h5\]/is", "<h5> \ \ 1</h5>", $text);
	$text = preg_replace("/\[h6\](.+?)\[\/h6\]/is", "<h6> \ \ 1</h6>", $text);
	
	$text = preg_replace("/\[url\](.+?)\[\/url\]/is", "<a href = \ \1> \ \ 1</a>", $text);
	$text = preg_replace("/\[url = (.+?)\](.*)\[\/url\]/is", "<a href = \ \1> \ \ 2</a>", $text);
	
	$text = preg_replace("/\[img\](.+?)\[\/img\]/is", "<img src = \ \1>", $text);
	$text = preg_replace("/\[b\](.+?)\[\/b\]/is", "<b> \ \ 1</b>", $text);
	$text = preg_replace("/\[email\](.+?)\[\/email\]/is", "<a href = \ \1> \ \1 </a>", $text);
	$text = preg_replace("/\[i\](.+?)\[\/i\]/is", "<i> \ \1 </i>", $text);

	return $text;
}

// 字符串解析，可以按照自己的习惯设计，个人思考方式不同，源代码可能有很大不同
// 可以通过自己的思考设计，研究此函数！

?>