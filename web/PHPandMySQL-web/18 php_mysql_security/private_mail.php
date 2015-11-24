<?php
/*
	private_mail.php 
*/
?>
<!DOCTYPE html>
<html>
	<body>
		<h1> send me private mail </h1>
		
		<?php
		// 
		if ($_SERVER['SERVER_PORT'] != 443)
		{
			echo '<p style = "color: red"> WARNING: you have not connected to this page using SSL. '.
				'Your message could be read by others.</p>';
		}
		?>
		
		<form method = 'post' action = "send_private_mail.php">
			<p> your email address: <br />
				<input type = "text" name = "from" size = "40" />
			</p>
			
			<p> Subject: <br />
				<input type = "text" name = "title" size = "40"/>
			</p>
			
			<p>	your message: <br/>
				<textarea name = "body" cols = "30" rows = "10">
				</textarea>
			</p>
			
			<br />
			<input type = "submit" name = "submit" value = "send" />
		</form>
		
	</body>
</html>