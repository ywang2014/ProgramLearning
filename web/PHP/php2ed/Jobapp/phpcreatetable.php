<html>
	<head>
		<title> 在MYSQL数据库中，内建一张新表并写入数据 </title>
	</head>
	<body>
		<?php 
		$host = "localhost";	// 设置数据库的位置
		$user = "root";			// 设置数据库的名字
		$password = "root";		// 设置数据库密码
		$my_connect = mysql_connect($host, $user, $password);	// 连接数据库
		if ($my_connect)		// 判断是否已经连接上
		{
			echo "succeed!<br>";
			// <br> 用于换行
		}
		$resule = mysql_list_dbs($my_connect);	// 列出所有数据库
		$db_num = mysql_num_rows($resule);		// 统计数据库的个数
		echo $db_num;	// 输出数据库的个数
		echo "<br>";
		while ($dbs = mysql_fetch_array($resule))	// 比较所有的结果
		{
			echo $dbs[Database];		// 输出各个符合条件的数据库名称
			echo "<br>";
		}
		$table = mysql_list_tables("mysql", $my_connect);	// 理出所有mysql数据库里面的数据表
		$table_num = mysql_num_rows($table);	// 返回数据表个数
		echo $table_num;	// 输出个数
		$sql = "create table student3(
		id int(3) auto_increment not null primary key,	// auto_increment 为自动增加，not null为不能为空，primary key 为定义主键
		name char(10) not null)";
		mysql_select_db("mysql", $my_connect);	// 选择数据库
		$do = mysql_query($sql, $my_connect);	// 对数据库进行增加数据表操作
		if ($do)
		{
			echo "succeed!";
			echo "<br>";
		}
		else
		{
			echo "failed!";
		}
		mysql_close($my_connect);	// 关闭数据库
		?>
	</body>
</html>
<!-- 方法二： -->
<?php
require("conn.php");
$sql = "create table lunzitest";
$sql .= "(id int not null auto_increment primary key,";
$sql .= "time varchar(20),";
$sql .= "name varchar(20),";
$sql .= "title varchar(50),";
$sql .= "messages text)"; 
echo "$sql\n";
$out = mysql_query($sql);
if ($out)
{
	echo ("ok!");
}
else
{
	printf("no!");
}
?>
<!-- conn.php -->
<?php 
$conn = mysql_connect("localhost", "mis", "miss") or die("failed to access the server");

$sql = mysql_select_db("joke") or die("select table failed");
?>