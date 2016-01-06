<?php
/*
	输出HTML
	
	do_html_header()
	do_html_footer()
	display_site_info();
	display_login_form();
*/

function do_html_header($title)
{
	?>
	<!DOCTYPE html>
	<html>
		<head>
			<meta http-equiv = "Content-type" content = "text/html; charset = utf-8" />
			<title> <?php echo $title; ?> </title>
			<style>
				*
				{
					margin: 0px;
					padding: 0px;
				}
				
				body
				{
					padding-left: 20px;
					font-family: Arial, Helvetica, sans-serif; 
					font-size: 13px;
				}
				
				li, td
				{
					font-family: Arial, Helvetica, sans-serif; 
					font-size: 13px;
				}
				
				hr
				{
					color: #3333cc;
					width = 300px;
					text-align: left;
				}
				
				a 
				{
					color: #000000;
					text-decoration: none;
				}
				
				a:hover 
				{
					color: #f00;
					text-decoration: none;
				}
			</style>
		</head>
		
		<body>
			<div >
				<img src = "images/logo.jpg" alt = "PHPbookmark logo" border = 0 align = "left" valign = "bottom" height = "55" width = "57" />
				<h1 style = "padding:10px;"> PHPbookmark </h1>
				<hr />
			</div>
			<?php
				if ($title)
				{
					do_html_heading($title);
				}
}

function do_html_heading($title)
{
	
	echo "<br> <h3> $title </h3>";
	if (isset($_SESSION['valid_user']))
	{
		echo "<p> Logged in as ".$_SESSION['valid_user']."</p>";
	}
}

function do_html_footer()
{
	echo "<p align = \"center\"> You should follow our <a href = \"\"> service agreement </a> </p>";
	echo "<p align = \"center\"> All rights reserved &copy ywang_ltd </p>";
}

function display_site_info()
{
	?>
	<div style = "padding:20px;">
		<ul style = "padding-left:50px;">
			<li> Store your bookmarks online with us </li>
			<li> See what other users use </li>
			<li> Share your favorite links with others </li>
		</ul>
	</div>
	<?php 
}

function display_login_form()
{
	?>
	<a href = "register_form.php"> Not a member? </a> <br>
	<table style = "background-color:#ddd">
		<tr>
			<td colspan = 2>
				<strong> Member log in here </strong>
			</td>
		</tr>
		<tr>
			<td >
				<strong> Username </strong>
			</td>
			<td>
				<input type = "text" name = "username" value = "" placeholder = "username"/>
			</td>
		</tr>
		<tr>
			<td >
				<strong> Password </strong>
			</td>
			<td>
				<input type = "password" name = "password" value = "" />
			</td>
		</tr>
		<tr>
			<td colspan = 2 align = "center">
				<input type = "submit" value = "Log in" />
			</td>
		</tr>
		<tr>
			<td >
				<a href = "forgot_password_form.php" > <strong> Forgot your password? </strong> </a>
			</td>
		</tr>
	</table>
	<?php 
}


function display_registration_form()
{
	?>
	<form method = "post" action = "register_new.php">
		<table>
			<tr>
				<td>
					Email address:
				</td>
				<td>
					<input type = "text" name = "email" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					Prefered username:
				</td>
				<td>
					<input type = "text" name = "username" value = "" placeholder = "(max 30 chars)"/>
				</td>
			</tr>
			<tr>
				<td>
					Password:
					<font style = "font-size:10px; color:#ddd;"> (between 6 and 32 chars) </font>
				</td>
				<td>
					<input type = "password" name = "password" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					Confirm password:
				</td>
				<td>
					<input type = "password" name = "password2" value = "" />
				</td>
			</tr>
			<tr>
				<td colspan = 2 align = "center">
					<input type = "submit" value = "Register" />
				</td>
			</tr>
		</table>
	</form>
	<?php
}


function display_change_password_form()
{
	?>
	<form method = "post" action = "register_new.php">
		<table style = "background-color:#ddd">
			<tr>
				<td>
					Old password:
				</td>
				<td>
					<input type = "password" name = "oldpassword" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					New password:
				</td>
				<td>
					<input type = "password" name = "newpassword" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					Repeat new Password:
				</td>
				<td>
					<input type = "password" name = "newpassword2" value = "" />
				</td>
			</tr>
			<tr>
				<td colspan = 2 align = "center">
					<input type = "submit" value = "Change password" />
				</td>
			</tr>
		</table>
	</form>
	<?php
}


function display_forgot_password_form()
{
	?>
	<form method = "post" action = "register_new.php">
		<table style = "background-color:#ddd">
			<tr>
				<td>
					Enter your username:
				</td>
				<td>
					<input type = "text" name = "username" value = "" placeholder = "username"/>
				</td>
			</tr>
			<tr>
				<td colspan = 2 align = "center">
					<input type = "submit" value = "Change password" />
				</td>
			</tr>
		</table>
	</form>
	<?php
}

function display_add_bm_form()
{
	?>
	<form method = "post" action = "register_new.php">
		<table style = "background-color:#ddd">
			<tr>
				<td>
					New BM:
				</td>
				<td>
					<input type = "text" name = "username" value = "http://" placeholder = "http://www.helloworld.com"/>
				</td>
			</tr>
			<tr>
				<td colspan = 2 align = "center">
					<input type = "submit" value = "Add bookmark" />
				</td>
			</tr>
		</table>
	</form>
	<?php
}


function display_user_menu()
{
	?>
	<hr />
	<table>
		<tr>
			<td>
				<a href = "login.php"> Home </a>
				&nbsp;|&nbsp;
				<a href = "add_bm_form.php"> Add BM </a>
				&nbsp;|&nbsp;
				<a href = "delete_bm_form.php"> Delete BM </a>
				&nbsp;|&nbsp;
				<a href = "change_password_form.php"> Change password </a>
			</td>
		</tr>
		<tr>
			<td>
				<a href = "recommend.php"> Recommend URLs to me </a>
				&nbsp;|&nbsp;
				<a href = "logout.php"> Logout </a>
			</td>
		</tr>
	</table>
	</hr>
	<?php
}

function display_user_urls($url_array)
{
	?>
	<table>
		<tr>
			<td width = "200">
				<strong> Bookmark </strong>
			</td>
			<td>
				<strong> Delete? </strong>
			</td>
		</tr>
		<?php
			foreach ($url_array as $url)
			{ ?>
				<tr>
					<td>
						<a href = "<?php echo $url; ?>"> <?php echo $url; ?> </a>
					</td>
					<td>
						<input type = "checkbox" name = "del_bm" value = "<?php echo $url; ?>">
					</td>
				</tr>
			<?php
			} 
	echo "</table>";
}


?>