<?php
// 在线支付的返回信息接收页，防止伪造！

$md5key = '12345678adferrf';
$v_oid = trim($_POST['v_oid']);
$v_pstatus = trim($_POST['v_pstatus']);
$v_amount = trim($_POST['v_amount']);
$v_moneytype = trim($_POST['v_moneytype']);

$join_string = $v_oid.$v_pstatus.$v_amount.$v_moneytype.$md5key;
$md5info = strtoupper(md5($join_string));	// 自己计算MD5值

// 验证MD5信息是否正确
if ($md5info !== $_POST['v_md5str'])
{
	echo "这是假信息，没有支付成功！";
	exit;
}
else
{
	echo "支付成功，把订单号".$v_oid."对应的订单修改为已支付！";
}

?>