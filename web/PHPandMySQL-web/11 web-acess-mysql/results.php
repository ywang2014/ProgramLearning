<?php
// result.php  从数据库获取格式化搜索结果


?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> BOOK_O_RAMA </title>
		<script type = "text/javascript">
		
		</script>
		
		<style type = "text/css">
		
		</style>
	</head>
	
	<body>
		<h1> Search Results </h1>
		
		<?php
			// create short variable names
			$searchtype = $_POST['searchtype'];
			$searchterm = trim($_POST['searchterm']);
			if (!$searchtype || !$serchterm)
			{
				echo "You have not entered search informations. Please try again.";
				exit;
			}
			
			if (!get_magic_quotes_gpc())
			{
				$searchtype = addslashes($searchtype);
				$searchterm = addslashes($searchterm);
			}
			
			@$db = new mysqli('localhost', 'bookorama', 'bookorama123', 'books');
			
			if (mysqli_connect_errno())
			{
				echo "Error: Could not connect to database. Please try again later.";
				exit;
			}
			
			$query = "select * from books where ".$searchtype." like '%".$searchterm."%'";
			$result = $db->query($query);
			
			$num_results = $result->num_rows;
			
			echo "<p>Number of books found: ".$num_results."</p>";
			
			for ($i = 0; $i < $num_results; $i++)
			{
				$row = $result->fetch_assoc();
				echo "<p> <strong>".($i+1).". Title: ";
				echo htmlspecialchars(stripslashes($row['title']));
				echo "</strong> <br> Author: ";
				echo stripslashes($row['author']);
				echo "<br> ISBN: ";
				echo stripslashes($row['isbn']);
				echo "<br> Price: ";
				echo stripcslashes($row['price']);
				echo "</p>";
			}
			
			$result->free();
			$db->clsoe();
		
		?>
	</body>
</html>