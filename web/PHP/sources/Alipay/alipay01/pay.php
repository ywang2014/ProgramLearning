<?php
error_reporting(E_ALL);


header("Content-Type: text/html; charset = utf-8");


$aliname = trim($_POST['aliname']);
$alizipcode = trim($_POST['alizipcode']);
$aliphone = trim($_POST['aliphone']);
$aliaddress = trim($_POST['aliaddress']);
$aliorder = trim($_POST['aliorder']);
$alimailtype = trim($_POST['alimailtype']);
$alimoney = trim($_POST['alimoney']);
$alimob = trim($_POST['alimob']);
$alibody = trim($_POST['alibody']);

require_once('alipay.class.php');

$cmd = '0001';
$subject = '订单号：'.$aliorder;
$body = '商品介绍';
$order_no = $aliorder;
$price = $alimoney;
$url = '127.0.0.1/127.0.0.100/file/';
$type = '1';
$number = '1';
$transport = $alimailtype;
$ordinary_fee = '0.00';
$express_fee = '0.00';
$readonly = 'true';
$buyer_msg = $alibody;
$seller = $selleremail;
$buyer = '';
$buyer_name = $aliname;
$buyer_address = $aliaddress;
$buyer_zipcode = $alizipcode;
$buyer_mobile = $alimob;
$partner = '208822222222222';

$geturl = new Alipay();

$link = $geturl->geturl(
			$cmd,$subject,$body,$order_no,$price,$url,$type,$number,$transport, 
			$ordinary_fee,$express_fee,$readonly,$buyer_msg,$seller,$buyer, 
			$buyer_name,$buyer_address,$buyer_zipcode,$buyer_tel,$buyer_mobile,$partner, 
			$interfaceurl,$payalikey 
		);
		
include('./view.html');

?>