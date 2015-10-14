<?php
// 函数方式，创建表格
function create_table($data, $border = 0, $cellpadding = 4, $cellspacing = 4)
{
	echo "<table border = '$border' cellpadding = '$cellpadding' cellspacing = '$cellspacing'>";
	reset($data);	// Remember this is used to point to the beginning
	$value = current($data);
	while ($value)
	{
		echo "<tr> <td> $value </td> </tr>";
		$value = next($$data);
	}
	echo "</table>";
}

$my_array = array("Line one.", "Line two.", "Line three.");
create_table($my_array);

?>