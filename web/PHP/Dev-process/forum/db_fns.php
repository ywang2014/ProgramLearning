<?php
/*
	db_fns.php
*/

function db_connect()
{
	$conn = mysql_connect("127.0.0.1", "project", "project");
	if ($conn)
	{
		if (@mysql_select_db("project", $conn))
		{
			mysql_query("SET names utf8");
		
			return $conn;
		}
		else
		{
			echo "<p> Database cannot be accessed now, please try again later! </p>";
		}
	}
	else
	{
		echo "<p> Host server cannot be accessed now, please try again later! </p>";
	}
	
	return false;
}

function getRow($sql)
{
	$result = mysql_query($sql);
	if ($result)
	{
		$row = mysql_fetch_array($result);
		
		return $row;
	}
	else
	{
		echo "<p> The SQL cannot be executed, try again later! </p>";
		return false;
	}
}

function getRows($sql)
{
	$result = mysql_query($sql);
	if ($result)
	{
		$rows = array();
		while ($current_row = mysql_fetch_array($result))
		{
			array_push($rows, $current_row);
		}
		
		return $rows;
	}
	else
	{
		echo "<p> The SQL cannot be executed, try again later! </p>";
		return false;
	}
}

function getNum($sql)
{
	$result = mysql_query($sql);
	if ($result)
	{
		$num = mysql_num_rows($result);
		
		return $num;
	}
	else
	{
		echo "<p> The SQL cannot be executed, try again later! </p>";
		return false;
	}
}

// 修改，删除，插入等
function do_sql_ok($sql)
{
	$result = mysql_query($sql);
	if ($result)
	{
		// 保证确实修改了数据库
		if (mysql_affected_rows() > 0)
		{
			echo "<p> Congratulations! </p>";
			return true;
		}
	}
	
	echo "<p> Sorry, something is wrong! </p>";
	return false;
}


?>