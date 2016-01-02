<?php
/*
	constants.php -- 声明全局常量和变量
	
	一次集中声明，方便调试和维护
*/
//define("METHOD", "SOAP");
define("METHOD", "REST");

define("CACHE", "cache");	// path to cached files
define("ASSOCIATEID", "XXXXXXXXXXXXXXXXXXXXX");	// put your associate id here	亚马逊注册的会员id，得提成回扣的
define("DEVTAG", "XXXXXXXXXXXXXXXXX");	// put your developer tag here			开发人员令牌

if(DEVTAG == 'XXXXXXXXXXXXXXXXX')
{
	die("You need to sign up for an Amazon.com developer tag at <a href = \"http://aws.amazon.com\" > Amazon </a>
		 when you install this sotfware. you should probably sign up for an associate ID at the same time. Edit the file constants.php.");
}

$categoryList = array(5 => "Computers & Internet", 3150 => "Web Development", 295223 => "PHP", 17 => "Literature and Fiction", 
						3 => "Business & Investing", 53 => "Non Fiction", 23=>'Romance', 75=>'Science', 21=>'Reference',
						6 =>'Food & Wine', 27=>'Travel',16272=>'Science Fiction');




?>