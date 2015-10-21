<?php
// processorder.php  Bob汽車零部件商店，程序的訂單處理腳本，該腳本包括了異常處理

require_once("file_exceptions.php");

// create short variable name
$tireqty = $_POST['tireqty'];
$oilqty = $_POST['oilqty'];
$sparkqty = $_POST['sparkqty'];
$address = $_POST['address'];

$DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];
?>

<html>
	<head>
		<title> Bob Auto Parts - Order Results </title>
	</head>
	
	<body>
		<h1> Bob Auto Parts </h1>
		<h2> Order Results </h2>
		<?php
		$date = date("H:i, jS F");
		
		echo "<p> Order processed at ".$date."</p>";
		
		echo "<p> Your order is as follows: </p>";
		
		$totalqty = 0;
		$totalqty = $tireqty + $oilqty + $sparkqty;
		echo "Item ordered: ".$totalqty."<br>";
		
		if ($totalqty == 0)
		{
			echo "You did not order anything on the previous page!<br>";
		}
		else
		{
			if ($tireqty > 0)
			{
				echo $tireqty." tires<br>";
			}
			if ($oilqty > 0)
			{
				echo $oilqty." bottles of oil<br>";
			}
			if ($sparkqty > 0)
			{
				echo $sparkqty." spark plugs<br>";
			}
		}
		
		$totalamount = 0.00;
		define("TIREPRICE", 100);
		define("OILPRICE", 10);
		define("SPARKPRICE", 4);
		
		$totalamount = $tireqty * TIREPRICE
						+ $oilqty * OILPRICE
						+ $sparkqty * SPARKPRICE;
						
		$totalamount = number_format($totalamount, 2, '.', ' ');
		
		echo "<p> Total of order is ".$totalamount."</p>";
		echo "<p> Address to ship to is ".$address."</p>";
		
		$outputstring = $date."\t".$tireqty." tires\t".$oilqty." oil\t".
						$sparkqty." spark plugs\t\$".$totalamount.
						"\t".$address."\n";
						
		// open file for appending
		try
		{
			if (!($fp = @fopen("$DOCUMENT_ROOT/../orders/orders.txt", "ab")))
			{
				throw new FileOpenException();
			}
			
			if (!flock($fp, LOCK_EX))
			{
				throw new FileLockException();
			}
			
			if (!fwrite($fp, $outputstring, strlen($outputstring)))
			{
				throw new FileWriteException();
			}
			
			flock($fp, LOCK_UN);
			fclose($fp);
			echo "<p> Order written.</p>";
		}
		catch (fileOpenException $foe)
		{
			echo "<p> <strong> Orders file could not be opened.".
				"Please contact our webmaster for help.</strong> </p>";
		}
		catch (Exception $e)
		{
			echo "<p> <strong> Your order could not be processed at this time.
					Please try again later. </strong> </p>";
		}
		?>
	</body>
</html>