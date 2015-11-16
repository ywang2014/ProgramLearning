<?php
/*
	测试循环结果，重复输出
*/

define('ACCESS', true);

header("Content-Type: text/html; charset=utf-8;");

require_once('main.php');
include(ROOT."testpath.php");
$path = "/127.0.0.100/www/mytest/";
include(ROOT."template123/test_form.html");

$arr1 = array(1=>"苹果", 2=>"菠萝", 3=>"西红柿", 3=>"水蜜桃");
$smarty->assign('arr1', $arr1);

$forum = array(
			array("category_id"=>1, "category_name"=>"公告区", 
					"topic"=>array(
								array("topic_id"=>1, "topic_name"=>"站务公告")
								)
					),
			array("category_id"=>2, "category_name"=>"文学专区",
					"topic"=>array(
								array("topic_id"=>2, "topic_name"=>"好书介绍"),
								array("topic_id"=>3, "topic_name"=>"奇文共赏")
								)
					),
			array("category_id"=>3, "category_name"=>"计算机专区",
					"topic"=>array(
								array("topic_id"=>4, "topic_name"=>"硬件技术"),
								array("topic_id"=>5, "topic_name"=>"软件讨论")
								)
					)
			);
			
$smarty->assign("forum", $forum);

$smarty->display("test_form.html");


?>