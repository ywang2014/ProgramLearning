<?php
// create connection to Oracle

// connection
$conn = oci_connnect($username, $password, "//localhost/orcl");	// localhost 可以直接使用ip
if (!$conn)
{
	$err = oci_error();
	echo $m['message'];
	exit;
}
else
{
	print("Connected to Oracle!");
}

// close the oracle connection
oci_close($conn);	// 如果脚本结束时会自动关闭连接，则不需要 oci_close() 函数

?>