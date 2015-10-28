<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
	</head>
</html>

<?php
$name = $_POST["name"];
$sex = $_POST["sex"];
$email = $_POST["email"];
$school = $_POST["school"];
$birthday = $_POST["birthday"];
$qq = $_POST["QQ"];
$tel = $_POST["tel"];
$city = $_POST["city"];
$job = $_POST["job"];
$hobby = $_POST["hobby"];

if ($name == "")
{
	echo "<script> alert('姓名不能为空，请返回重填'); history.go(-1); </script>";
}
else
{
	if ($email == "" || $school == "" || $birthday == "" || $tel == "")
	{
		echo "<p style = \"color: red\">";
		echo "Email、学校、生日、电话中有未填写项！请返回填写完整。谢谢！<br />";
		echo "</p>";
		echo "<script> alert('基本信息全部不能为空，请返回重填'); history.go(-1); </script>";
	}
	else
	{
		// 检查邮箱格式
		if ($email != "")
		{
			if (! strpos($email, "@") || ! strpos($email, "."))
			{
				echo "<p style = \"color: red\">";
				echo "Email 地址格式错误";
				echo "</p>";
				echo "<a href = \"javascript:history.back()\"> 返回 </a>";
				exit();
			}
		}
		// 检查手机号格式
		if (! preg_match("/1[358]{1}\d{9}$/", $tel) || strlen($tel) != 11)
		{
			echo "<p style = \"color: red\">";
			echo "手机号输入非法 </p>";
			echo "<a href = \"javascript:history.back()\"> 返回 </a>";
			exit();
		}
		// 检查生日格式
		if (! preg_match("/[12]{1}\d{7}$/", $birthday) || strlen($birthday) != 8)
		{
			echo "<p style = \"color: red\">";
			echo "生日格式输入错误 </p>";
			echo "<a href = \"javascript:history.back()\"> 返回 </a>";
			exit();
		}
		
		include "mysql/connection.php";

		$insert = "INSERT INTO friends(name, sex, email, school, birthday, qq, tel, city, job, hobby)";
		$insert .= "values('$name', '$sex', '$email', '$school', '$birthday', '$qq', '$tel', $city, $job, $hobby)";
		mysql_query($insert) or die("<p align = center> 录入时发生错误");
		
		header("Location: ../login/personalHomePage.html");
		
		mysql_close();
	}
}

?>
