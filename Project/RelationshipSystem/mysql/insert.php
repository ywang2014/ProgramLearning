<html>
	<head>
		<meta charset = "utf-8">
		<title> RelationshipNetwork </title>
	</head>
</html>

<?php
require("../include/init.php");

$name = trim($_POST["name"]);
$gender = trim($_POST["sex"]);
$email = trim($_POST["email"]);
$school = trim($_POST["school"]);
$birthday = trim($_POST["birthday"]);
$qq = trim($_POST["QQ"]);
$tel = trim($_POST["tel"]);
$city = trim($_POST["city"]);
$job = trim($_POST["job"]);
$hobby = trim($_POST["hobby"]);
$introduce = "my classmates, maybe we are good friends!";
$rtime = date("Y/m/d");

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
		
		$insert = "INSERT INTO classmates(name, gender, email, school, birthday, qq, tel, city, job, hobby, introduce, rtime)";
		$insert .= "values('$name', '$gender', '$email', '$school', $birthday, $qq, $tel, '$city', '$job', '$hobby', '$introduce', $rtime)";
		@mysql_select_db($_CFG['dbname'], $conn);
		if (!mysql_query($insert))
		{
			echo "<script> alert('注册失败，请稍后再试'); history.go(-1); </script>";
		}
		else
		{
			$cid = mysql_insert_id($conn);
	
			echo "<script language=javascript> alert('发布成功');window.location.href = 'person_page.php?cid=".$cid."'; </script>";
		}
		
		mysql_close();
	}
}

?>
