<?php
/*
* 数据库处理函数集
*
*/


/*
* getALL 一次读取多行数据
* $sql:sql语句，$conn数据库连接资源
* return an array(二维)
*/
function getAll($sql, $conn)
{
	// 沿着$conn通道，发送$sql查询
	// while 循环，取出每一行
	// 装到二维数组，返回
	
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	$row_arr = array();
	while ($row = mysql_fetch_assoc($result))
	{
		$row_arr[] = $row;
	}
	
	return $row_arr;
}

/*
* getRow 取出单行数据
* $sql:sql语句，$conn数据库连接资源
* return an array
*/
function getRow($sql, $conn)
{
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	return mysql_fetch_assoc($result);
}

function getOne($sql, $conn)
{
	$result = mysql_query($sql, $conn);
	if (!$result)
	{
		return false;
	}
	
	$row = mysql_fetch_row($rs);
	
	return $row[0];
}

?>