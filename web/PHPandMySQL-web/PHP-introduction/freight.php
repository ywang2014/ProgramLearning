<html>
<!-- freight.html 运费表 -->
	<head>
		<title> Bob freight cost </title>
	</head>
	
	<body>
		<table border = 0 cellpadding = 10 style = "color: red">
			<tr>
				<td bgcolor = "#002299" align = center> Distance </td>
				<td bgcolor = "#2277cc" align = center> Cost </td>
			</tr>
			<?php 
		
			$distence = 50;
			while ($distence <= 250)
			{
				$cost = $distence / 10;
				echo "<tr>";
				echo "<td>".$distence."</td>";
				echo "<td>".$cost."</td>";
				echo "</tr>";
				$distence = $distence + 50;
			}
		
			?>
		</table>
	</body>
</html>