<?php
/*
	所有用户访问的页面，第一步必须加载 init.php 
*/

require(./includes/init.php);

$conf = conf::getInstance();

// test
$conf = config::getInstance();
print_r($conf);

echo $conf->hostname;

var_dump($conf->template_dir);
$conf->template_dir = 'D:/www/smarty';

echo $conf->template_dir;


?>