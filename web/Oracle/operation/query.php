<?php
// query a database and show the result in the web broswer.

// create connection to Oracle
$conn = oci_connect($username, $password, $dbname);	/* "//localhost/orcl" */

$query = 'SELECT * FROM tablename';
$stid = oci_parse($conn, $query);	// 分析语句
$r = oci_execute($stid);			// 执行经过分析的语句

// Fetch the result in an associate array
print('<table border = "1">');

// oci_fetch_array() 将查询结果作为一个关联数组进行检索，包括空值
while ($row = oci_fetch_array($stid, OCI_RETURN_NULLS+OCI_ASSOC))
{
	print('<tr>');
	foreach ($row as $item)
	{
		print('<td>'.($item ? htmlentities($item) : ' ').'</td>');	// ? 条件语句
	}
	print('</tr>');
}
print('</table>');

// close the oracle connection
oci_close($conn);

?>