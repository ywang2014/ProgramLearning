<?php
// processfeedback.php 	智能表单处理程序

// create a short variable names   format the string into a suitable format
$name = trim($_POST["name"]);
$email = trim($_POST["email"]);
$feedback = addslashes(trim($_POST["feedback"]));

// set up some static information
$toaddress = "feedback@example.com";

$subject = "Feedback from web site";

$mailcontent = "Customer name: ".$name."\n".
				"Customer email: ".$email."\n".
				"Customer comments: \n".$feedback."\n";
				
$fromaddress = "From: webserver@example.com";

// invoke mail() function to send mail 
mail($toaddress, $subject, $mailcontent, $fromaddress);

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Bobs Feedback Submitted </title>
	</head>
	
	<body>
		<h1> Bob's Auto Parts Feedback Submitted <>/h1>
		<p> Your feedback has been sent. </p>
 	</body>
</html>

