<?php

/*
	处理用户注册表单
	regaction.php
*/

require('./include/init.php');

$user = new UserModel();

if (!$user->_validate($_POST))	// 自动检验
{
	//print_r($user->getErr());
	$msg = implode('<br>', $user->getErr());
	include(ROOT.'view/front/msg.html');
	exit;
}

// 检验是否有重名
if ($user->checkUser($_POST['username']))
{
	$msg = '用户名已存在';
	include(ROOT.'view/front/msg.html');
	exit;
}

$data = $user->_facade($_POST);		// 自动过滤
$user->_autoFill($data);			// 自动填充

if ($user->reg($data))
{
	//echo '注册成功'; 用页面输出 view
	$msg = '注册成功';
}
else
{
	// echo '注册失败';
	$msg = '注册失败';
	
}

// 引入view
include(ROOT.'view/front/msg.html');