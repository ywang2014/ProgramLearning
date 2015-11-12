<?php
/*
	接收表单，过滤数据
*/
switch (trim($_POST['gender']))
{
	case 'Male':
	case 'Female':
	case 'Other':
		echo "<p aligen = \"center\"> Congratulations! your are: ".trim($_POST['gender']).".</p>";
		break;
		
	default:
		echo "<p align = \"center\" > <span style = \"color:red;\"> WARNING: </span>".
		"Invalid input value for gender specified.</p>";
		break;
}

/*
	数字检查：
*/
$number = (int) $_POST['num_nights'];
if ($number == 0)
{
	echo "Error: invalid number of nights!";
	exit;
}

/*
	检查日期：
*/
$mmddyy = split(trim($_POST['user_date']), '/');
if (count($mmddyy) != 3)
{
	echo "Error: invalid date specified!";
	exit;
}

// handle years like 02 or 95
if ((int)$mmddyy[2] < 100)
{
	if ((int)$mmddyy[2] > 50)
	{
		$mmddyy[2] = (int)$mmddyy[2] + 1900;
	}
	else if ((int)$mmddyy[2] >= 0)
	{
		$mmddyy[2] = (int)$mmddyy[2] + 2000;
	}
}

if (! checkdate($mmddyy[0], $mmddyy[1], $mmddyy[2]))
{
	echo "Error: invalid date specified!";
	exit;
}

/*
	用户的输入，通过过滤、验证，执行常规的错误检查，同时
	提高系统的安全性

*/

/*
	转义输出：
	用户如果输入html代码，不进行转义，将无法正确输出，而且会打乱布局！===-
*/

$input = "<body> <input type = \"radio\" name = \"gender\" value = \"Male\" /> Male <br />".
			"<input type = \"radio\" name = \"gender\" value = \"Female\" /> Female <br />".
			"<input type = \"radio\" name = \"gender\" value = \"Other\" /> None of your business <br />".
			"<input type = \"submit\" value = \"submit\" /> </body>";
			
$str = htmlspecialchars($input, ENT_NOQUOTES, "utf-8");
echo nl2br($str);

$str = htmlentities($input, ENT_QUOTES, "utf-8");
echo nl2br($str);

?>