<?php
// vieworder2.php 分离、格式化并显示订单内容

$DOCUMENT_ROOT = $_SERVER["DOCUMENT_ROOT"];

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Customer Orders </title>
	</head>
	
	<body>
		<h1> Bob's Auto Parts - Customer Orders </h1>
		<?php
			// Read in the entire file: echo order become an element in the array
			$orders = file("DOCUMENT_ROOT/../orders/orders.txt");
			
			// count the number of orders in the array
			$number_of_orders = count($orders);
			
			if ($number_of_orders == 0)
			{
				echo "<p> <strong> No orsers pending. Please try again later. </strong> </p>";
			}
			echo "<table border = 1> \n";
			echo "<tr> <th bgcolor = \"#ccccff\"> Order Date </th>
						<th bgcolor = \"#ccccff\"> Tires </th>
						<th bgcolor = \"#ccccff\"> Oil </th>
						<th bgcolor = \"#ccccff\"> Spark Plugs </th>
						<th bgcolor = \"#ccccff\"> Total </th>
						<th bgcolor = \"#ccccff\"> Address </th>
					<tr>";
			for ($i = 0; $i < $number_of_orders; $i++)
			{
				// split up each line
				$line = explode("\t", $orders[$i]);
				
				// keep only the number of items ordered
				$line[1] = intval($line[1]);
				$line[2] = intval($line[2]);
				$line[3] = intval($line[3]);
				
				// output each order
				echo "<tr>
							<td>".line[0]."</td>
							<td> align = \"right\">".$lin[1]."</td>
							<td> align = \"right\">".$lin[2]."</td>
							<td> align = \"right\">".$lin[3]."</td>
							<td> align = \"right\">".$lin[4]."</td>
							<td>".$line[5]."</td>
						</tr>";
			}
			echo "</table>";
		?>
 	</body>
</html>