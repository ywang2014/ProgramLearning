<?php
/*
	insert_book.php  将新的图书写入到数据库
*/

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Book-O-Rama </title>
	</head>
	
	<body>
		<h1> Entry Results </h1>
		<?php
			// create short variable names
			$isbn = trim($_POST['isbn']);
			$author = trim($_POST['author']);
			$title = trim($_POST['title']);
			$price = trim($_POST['price']);
			
			if (!$isbn || !$author || !$title || !$price)
			{
				echo "You have not entryed all the required details <br>".
					"Please go back and try again.";
				exit;
			}
			
			if (!get_magic_quotes_gpc())
			{
				$isbn = addslashes($isbn);
				$author = addslashes($author);
				$title = addslashes($title);
				$price = doubleval($price);	// 除去所有临时字符，以浮点数形式保存
			}
			
			@$db = new mysqli($localhost, $username, $password, $dbname);
			
			if (mysqli_connect_errno())
			{
				echo "Error: Could not connect to database. Please try again later.";
				exit;
			}
			
			$query = "insert into books values ('$isbn', '$author', '$title', $price)";
			
			$result = $db->query($query);
			
			if ($result)
			{
				echo $db->affected_rows." book insert into database.";
			}
			else
			{
				echo "An error has occurred. The item was not added.";
			}
			
			$db->close();
		
		?>
	</body>
</html>