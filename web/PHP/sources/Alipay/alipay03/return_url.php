<?php 

$alipayNotify = new AlipayNotify($aliapy_config);

$verify_result = $alipayNotify->verifyReturn();

if($verify_result) {//验证成功
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //请在这里加上商户的业务逻辑程序代码
     
    //――请根据您的业务逻辑来编写程序（以下代码仅作参考）――
    //获取支付宝的通知返回参数，可参考技术文档中页面跳转同步通知参数列表
    $out_trade_no   = $_GET[out_trade_no];  //获取订单号
    $trade_no       = $_GET[trade_no];      //获取支付宝交易号
    $total_fee      = $_GET[total_fee];     //获取总价格
    
	
	if($_GET[trade_status] == TRADE_FINISHED || $_GET[trade_status] == TRADE_SUCCESS) 
	{
        //判断该笔订单是否在商户网站中已经做过处理
            //如果没有做过处理，根据订单号（out_trade_no）在商户网站的订单系统中查到该笔订单的详细，并执行商户的业务程序
            //如果有做过处理，不执行商户的业务程序
		$sqldingdan="select 订单 from 数据库 where 订单字段=".$out_trade_no." ";
		$num = mysql_num_rows(_query($sqldingdan));
		//判断有无此订单号 
		if($num==0)
		{
			_query("INSERT INTO .....)");//插入订单平且更新订单为已付款
			_query("UPDATE ......");更新数据库用户的金额
		}
	}
    else 
	{
		echo "trade_status=".$_GET[trade_status];
    }
   
	echo "验证成功<br />";
    echo "trade_no=".$trade_no;
    //――请根据您的业务逻辑来编写程序（以上代码仅作参考）――
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
else 
{
    //验证失败
    //如要调试，请看alipay_notify.php页面的verifyReturn函数，比对sign和mysign的值是否相等，或者检查$responseTxt有没有返回true
    echo "验证失败";
}

>?