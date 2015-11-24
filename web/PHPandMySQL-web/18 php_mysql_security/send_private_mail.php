<?php
/*
	send_private_mail.php
*/
$from = trim($_POST['from']);
$title = trim($_POST['title']);
$body = trim($_POST['body']);
$to_email = 'projectyw2015@sina.com';

// tell gpg where to find the key ring user's home directory is /tmp/ 
putenv('GNUPGHOME=/tmp/.gnupg');	// 指定GPG密钥环的地址

// create a unique file name
$infile = tempnam('', 'pgp');
$outfile = $infile.'.asc';

// write the user's text to the file 
$fp = fopen($infile, "w");
fwrite($fp, $body);
fclose($fp);

// set up our command
$command = "/usr/local/bin/gpg -a \\ 
			--recipient 'username <user@web.com.au>' \\
			--encrypt -o $outfile $infile";
			
// execute our gpg command
system($command, $result);

// delete the unencrypted temp file 
unlink($infile);

if ($result == 0)
{
	$fp = fopen($outfile, "r");
	if ((!$fp) || (filesize($outfile) == 0))
	{
		$result = -1;
	}
	else
	{
		// read the encrypted file
		$contents = fread($fp, filesize($outfile));
		
		// delete the encrypted file
		unlink($outfile);
		
		mail($to_email, $title, $contents, "From: ".$from."\n");
		echo "<h1> Message Sent </h1>".
			"<p> Your message was encrypted and sent. </p>".
			"<p> Thank you. </p>";
	}
}

if ($result! = 0)
{
	echo '<h1> Error: </h1>'.
		'<p> Your message could not be encrypted. </p>'.
		'<p> It has not been sent. </p>'.
		'<p> Sorry. </p>';
}

?>