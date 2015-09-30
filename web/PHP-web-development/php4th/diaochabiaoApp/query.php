<meta charset = "utf-8">

<?php
// query.php

include "common.php";
mysql_connect($hostname, $username, $password) or die("Unable to connect database");
mysql_select_db("$dbname") or die("Unable to select database");

// 获取所有参加调查的记录数目，并显示
$q = "SELECT * FROM $userstable";
$r = mysql_query($q);
$total = mysql_num_rows($r);
printf("<center> 到您为止，总共有%d人参加调查.", $total);

// 查询有多少男性用户
$query = "SELECT * FROM $userstable WHERE sex = 'man'";
$result = mysql_query($query);
$man = mysql_num_rows($result);

// 显示查询结果中的男女比例
if ($man == 0)
{
	print "<center> <p> 很遗憾，没有男士上网记录。</p></center>";
}
else
{
	printf("<center> <p> 上网的人中男士占：%.1f/100 <br>", ($man * 100.0) / $total);
}
if ($man == $total)
{
	print "<center> <p> 很遗憾，没有女士上网记录。</p></center>";
}
else
{
	printf("<center> <p> 上网的人中女士占：%.1f/100 <br><br>", (($total - $man) * 100.0) / $total);
}

// 查询调查中有多少16-25岁的网民：
$query = "SELECT * FROM $userstable WHERE age = 20";
$result = mysql_query($query);
$age20 = mysql_num_rows($result);
printf("<p> 网民中16-25岁的占：%.1f/100 <br><br>", ($age20 * 100.0) / $total);

// 查询调查中有多少是在家里上网的
$query = "SELECT * FROM $userstable WHERE place = 'home'";
$result = mysql_query($query);
$surfinhome = mysql_num_rows($result);
printf("<p> 网民在家中上网的占：%.1f/100<br><br>", ($surfinhome * 100.0) / $total);
print "</center>";

?>

<p> <br> <br>
	<a href = "diaochabiao.html" > 首页 </a>
</p>