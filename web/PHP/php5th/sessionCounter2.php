<meta charset = 'utf-8'>

<?php

session_start();
// session变量用于保存计数器
session_register('counter');
// session变量用于保存最后装入的时间值
// 此值用于比较两次的不同
session_register('timeAtLastLoad');
// 当前时间
$timeNow = time();
// 增加计数
$_SESSION['counter']++;
// 计算两次时间间隔
$timeLapsed = $timeNow - $_SESSION['timeAtLastLoad'];
$_SESSION['timeAtLastLoad'] = $timeNow;
// 显示信息
echo "<CENTER> <h1>Welcome to my homepage!</h1> <br><br><br>";
if ($_SESSION['counter'] > 1)
{
	echo "<b>从你上一次浏览这个页面到现在过了 $timeLapsed 秒! </b>";
}
else
{
	echo "<b> 第一次来这里吗？</b>";
}
echo "<br><br><br>Thank you for visit my website!";
echo "<br><br><br>Bye-bye! Hope to see you later. </CENTER>";
echo "<br><a algin = left href = https://github.com/ywang2014> Mygithub </a>";

// <div sttyle = "position: absolute; bottom: 1000px; right: 1000px;"> Link </div>

?>
