<?php

header('Content-type: text/html; charset=utf-8');
	
echo $_SESSION['wuliu_captcha'].'<br>';
$validate = trim($_POST['validate']);
echo $validate.'<br>';
if (strtolower($validate) == $_SESSION['wuliu_captcha'])
{
	echo "输入验证码正确";
}
else
{
	echo"<script>alert('验证码输入错误！');history.go(-1);</script>";  
	exit;
}

?>