// 变量的函数

<? php

/* gettype() 确定变量类型
* integer/ double/ string/ array/ object
* unkown type
*/

$avar = 0.1;
if (gettype($avar) == "double")
{
	$avar = 0;
}

// settype() 用来设置变量类型，若不能设置，则返回false
$var1 = 4;
if (settype($var1, "string"))
{
	echo("Succeed!\n");
}
else
{
	echo("failed!\n");
}

// isset() 用来确定一个变量是否被赋值
// unset() 用来释放一个变量所占的存储空间，释放后变量不可用
$ava2 = 34;
if (isset($ava2))
{
	echo("这将被输出 <br>");
}
unset($ava2);
if (isset($ava2))
{
	echo("这将不能输出 <br>");
}

// empty() 与isset()相反，确定一个变量没有被赋值
echo empty($var3);	// true
$var4 = 123;
echo empty($var4);	// false
$var5 = 0;
echo empty($var5);	// true
$var6 = "";
echo empty($var6);	// true
unset($var4);
echo empty($var4);	// true

/* is_xxx() 此类型函数用于检查类型
* is_int() is_integer() is_long() 检查变量是否是整数类型
* is_double() is_float() is_real() 检查变量是否是双字节
* is_string() is_array() is_object()
*/

$stri = "ghadhg";
if (is_string($stri))
{
	echo("<h1> string </h1>");
}

/*
* xxxval() 类型函数
* intval() 第二个参数用于指定要转换的数的进制，默认为10进制
* doubleval()
* stral()
*/

$vari1 = "123BB";
echo("<h1> $vara1 </h1>");		// print 123BB
$vari2 = intval($vara1);
echo("<h1> $vara2 </h1>");		// print 123
Svari3 = intval($vara1, 16);
echo("<h1> $vara3 <h1>");		//print 

? >