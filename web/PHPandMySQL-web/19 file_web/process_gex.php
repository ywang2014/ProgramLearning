<?php
/*
	progex.php 文件状态函数
	执行系统指令
*/
chdir('./uploads/');

/* exec */
echo '<pre>';	// 保持文本格式的输出！

// unix
exec('ls-a', $result);

// windows
exec('dir', $result);

foreach ($result as $line)
{
	echo "$line \n";
}

echo "</pre>";
echo "<hr>";


/* passthru */
echo '<pre>';	// 保持文本格式的输出！

// unix
passthru('ls-a');

// windows
passthru('dir');

echo "</pre>";
echo "<hr>";


/* system */
echo '<pre>';	// 保持文本格式的输出！

// unix
$result = system('ls-a');

// windows
$result = system('dir');

echo "</pre>";
echo "<hr>";


/* backticks */
echo '<pre>';	// 保持文本格式的输出！

// unix
$result = `ls-al`;

// windows
$result = `dir`;

echo $result;
echo "</pre>";

/*
	防止用户的恶意攻击
*/
system(escapeshellcmd($user_cmd));
escapeshellarg($shell_args);

?>