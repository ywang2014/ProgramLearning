<?php
// check.php

// 连接数据库
$link = mysql_connect(localhost, username, password);
if ($link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库连接错误！')";
	echo "</script>";
	exit();
}

// 激活需要使用的数据库
if (mysql_select_db(exam, $link) == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('Exam 激活数据库失败!')";
	echo "</script>";
	exit();
}

$query = "SELECT examid FROM answer WHERE name = $exam_man";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库操作失败!')";
	echo "</script>";
	exit();
}

$result = mysql_fetch_row($result_link);

// 查询考生准考证号
if ($result != $exam_pas)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('准考证号不对!')";
	echo "</script>";
	exit();
}

// 核对准证号
if (mysql_select_db(answer, $link) == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('Answer 激活数据库失败!')";
	echo "</script>";
	exit();
}

$query = "SELECT * FROM answer";
$result_link = mysql_query($query, $link);
if ($result_link == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库操作失败!')";
	echo "</script>";
	exit();
}
$result = mysql_fetch_row($result_link);
if ($result == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('读取数据失败!')";
	echo "</script>";
	exit();
}

// 得到第一题的题数
$number = mysql_num_rows($result);

$mark = 0;
for ($i = 0; $i <= $number; $i++)
{
	$query_key = "SELECT key,stand FROM answer WHERE no = 1";
	
	// 查询第i题的答案和分值
	$result_link = mysql_query($query_key, $link);
	if ($result == 0)
	{
		echo "<script language = 'JavaScript'>";
		echo "alert('数据库操作失败!')";
		echo "</script>";
		exit();
	}
	$result_key = mysql_fetch_row($result_link);
	
	$key = $result_key['key'];
	$stand = $result_key['stand'];
	
	// 将查询结果转为需要的类型
	for ($j = 1; $j <= 6; $j++)
	{
		$answer[] = "I".string($i * 10 + $j);
		$correct[] = substr($key, I - 1, i);
		$answer[] = $correct[];
	}
	
	echo "<?php";
	echo "if (";
	for ($j = 0; $j <= 5; $j++)
	{
		if (empty($correct[$j]))
		{
			if (empty($m))
			{
				echo "(empty($answer[$j]))";
				$m = $j;
			}
			else
			{
				echo "&&";
				echo "(empty($answer[$j]))";
			}
		}
	}
	echo ")\n";
	echo "{\n//错误选项}";
	echo "if(";
	for ($j = 0; $j <= 5; $j++)
	{
		if (!empty($correct[$j]))
		{
			if(empty($m))
			{
				echo "(! empty($answer[$j]))";
				$m = $j;
			}
			else
			{
				echo "||";
				echo "(! empty($answer[$j]))";
			}
		}
	}
	echo ")\n";
	echo "{\n //正确}";
	echo "if(";
	for ($j = 0; $j <= 5; $j++)
	{
		if (!empty($correct[$j]))
		{
			if(empty($m))
			{
				echo "(! empty($answer[$j]))";
				$m = $j;
			}
			else
			{
				echo "&&";
				echo "(! empty($answer[$j]))";
			}
		}
	}
	echo ")\n";
	echo "{ \n";
	echo "$mark_list = $stand; \n";
	echo "{ \n";
	echo "else";
	echo "{ \n";
	echo "$mark_list = 0.5 * $stand; \n";
	echo "} \n";
	echo "} \n";
	echo "} \n";
	echo "?>"
	// 生成动态PHP代码，判定考生答案
	
	$mark += $mark_list;
	// 加上得分
}

echo "第二题：";
for ($i = 1; $i <= $n2_ge_num; $i++)	// 从数据库中，读取第二题题目个数
{
	$name = "II".(string)$i;
	$mark += $name;
	// 小题得分
}

echo "第三题：";
for ($i = 1; $i <= $n3_ge_num; $i++)	// 从数据库中，读取第二题题目个数
{
	$name = "III".(string)$i;
	$mark += $name;
}

if (mysql_select_db(exam, $link) == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('Exam 激活数据库失败!')";
	echo "</script>";
	exit();
}

// 将分数存入数据库
$update = "UPDATE exam SET mark = $mark WHERE name = $exam_man";
$result = mysql_query($update, $link);
if ($result == 0)
{
	echo "<script language = 'JavaScript'>";
	echo "alert('数据库操作失败!')";
	echo "</script>";
	exit();
}
else
{
	echo "<script language = 'JavaScript'>";
	echo "alert('阅卷完毕!')";
	echo "</script>";
	exit();
}
?>
