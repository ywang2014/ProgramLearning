<?PHP
/*
*	计算在线支付的md5值
*	拼接支付平台要求的字符串
*	使用MD5加密
*/

$v_amount = $total = "50.00";	// 订单总金额
$v_moneytype = 'CNY';			// 币种
$order_sn = '12345678';			// 订单号
$v_user_account = '123456';		// 接收钱的账号
$v_url = 'http://localhost/bool/recive.php';	//回调地址
$md5key = 'abc123efd532erg';	// 这是你在支付平台留的密钥字符串，绝密资料

$join_string = $v_amount.$v_moneytype.$order_sn.$v_user_account.$v_url.$md5key;
$v_md5info = strtoupper(md5($join_string));


?>