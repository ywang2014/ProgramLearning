<?php

// query.php 显示一个web页面，询问你要删除的记录，同时在记录前面提供到文件dele.php的链接>

?>

<table border = 1 width = 500 bgcolor = blue>
	<tr align = center bgcolor = #f0ffe0>
		<td> &nbsp; </td>
		<td> 姓名 </td>
		<td> 年龄 </td>
		<td> 电话 </td>
		<td> 住址 </td>
	</tr>
	
	<?php
	$q = mysql_query("SELECT * FROM students ORDER BY age DESC", $link_us);
	while ($a = mysql_fetch_array($q))
	{
		print("<tr>
				<td> $a[name] </td>
				<td> $a[age] </td>
				<td> $a[tel] </td>
				<td> $a[addr] </td>
			</tr>");
	}
	?>
	
</table>
