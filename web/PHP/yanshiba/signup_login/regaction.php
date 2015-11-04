<?php

/*
	处理用户注册表单
	regaction.php
*/

require('./include/init.php');

$user = new UserModel();

$data = $user->_facade($_POST);		// 自动过滤
$user->_autoFill($data);			// 自动填充

if ($user->add($data))
{
	echo '注册成功';
}
else
{
	echo '注册失败';
}