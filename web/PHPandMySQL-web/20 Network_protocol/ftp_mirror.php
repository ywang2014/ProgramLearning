<?php
/*
	ftp_mirror.php
	从一个FTP服务器下载新版本的文件脚本
*/

?>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-type" content = "text/html; charset = utf-8" />
		<title> Mirror update </title>
	</head>
	<body>
		<h1> ftp mirror update file </h1>
		<?php
			$host = "ftp.cs.rmit.edu.au";
			$user = "anonymous";
			$password = "me@example.com";
			$remotefile = "/pub/tsg/teraterm/ttssh14.zip";
			$localfile = "/tmp/writable/ttssh14.zip";
			
			$conn = ftp_connect($host);
			if (!$conn)
			{
				echo "Error: could not connect to ftp server<br>";
				exit;
			}
			
			echo "Connected to $host. <br>";
			
			$result = @ftp_login($conn, $user, $password);
			if (!$result)
			{
				echo "Error: could not log on as $user <br>";
				ftp_quit($conn);
				exit;
			}
			echo "Logged in as $user <br>";
			
			echo "Checking file time...<br>";
			if (file_exists($localfile))
			{
				$localtime = filemtime($localfile);
				echo 'Local file last updated ';
				echo date('G:i j-M-Y', $localtime);
				echo '<br>';
			}
			else
			{
				$localtime = 0;
			}
			
			$remotetime = ftp_mdtm($conn, $remotefile);
			if (!($remotetime >= 0))
			{
				echo "Cannot access remote file time <br>";
				$remotetime = $localtime + 1;
			}
			else
			{
				echo 'Remote file last updated ';
				echo date('G:i j-M-Y', $remotetime);
				echo '<br>';
			}
			
			if (!($remotetime > $localtime))
			{
				echo 'Local copy is up to date. <br>';
				exit;
			}
			
			// download file
			echo 'Getting file from server...<br>';
			$fp = fopen($localfile, "w");
			if (!($success = ftp_fget($conn, $fp, $remotefile, FTP_BINARY)))
			{
				echo "Error: could not download file";
				ftp_quit($conn);
				exit;
			}
			fclose($fp);
			
			echo 'File downloaded successfully';
			
			ftp_quit($conn);
		
		?>
	</body>
</html>