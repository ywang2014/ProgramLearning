<html>
	</head>
		<meta charset = "utf-8">
		<title> ProcessorProgram </title>
	</head>
	
	<body>
		<?php
		echo "<h1> Bob's Auto Parts </h1>";
		echo "<hr>";
		
		echo "<h2> Order Results </h2>";
		
		$tireqty = $_POST["tire"];
		$oilqty = $_POST["oil"];
		$sparkqty = $_POST["spark"];
		$address = $_POST["address"];
		
		$total = $tireqty + $oilqty + $sparkqty;
		
		if ($total <= 0)
		{
			echo "<p style = \"color: red\">";
			echo "You did not order anything on the previous page! <br />";
			echo "</p>";
			echo "<script> alert('订单不能全部为空，请返回重填'); history.go(-1); </script>";
		}
		else
		{
			if ($address == "")
			{
				echo "<p style = \"color: red\">";
				echo "Your address can not be none! <br />";
				echo "</p>";
				echo "<script> alert('订单地址不能为空，请返回重填'); history.go(-1); </script>";
			}
		}
		
		echo "<p> Order processed at ".date("H:i, F JS Y")."</p>";
		
		echo "Your order is as follow: <br> <br>";
		
		echo "Items ordered ".$total."<br>";
		echo $tireqty." tires <br>";
		echo $oilqty." bottles of oil <br>";
		echo $sparkqty." spark plugs <br>";
		
		$totalamount = 0.0;
			
		define('TIREPRICE', 100);
		define('OILPRICE', 10);
		define('SPARKPRICE', 4);
			
		$totalamount = $tireqty * TIREPRICE
						+ $oilqty * OILPRICE
						+ $sparkqty * SPARKPRICE;
		echo "<br> Subtotal of order is $".number_format($totalamount, 2)."<br />";
		
		echo "<br> Address to ship to is ".$address;
		
		@$fp = fopen("orderFile/order.txt", "ab");
		if (!$fp)
		{
			echo "<p> <strong> Your order could not be processed at this time. Please try again later. </strong> </p>";
			exit();
		}
		
		?>
	</body>
</html>