<meta charset = 'utf-8'>

<?php
// 5.4

session_start();
if (session_is_register('username'))	// 检查变量是否注册
{
	echo "A session variable by the name \"username\" already exists";
}
else
{
	echo "No variable named \"username\" registered yet.Registering...";
	session_register('username');
}
?>

<?php 
// 5.5

session_start();
session_register('someString');
$_SESSION['someString'] = "I have a dream!";

// 将所有的session变量编成一个字符串
$seesStr = session_encode();

// visualization
echo $seesStr;
echo "<br><br>";

// string replace
$seesStr = ereg_replace("dream", "ideal", $seesStr);

// decode the update string
session_decode($seesStr);

echo $_SESSION['someString'];

?>

<!-- All the session's examples have used the sookies to save the session_id
	 What happends if the user's browser is unable to use cookies?
	 
	 put the session_id into a URL to transmit from one page to another. 
 -->
<A href = "http://www.baidu.com/index.php? PHPSESSID = <?echo "$PHPSESSID"; ?>" >
	Edit Your Protfolio! 
</A>