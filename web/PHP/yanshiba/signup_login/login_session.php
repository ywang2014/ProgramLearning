<?php
/*
	用户登录页面
*/

require('./include/init.php');

if(isset($_POST['act']))
{
	// 说明是点击登录提交按钮之后，进入login.php的
	// 此时，只需要接收post的数据即可
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	// 检测信息合法性
	// 1.创建对象
	$user = new UserModel($username, $password);
	// 2.调用对象方法，检查信息
	$row = $user->checkUser($username, $password);
	if (empty($row))
	{
		$msg = '用户名或密码错误';
	}
	else
	{
		$msg = '登录成功';
		session_start();
		$_SESSION = $row;
		
		// 记住用户名
		if (isset($_POST['remenberuser']))
		{
			setcookie('remenberuser', $username, time()+14*24*3600)；
		}
		else
		{
			setcookie('remenberuser', '', 0);
		}
		
		include(ROOT.'msg.html');
		exit;
	}
	
}
else
{
	// 准备登录，点击的是导航条的登录按钮
	$remenberuser = isset($_COOKIE['remenberuser']) ? $_COOKIE['remenberuser']: '';
	// 在用户名表单中，value = echo $remenberuser; 即可
	
	include(ROOT.'view/front/login.html');
}



?>