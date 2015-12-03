<?php
/*
	身份验证程序
*/

session_start();
$key = 'youarehacker!';

if (isset($_POST['userid']) && isset($_POST['password']))
{
	$userid = trim($_POST['userid']);
	$password = trim($_POST['password']);
	$password = md5($password.$key);
	
	$conn = mysql_connect('localhost', 'admin', 'admin') or die ('Can not connect the database!');
	@mysql_select_db('wuliu', $conn);
	
	$sql = "select * from users where username = '$userid' and password='$password'";
	$result = mysql_query($sql, $conn);
	$num = mysql_num_rows($result);
	if ($num > 0)
	{
		$_SESSION['user'] = $userid;
	}
	mysql_close($conn);
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8" />
		<title> Home Page </title>
	</head>>
	
	<body>
		<?php
			if (isset($_SESSION['user']))
			{
				echo "You are logged in as: ".$_SESSION['user']."<br />";
				echo "<a href = \"logout.php\"> Logout </a> <br>";
			}
			else
			{
				if (isset($userid))
				{
					echo "Could not log you in<br>";
				}
				else
				{
					echo "You are not logged in <br>";
				}
				?>
				<form action = "" method = "post">
					<table>
						<tr>
							<td>
								Userid:
							</td>
							<td>
								<input type = "text" name = "userid" value = "">
							</td>
						</tr>
						<tr>
							<td>
								Password:
							</td>
							<td>
								<input type = "password" name = "password" value = "">
							</td>
						</tr>
						<tr>
							<td colspan = 2 align = "center"> 
								<input type = "submit" value = "login" style = "width:200px; height:30px; border:0px solid #fff; background-color:#34d;">
							</td>
						</tr>
					</table>
				</form>
			<?php
			}
		?>
		<br>
		<a href = "users.php"> User page </a>
	</body>
</html>