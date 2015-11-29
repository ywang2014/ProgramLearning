<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset = utf-8" />
		<title> Site Submission Results </title>
	</head>
	<body>
		<h1> The Results </h1>
		<?php
			$url = trim($_POST['url']);
			$email = trim($_POST['email']);
			
			$url = parse_url($url);	// 返回URL信息数组
			$host = $url['host'];
			if (!($ip = gethostbyname($host)))
			{
				echo "Host for url does not have valid ip";
				exit;
			}
			echo "Host is at ip $ip <br>";
			
			$email = explode('@', $email);
			$emailhost = $email[1];
			
			if (!dns_get_mx($emailhost, $mxhostsarr))	// 此函数，windows未实现
			{
				echo 'Email address is not at valid host';
				exit;
			}
			echo 'Email is delivered via: ';
			foreach ($maxhostarr as $mx)
			{
				echo "$mx";
			}
			
			echo "<br> ALL submited details are ok. <br>";
			echo "Thank you for submitting your site. <br>".
				"It will be visited by our staff members soon.";
		?>
	</body>
</html>