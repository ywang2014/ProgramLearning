<?php
// create.php
include <common.php>;
mysql_connect($hostname, $username, $password) or die("Unable to connect database");
@mysql_select_db("$dbname") or die("Unable to select database");
// 函数前面加 @ 符号，将会抑制错误信息的提示
$sql = "create table diaocha(id int default '0' not null auto_increment, 
							 name char(20),
							 sex varchar(10),
							 age tinyint(4),
							 place varchar(10),
							 primary key(id),
							 unique id(id))";
mysql_query($sql);
mysql_close();

?>