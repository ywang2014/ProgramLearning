<html>
	<head>
		<title> Bob's Auto Parts - Order Results </title>
	</head>
	<body>
		<h1> Bob's Auto Parts </h1>
		<h2> Order Results </h2>
		<?php
			// create short variable name
			$tireqty = $_POST["Tireqty"];
			$oilqty = $_POST['Oilqty'];
			$sparkqty = $_POST['Sparkqty'];
			
			echo "<p> Order Processed at ";
			echo date("H:i:s, jS F Y");
			echo " </p>";
			
			// 链接形式 "."
			echo "<p> Your order is as follow: </p>";
			echo $tireqty." tires <br/>";
			echo $oilqty." bottles of oil <br/>";
			echo $sparkqty." spark plugs <br/>";
		?>
	</body>
</html>