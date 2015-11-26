<?php
/*
	lookup.php 从NASDAQ获得￥symbol列表给出的股票信息
	
	获取其他站点提供的数据，显示在自己的网页中
*/

?>

<!DCOTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset=utf-8"/>
		<title> Stock quote From NASDAQ </title>
	</head>
	
	<body>
		<?php
			$symbol = 'AMZN';
			
			echo '<h1> Stock quote for '.$symbol.'</h1>';
			
			$url = "http://finance.yahoo.com/d/quotes.csv?s=".$symbol."&e.csv&f=slldlt1clohgv";
			
			if (!($contents = file_get_contents($url)))
			{
				die('Failure to open'.$url);
			}
			
			list($symbol, $quote, $date, $time) = explode(',', $contents);
			$date = trim($date, '"');
			$time = trim($time, '"');
			
			echo '<p>'.$symbol.' was last sold at: '.$quote.'</p>';
			echo '<p> Quote current as of '.$date.'at '.$time.'</p>';
			
			echo '<p> This information retrieved from <br> <a href ="'.$url'">'.$url.'</a> </p>';
		
		?>
	</body>
</html>