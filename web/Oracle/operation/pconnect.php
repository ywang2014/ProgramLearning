<?php
// oci_pconnect 创建永久链接，oci_close() 不会关闭持久连接

// function to execute a query
function do_query($conn, $query)
{
	$stid = oci_parse($conn, $query);
	oci_execute($stid);
	oci_fetch_all($stid, $res);
	echo "<pre>";
	var_dump($res);	// var_dump 调试函数输出包含日期查询结果的 PHP 变量的值和结构
	echo "</pre>";
}

// create a persistent connection to Oracle
$conn = oci_pconnect($username, $password, $dbname);

// query the database system date
$sql1 = "select sysdate from dual";
do_query($conn, $sql);

// change the NLS Territory
$sql2 = "alter session set nls_territory=china";
$stid = oci_parse($conn, $sql);
$r = oci_execute($stid);

// query the database system date again
do_query($conn, $sql1);

oci_close($conn);	// invalid

?>