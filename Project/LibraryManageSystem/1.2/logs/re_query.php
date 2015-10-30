<?
// re_query.php

include "common.php";

$link = mysql_connect($hostname, $username, $password);
if ($link == 0)
{
	echo "<p align = center> 数据库服务器连接出错！</p>";
	exit();
}

if (mysql_select_db($dbname, $link) == 0)
{
	echo "<p align = center> 激活数据库失败！</p>";
	exit(0);
}

if ($subject == "")
{
	echo "<p align = center> 请填写必要的搜索信息！";
	echo "<br> <a href = \"javascript:history.back()\"> 返回重填 </a>";
	exit();
}

// 判断是否精确查询，从而确定SQL语句中的查询运算符
if ($exact)
{
	$operate = " == ";
}
else
{
	$operate = " like ";
}

switch($qtype)
{
	case "keyWord":
		$doc = "name";
		break;
	case "author":
		$doc = "author";
		break;
	case "publish":
		$doc = "pub";	// 必须和数据库表对应
		break;
}

// 生成查询记录数的SQL语句
$query = "SELECT count(*) as total FROM book WHERE ".$subject.$operate.$doc;
$result = mysql_query($query) or die("无法执行SQL语句：$query!");
$row = mysql_fetch_array($result) or die("没有相关的记录！");
$rowcount = $row["total"];

mysql_free_result($result) or die("无法释放result资源！");

$pagecount = bcdiv($rowcount + $pagesize - 1, $pagesize, 0);

// 没有设置pageno时，缺省值为显示第1页
if (! isset($pageno))
{
	$pageno = 1;
}	
// 若pageno比1小时，则把它设置为1
if ($pageno < 1)
{
	$pageno = 1;
}
// 若pageno比总共的页数大，则把它设置为最后一页
if ($pageno > $pagecount)
{
	$pageno = $pagecount;
}

if ($pageno > 0)
{
	// 把$PHP_SELF转化为可以在URL上使用的字符串，这样就可以处理中文目录或文件名
	$href = eregi_replace("%2f", "/", urlencode($PHP_SELF));

	// 显示上一页的链接
	if ($pageno > 1)
	{
		echo "<a href = \"'.$href.'? pageno = '.($pageno - 1).'\"> 上一页 </a> &nbsp; &nbsp; &nbsp;";
	}
	else
	{
		echo "上一页 &nbsp; &nbsp; &nbsp;";
	}

	for ($i = 1; $i < $pageno; $i++)
	{
		echo "<a href = \"'.$href.'? pageno = '.$i.'\"> '.$i.' </a> &nbsp; &nbsp; &nbsp;";
	}

	echo $pageno."&nbsp; &nbsp; &nbsp;";

	for ($i = 1; $i <= $pagecount; $i++)
	{
		echo "<a href = \"'.$href.'? pageno = '.$i.'\"> '.$i.' </a> &nbsp; &nbsp; &nbsp;";
	}
	// 95-100 几行应该放进92行后面的for循环中！！！！！！？？？？

	// 显示下一页的链接
	if ($pageno < $pagecount)
	{
		echo "<a href = \"'.$href.'? pageno = '.($pageno + 1).'\"> 下一页 </a> &nbsp; &nbsp; &nbsp;"
	}
	else
	{
		echo "下一页 &nbsp; &nbsp; &nbsp;";
	}

	// 计算出本页的第一条记录在表中的位置
	$offset = ($pageno - 1) * $pagesize;
	$query = "SELECT * FROM book WHERE ".$subject.$operate.$doc;
	$query = "SELECT * FROM ".$query." LIMIT $offset, $pagesize";
	$result = mysql_query($query);
	$num_fields = mysql_num_fields($result);	// 取得字段总数
	$i = 0;
	while ($i < $num_fields)	// 取得所有字段的名字
	{
		$fields[$i] = mysql_field_name($result, $i);	// 取得第i+1个字段的名字
		$i++;
	}

	echo "<table border = 1 cellspacing = 0 cellpadding = 0>";	// 开始输出表格
	echo "<tr>";
	reset($fields);
	while (list(, $field_name) = each($fields))	// 显示字段名称
	{
		echo "<th> $field_name </th>";
	}
	echo "</tr>";

	while ($row = mysql_fetch_array($result))	// 显示本页数据
	{
		echo "<tr>";
		reset($fields);
		while (list(, $field_name) = each($fields))	// 显示每个字段值
		{
			$field_value = $row[$field_name];
			if ($field_value == "")
			{
				echo "<td> &nbsp; </td>";
			}
			else
			{
				echo "<td> $field_value </td>";
			}
		}
		echo "</tr>";
	}
	echo "</table>";	// 表格输出结束

	mysql_free_result($result) or die("无法释放result资源！");
}
else
{
	echo "没有任何数据记录！";
}

mysql_close($link) or die("无法与服务器断开连接！");

?>