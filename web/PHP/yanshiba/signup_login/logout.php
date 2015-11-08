<?php
/*
	退出：删除session即可
*/
require('./include/init.php');

session_start();
session_destroy();

$msg = '退出成功';

include(ROOT.'msg.html');



?>