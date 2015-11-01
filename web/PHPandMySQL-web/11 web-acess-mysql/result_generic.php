<?php
// result_generic.php  从MySQL数据库检索结果，并格式化显示
// 使用MDB2 


?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Book-o-Rama </title>
	</head>
	
	<body>
		<h1> Search Result </h1>
		
		<?php
			// create short variable name
			$searchtype = trim($_POST['searchtype']);
			$searchterm = trim($_POST['searchterm']);
			
			if (!$searchtype || !$searchterm)
			{
				echo "Your search infomation is not completed.".
					"Please try again.";
				exit;
			}
			
			if (!get_magic_quotes_gpc())
			{
				$searchtype = addslashes($searchtype);
				$searchterm = addslashes($searchterm);
			}
			
			// set up for using PEAR MDB2
			require_once("MDB2.php");
			$username = 'bookorama';
			$password = "bookorama123";
			$host = "localhost";
			$dbname = 'books';
			
			// set up universal connection string or DSN
			$dsn = "mysqli://".$user.":".$password."@".$host."/".$dbname;
			
			// connect to database
			$db = &MDB2::connect($dsn);
			
			// check if connection worked
			if (MDB2::isError($db))
			{
				echo $db->getMessage();
				exit;
			}
			
			// perform query
			$query = "select * from books where ".$searchtype." like '%".$searchterm."%'";
			
			$result = $db->query($query);
			
			// check that result was ok
			if (MDB2::isError($result))
			{
				echo $db->getMessage();
				exit;
			}
			
			// get number of returned rows
			$num_results = $result->numRows();
			
			// display each returned row 
			for ($i = 0; $i < $num_results; $i++)
			{
				$row = $result->fetchRow(MDB2_FETCHMODE_ASSOC);
				
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
			
			// disconnect from database
			$db->disconnect();
		
		?>
	</body>
</html>
