<meta charset = 'utf-8'>

<?php 
/* stock_user_info 表在数据库中，用于存储用户的用户名(唯一的)和四只股票
*  session 被初始化之后，注册变量保存用户名和股票信息，同数据库进行连接，并取回值显示在页面上
*/

// create a session
session_start();

// register session varable
	// username
session_register('username');
	// choose the stock varable
session_register('stock1');
session_register('stock2');
session_register('stock3');
session_register('stock4');

// connect MySQL
$link = mysql_connect("localhost", "root", "root");

// choose database
mysql_select_db("mydb", $link);

// use SQL query the DBase
$name = $_SESSION['username'];
$query = "SELECT stock_pref1, stock_pref2, stock_pref3, stock_pref4 FROM stock_user_info WHERE username = '$name'";
$result = mysql_query($query, $link);

// get the ticker symbol from the DataBase, and assign values to varables
list($_SESSION['stock1'], $_SESSION['stock2'], $_SESSION['stock3'], $_SESSION['stock4']) = mysql_fetch_row($result);

echo "Hi $name! <br>";
echo "Your selected stocks are: <br>";
echo $_SESSION['stock1'];
echo "<br>";
echo $_SESSION['stock2'];
echo "<br>";
echo $_SESSION['stock3'];
echo "<br>";
echo $_SESSION['stock4'];
echo "<br>";

?>