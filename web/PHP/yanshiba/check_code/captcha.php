<?php
header('Content-type: text/html; charset=utf-8');

session_start();
require_once('./ValidateCode.class.php');

$vc = new ValidateCode();
$vc->createImg();
$_SESSION['wuliu_captcha'] = $vc->getCode();
print_r($_SESSION);

?>