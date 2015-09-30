// 字符串转换
<? php
$str1 = "123nation";
echo("<h1> $st1 </h1>");
$number = 23;
echo("<h1> $number </h1>");
$str1_num = $str1 + $number;
echo("<h1> $str1_num </h1>");
echo("<h1> $str1 </h1>");

// 强制类型转换
$no = 34.5;
$no = (int) $no;	// 强制类型转换成 int
echo($no);	//输出 11 ???
$no = (double) $no;
echo($no);	// 11.0
$str1 = (string)$no;
echo($str1);	// "11"

// 变量的变量
$num = "str";
$$num = 345;	// 用变量$num的值创建变量
echo($str);		//345
echo($$num);	//345

? >