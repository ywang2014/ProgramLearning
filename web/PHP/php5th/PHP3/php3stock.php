<html>
	<meta charset = 'utf-8'>
</html>

<?php 
// 用户股票信息 php3 version

page_open(array("sess" => "Custom_Session"));
// register session variable  Note: syntax
$sess->register('username');
$sess->register('stock1');
$sess->register('stock2');
$sess->register('stock3');
$sess->register('stock4');

// connect MySQL
$db = mysql_connect("hostlocal", "root", "root");

// select db
mysql_select_db("mydb", $db);

$username = $_SESSION['username'];

// use SQL query db
$query = "SELECT stock_pref1, stock_pref2, stock_pref3, stock_pref4 FROM stock_user_info WHERE username = '$username'";
$result = mysql_query($query, $db);

// get the stock code and session variable
list($_SESSION['stock1'], $_SESSION['stock2'], $_SESSION['stock3'], $_SESSION['stock4']);

echo "Hi $username! <br>";
echo "Your selected stocks are: <br>";
echo($_SESSION['stock1']);
echo("<br>");
echo($_SESSION['stock2']);
echo("<br>");
echo($_SESSION['stock3']);
echo("<br>");
echo($_SESSION['stock4']);
echo("<br>");

page_close();

?>