<?php
/*
	此时不能跳转，信息不能传递
	USER 没有定义
*/

if (USER != true)
{
	echo "你没有登录，请登录";
	exit;	// 直接退出很重要！
}


// 执行到这个地方，说明前面的 if语句执行成功！
echo "你是合法用户，你可以看见这些信息";
echo $username;

?>
