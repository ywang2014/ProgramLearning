<?php
// 二维数组的建立和遍历
$class = array(1 => array("Joan", "Tom", "Lucy"), 2 => array("Jack", "Marry", "Jean"));
// list() 列出数组所有元素，each() 使指针指向下一个元素
// foreach(array as $value) 遍历数组，元素值赋给 $value
while (list($key_1) = each($class))
{
	// 输出所有班级
	echo("<h1> $key_1 班的学生有 </h1>");
	while (list($key_2, $name) = each($class[$key_1]))
	{
		// 输出某个班的所有学生
		echo("<h2> $name </h2>");
	}
}
?>

<?php
$student = array("Jack", "Bob", "Alice", "lena", "Gates");
foreach($student as $key => $value)
{
	echo("<h3> $key---$value </h3>");
}
// sort() 排序
sort($student);
foreach($student as key => $value)
{
	echo("<h3> $key---$value </h3>");
}
?>