<? php
// this is jobapp_action.php
echo("<h1> 你叫：$app_name </h1>");
echo("<h1> 你的地址是：$app_address </h1>");
echo("<h1> 你的E-mail是：$app_email </h1>");
switch($position)
{
	case "1":
		$position1 = "经理"；
		break;
	case "2":
		$position1 = "经理助理"；
		break;
	case "3":
		$position1 = "秘书"；
		break;
	case "4":
		$position1 = "驾驶员"；
		break;
	case "5":
		$position1 = "程序员"；
		break;
	case "6":
		$position1 = "码农"；
		break;
}
echo("<h1> 你喜欢的工作是$position1 </h1>");
switch($province)
{
	case "1":
		$province1 = "北京";
		break;
	case "2":
		$province1 = "上海";
		break;
	case "3":
		$province1 = "广州";
		break;
	case "4":
		$province1 = "武汉";
		break;
	default:
		$province1 = "无锡";
		break;
}
echo("<h1> 你愿意的工作地方是$province1 </h1>");
echo("<h1> 你的简历如下: </h1>");
echo("<p> $app_his </p>");
? >