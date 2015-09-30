# PHP 脚本语言基础
#########################################################################

/** 在Homepage中放入PHP的方法：
*  <? >
* 1. 类XML ：<? echo("这是一个PHP语言的嵌入范例\n"); ? >
* 
* 2. 类SGML：<? php echo("这是第二个PHP语言的嵌入范例 \n"); ? >
* 3. 类JavaScript、VBScript：
		<script language = "php">
		echo("这是类似JavaScript及VBScript语法的PHP语言嵌入范例");
		</script>
* 4.类ASP：<% echo("这是类似ASP嵌入语法的PHP范例"); %>
		此方法需要在php.ini加入asp-tags或者在编译PHP时加入--enable-asp-tags选项
* @date 2015-08-29
*/

## 编写PHP程序技巧：先处理纯HTML格式的Homepage文件
#  再将需要变化或处理的地方修改成PHP程序

/** PHP 引用文件
* 1. require 语句
	require("afile.php")
* 2. include 语句
	include("afile.php")
*
*/

/*
* 基本数据类型：
* Integer	2
* Double	2.3
* String	"2" 	"" (空串)
*/

// define() 定义常量
<? php
define("NATION", "China");
define("YELLOW", "# FFFF00");
define("NO", 45);
define("NL", "<BR> \n");	// 定义常量NL，用来表示HTML中的转行符号
? >

Echo("You come from", NATION, NL);	# 常量不能被引号包含
Echo("You come from", "China", "<BR> \n");

if (define("NO"))	# define()可测试一个常量是否存在，存在返回1，否则返回0
{
	echo(NO)
}

// phpinfo(): 查看PHP相关的环境信息作为预定义的常量
<html>
<!-- -phpinfo.php- -->
<body>
<? php
phpinfo()
? >
</body>
</html>

# PHP 弱类型语言
// php 中变量在赋值时自动声明
// 赋值时，自动确定变量的类型
// 使用变量，在字符串前加上"$"即可
$num_id = "123456"
$number = 123456
$money = 123.56
$total = $total1 + $total2

# 变量的转换
<? php
$a = 1;			//$a是整形
$a = 1.2;		//$a是实型了
$a = "company";	//$a是字符串类型了
? >