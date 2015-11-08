<?php
/*
	防止cookie被篡改！cookie在用户的浏览器上，所以可以直接修改的
	
	测试cookie，如检测用户身份类型
	
*/
if ($_COOKIE['usertype'] == 'vip')
{
	echo "尊敬的vip客户，您好！";
}
else
{
	echo "会员用户您好！";
}


?>