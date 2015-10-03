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
			$find = $_POST['find']
			
			$totalqty = 0;
			$totalqty = $tireqty + $oilqty + $sparkqty;
			
			/*
			php实现返回上一页的功能的3种有效方法

				header("Location:orderform.html");				// 返回页面的路径：orderform.html   // 直接返回，没有提示，不好！看不见前面的代码执行情况

				header("location:".getenv("HTTP_REFERER"));		// 返回其调用页面					// 直接返回，没有提示，不好！看不见前面的代码执行情况

				echo "<script> alert('随便写点什么'); history.go(-1); </script>";  					// 有提示界面，非常友好。
			*/
			if (totalqty <= 0)
			{
				echo "<p style = \"color: red\">";
				echo "You did not order anything on the previous page! <br />";
				echo "</p>"
				echo "<script> alert('订单不能全部为空，请返回重填'); history.go(-1); </script>";
			}
			else
			{
				echo "<p> Order Processed at ";
				echo date("H:i:s, F jS Y");
				echo " </p>";
				
				echo "<p> Your order is as follow: </p>";
				if ($tireqty > 0)
				{
					echo $tireqty." tires <br/>";
				}
				if ($oilqty > 0)
				{
					echo $oilqty." bottles of oil <br/>";
				}
				if ($sparkqty > 0)
				{
					echo $sparkqty." spark plugs <br/>";
				}
			}
			
			echo "Items ordered: ".$totalqty."<br />";
			
			//$dir = `dir c:`;	// 执行操作符，执行服务器端命令：一对反向引号(``)(~同键)
			//$dir = `ls -la`;
			//echo $dir;
			//PHPinfo();
			
			$totalamount = 0.0;
			
			define('TIREPRICE', 100);
			define('OILPRICE', 10);
			define('SPARKPRICE', 4);
			
			$totalamount = $tireqty * TIREPRICE
							+ $oilqty * OILPRICE
							+ $sparkqty * SPARKPRICE;
			echo "Subtotal: $".number_format($totalamount, 2)."<br />";
			
			echo "isset($tireqty):".isset($tireqty)."<br />";
			$nowhere = 0;
			echo "isset($nowhere):".isset($nowhere)."<br />";
			echo "empty($tireqty):".empty($tireqty)."<br />";
			
			switch ($find)
			{
				case "a":	
					echo "<p> Regular customer. </p>";
					break;
				case "b":
					echo "<p> Customer referred by TV advert. </p>";
					break;
				case "c":
					echo "<p> Customer referred by phone directory. </p>";
					break;
				case "d":
					echo "<p> Customer referred by word of mouth. </p>";
					break;
				default:
					echo "<p> Others way to find us. </p>";
					break;
			}
			
		?>
	</body>
</html>