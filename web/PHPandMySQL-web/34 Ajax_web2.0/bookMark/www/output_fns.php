<?php
/*
	输出HTML
	
	do_html_header()
	do_html_footer()
	display_site_info();
	display_login_form();
*/

// 修改的函数 导入 *.css *.js文件，支持Ajax
function do_html_header($title)
{
	// print an HTML header
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
					font-size: 16px;
				}
				
				li, td
				{
					font-family: Arial, Helvetica, sans-serif; 
					font-size: 16px;
				}
				
				hr
				{
					color: #3333cc;
					width = 300px;
					text-align: left;
				}
				
				a 
				{
					color: #2233aa;
					text-decoration: none;
				}
				
				a:hover 
				{
					color: #f00;
					text-decoration: none;
				}
				
				p
				{
					padding-top:10px;
					padding-bottom:10px;
				}
			</style>
			
			<link rel = "stylesheet" type = "text/css" href = "../new_ss.css" />
			<script src = "../new_ajax.js" type = "text/javascript"> </script>
			
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
}

function do_html_footer()
{
	echo "<div style = \"width:98%; padding:0px; position:absolute; bottom:0px; text-align:center; border:1px solid #ddd; background-color:#ddd; \">";
	echo "<br>";
	echo "<p > You should follow our <a href = \"\"> \"service agreement\" </a> </p>";
	echo "<p > All rights reserved &copy ywang_ltd </p>";
	echo "<br>";
	echo "</div>";
	
}

function do_html_err($str)
{
	?>
	<div style = "width:80%; border:1px solid #f22; background-color:#eff; padding:10px; margin:20px auto;">
		<p>
			<font style = "font-size:18px; font-weight:bold; color:#a33;"> <?php echo $str; ?> </font> <br />
			<a href = "<?php echo $_SERVER['HTTP_REFERER']; ?>"> Back </a>
		</p>
	</div>
	<?php 
}

function do_html_url($url, $urlname)
{
	echo "<a href = \"".$url."\"> ".$urlname." </a>";
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
	<style>
	input:-webkit-autofill 
	{
		-webkit-box-shadow: 0 0 0px 1000px white inset;
			border: 1px solid #CCC!important;
	}
	
	</style>
	<br />
	<a href = "register_form.php"> Not a member? </a> <br>
	<table style = "background-color:#ddd">
	<form action = "member.php" method = "post">
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
				<input type = "text" name = "username" value = "" placeholder = "username" />
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
				<input type = "submit" value = "Log in" style = "width:150px; height:30px; background-color:#a8e;"/>
			</td>
		</tr>
	</form>
		<tr>
			<td >
				<a href = "forgot_password_form.php" > <strong> Forgot your password? </strong> </a>
			</td>
		</tr>
	</table>
	<?php 
}

function display_index_menu()
{
	?>
	<br />
	<a href = "register_form.php"> Not a member? </a> <br />
	<a href = "login.php"> Login </a> <br />
	<a href = "forgot_password_form.php" > Forgot your password? </a> <br />
	
	<a href = "member.php" > User Page </a> <br />
		
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
					Password:<br>
					<font style = "font-size:12px; color:#aaa;"> (between 6 and 32 chars) </font>
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
	<form method = "post" action = "change_password.php">
		<table style = "background-color:#ddd">
			<tr>
				<td>
					Old password:
				</td>
				<td>
					<input type = "password" name = "old_password" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					New password:
				</td>
				<td>
					<input type = "password" name = "new_password" value = "" />
				</td>
			</tr>
			<tr>
				<td>
					Repeat new Password:
				</td>
				<td>
					<input type = "password" name = "new_password2" value = "" />
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
	<form method = "post" action = "forgot_password.php">
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


// 修改 支持Ajax
function display_add_bm_form()
{
	?>
	<script type = "text/javascript">
		var myReg = getXMLHTTPRequest();
	</script>
	
	<form >
		<table width = "250" cellpadding = "2" cellspacing = "0" style = "background-color:#CCC">
			<tr>
				<td>
					New BM:
				</td>
				<td>
					<input type = "text" name = "new_url" value = "http://" size = "30" maxlength = "255"
						placeholder = "http://www.helloworld.com"/>
				</td>
			</tr>
			<tr>
				<td colspan = 2 align = "center">
					<input type = "button" value = "Add bookmark" onclick = "javascript:addNewBookmark(); " />
				</td>
			</tr>
		</table>
	</form>
	<?php
}

function display_delete_bm_form($username)
{
	?>
	<form action = "delete_bms.php" method = "post">
	<?php
	if ($url_array = get_user_urls($username))
	{
		display_user_urls_del($url_array);
	}
	?>
		&nbsp; &nbsp; &nbsp; <input type = "submit" value = "Confirm" style = "width:80px; background-color:#ff2; border:1px solid #333; "/>
	</form>
	<?php 
	
}

function display_user_menu()
{
	?>
	
	<br> <hr /> <br>
	<table>
		<tr>
			<td>
				<a href = "index.php"> Home </a>
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

// 删除使用
function display_user_urls_del($url_array)
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
						<input type = "checkbox" name = "del_bm[]" value = "<?php echo $url; ?>">
					</td>
				</tr>
			<?php
			} 
	echo "</table>";
}


// 显示使用
function display_user_urls($url_array)
{
	?>
	<table>
		<tr>
			<td width = "200">
				<strong> Bookmark </strong>
			</td>
		</tr>
		<?php
			foreach ($url_array as $url)
			{ ?>
				<tr>
					<td>
						<a href = "<?php echo $url; ?>"> <?php echo $url; ?> </a>
					</td>
				</tr>
			<?php
			} 
	echo "</table>";
}

?>