<?php

/*
*	测试 mini模板
*
*/

include('./mini_template.php');

$mini = new mini();

$mini->template_dir = './template';
$mini->compile_dir = './compile';

// echo $mini->compile('temp_smarty.html');
include($mini->compile('temp_smarty.html'));

?>