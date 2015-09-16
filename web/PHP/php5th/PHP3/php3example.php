<html>
	<meta charset = 'utf-8'>
	<!--
	服务器使用PHP3,则不能直接使用 session 
	PHPLib 函数库，提供有在 PHP3 中对 session的管理
	可以按照包中指示，进行安装，修改 local.inc 配置文件创建自己的类
	-->
</html>

<?php 
// when you initial a session, you should call page_open() at first
// phplib return a class named Example_Session default, you can modify the value in "local.inc"

// initial a session
page_open(array("sess" => "Example_Session"));

// register a session variable
$sess->register('username');

// close, which can help you to save the useful values into data base.
page_close();
?>

<?php 
// 5.9

page_open(array("sess" => "Example_Session"));
$sess->register('username');

if ($sess->is_registered('username'))	// is_registered() 如果已经注册，则返回True
{
	echo "Variable \"username\" is registered! <br>";
}
else
{
	echo "Variable \"username\" is unregister! <br>";
}

// cancel a variable
$sess->unregister('username');

if ($sess->is_registered('username'))
{
	echo "Variable \"username\" is registered! <br>";
}
else
{
	echo "Variable \"username\" is unregister! <br>";
}

page_close();

?>

<?php
page_open(array("sess" => "Example_Session"));

if ($sess->is_registered('username'))
{
	echo "A session varaible by the name \"username\" alreadyexists";
}
else
{
	$sess->register('username');
}

page_close();

?>

<!--
	delete()	// 释放当前session
	Note：在PHPLib的cookie模式中，改变session就像飞一样！！！
	
	url($url)	// 返回当前页的URL的引用：PHP_SELF QUERY_STRING
	
	cookie always can simulate a session. Set a cookie to save your client information about his access behaving!
-->