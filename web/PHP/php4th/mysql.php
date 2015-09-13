<?php
/* PHP and MySQL  */

// 如果没有参数 link_identifier，则默认为最近打开的一个连接
?>

<?php
// 1.建立与数据库服务器的链接
	// 用root连接到本地MySQL数据库服务器，用户密码“123”
$link_us = mysql_connect("localhost", "root", "123") or die("很抱歉，数据库连接失败！");

// 函数原型
// int mysql_connect(string [hostname][:port], string [username], string [password]);
?>

<?php
// 建立数据库
	// 如果连接成功，则可以创建一个数据库
mysql_create_db("mydb", $link_us);

// 函数原型
// int mysql_create_db(string databasename, int [link_identifier]);
?>

<?php
// 删除数据库
mysql_drop_db("mydb", $link_us);

// 函数原型
// int mysql_drop_db(string databasename, int [link_identifier]);
?>

<?php
// 建立数据表
	// 4.1 建立一个五个字段的数据表，记录同学的基本信息
$link = mysql_select_db("mydb", $link_us);
$tab = mysql_query("CREATE TABLE classmates(
												id INT NOT NULL AUTO_INCREMENT,
												name CHAR(10),
												age INT,
												tel VARCHAR(20),
												addr VARCHAR(30),
												PRIMARY KEY (id))",
												$link);
if ($tab)
{
	echo "数据表";
	echo(classmates);
	echo "建立成功！";
}
else
{
	echo "数据表建立失败! ";
}

// 使用select语句，结果标识是一个指向结果的指针(整数)

?>

<?php
// 添加新记录
	// 4.2 向新建的表中添加数据
$name = "Alice";
$age = 20;
$tel = "0731-4216354";
$addr = "Wuxi, China";
if ($link = mysql_select_db("mydb", $link_us))
{
	echo "Succeed!";
}
else
{
	echo "Failed!";
}

$ins = mysql_query("INSERT INTO students(name, age, tel, addr)
					VALUES('$name', $age, '$tel', '$addr')", $link);
if ($ins)
{
	echo "Insert Succeed!";
}
else
{
	echo "Insert failed!";
}

?>

<?php
// 浏览数据库表
	// 4.3 显示数据库数据，能够做到与用户交互
?>

<table border = 1 width = 500 bgcolor = white>
	<tr align = center bgcolor = #ffe0f0>
		<td> 姓名 </td>
		<td> 年龄 </td>
		<td> 电话 </td>
		<td> 住址 </td>
	</tr>
	
<?php
$link = mysql_select_db("mydb", $link_us);
$q = mysql_query("SELECT * FROM classmates ORDER BY age DESC", $link_us);
while ($a = mysql_fetch_array($q))	// 以关联数组的形式取出数据行
{
	print("<tr>
				<td> $a[name] </td>
				<td> $a[age] </td>
				<td> $a[tel] </td>
				<td> $a[addr] </td>
			</tr>");
}
?>

</table>


