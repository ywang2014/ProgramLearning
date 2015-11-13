<?php

require_once("alipay_service.php");
require_once("alipay_config.php");  

$array=explode("@",$info["spc"]);

$arraynum=explode("@",$info["slc"]);

$arrayinfo=array(); //创建数组

$arrayinfo_count=array(); //创建数组

for($i=0;$iif($array[$i]!="")
{
	$m=$i+1;
	$sqlcart=mysql_query("select * from tb_commodity where tb_commodity_id='".$array[$i]."'",$conn);
	$infocart=mysql_fetch_array($sqlcart);//读取数据库中数据
	array_push($arrayinfo,$infocart[tb_commodity_name]);//将购物商品的名称写入到数组中
	array_push($arrayinfo_count,"商品 $m ：$infocart[tb_commodity_name] 数量：$arraynum[$i]");    //将购物商品的数量写入到数组中
}

$commodity_name=implode(',',$arrayinfo); //获取商品名称
$commodity_count=implode(',',$arrayinfo_count);  //获取商品描述信息

$parameter = array(
		"service" => "trade_create_by_buyer", //交易类型，必填实物交易＝trade_create_by_buyer（需要填写物流）
		"partner" =>$partner,   //合作商户号
		"return_url" =>$return_url, //同步返回
		"notify_url" =>$notify_url, //异步返回
		"_input_charset" => $_input_charset,  //字符集，默认为GBK
		"subject" => $commodity_name,    //商品名称，必填
		"body" => $commodity_count,       //商品描述，必填
		"out_trade_no" => $ddnumber,//商品外部交易号，订单号，必填,每次测试都须修改
		"logistics_fee"=>$yprice, //物流配送费用
		"logistics_payment"=>'BUYER_PAY', //物流配送费用付款方式：BUYER_PAY(买家支付)
		"logistics_type"=>'EXPRESS',// 物流配送方式：POST(平邮)、EMS(EMS)、EXPRESS(其他快递)
		"price" => $amount,//商品单价，必填
		"payment_type"=>"1", // 默认为1,不需要修改
		"quantity" => "1", //商品数量，必填
		"show_url" => $show_url,//商品相关网站
		"seller_email" => $seller_email//卖家邮箱，必填
	);
	
$alipay = new alipay_service($parameter,$security_code,$sign_type);

$link=$alipay->create_url();

$smarty->assign("link",$link);

?>