<?php
// 实现POP3_mail类文件：pop3.php
// 通过POP3协议收取信件的类
class POP3_mail
{
	var $hostname = "";	// pop主机名
	var $port = 110;	// 主机的pop3端口，一般是110
	var $timeout = 5;	// 连接主机的最大超时时间
	var $connection = 0;// 保存与主机的连接
	var $state = "DISCONNECTED";	// 保存当前状态
	var $debug = 0;		// 作为标识，是否在调试状态，是则输出调试信息
	var $err_str = '';	// 如果出错，保存错误信息
	var $err_no;		// 如果出错，保存错误号码
	var $resp;			// 临时保存服务器的响应信息
	var $apop;			// 指示需要使用加密方式进行密码验证，一般不需要
	var $messages;		// 邮件数
	var $size;			// 各种邮件的总大小
	var $mail_list;		// 一个数组，保存各个邮件的大小及其在邮件服务器上的序号
	var $head = array();// 邮件头的内容，数组
	var $body = array();// 邮件体的内容，数组
	
	function POP3_mail($server = "192.100.100.1", $port = 110, $time_out = 5)
	{
		$this->hostname = $server;
		$this->port = $port;
		$this->timeout = $time_out;
		return true;
	}
	
	// 输出调试信息
	function outdebug($message)
	{
		// 把调试信息message显示出来，把一些特殊字符进行转换，在行尾加上<br>标签
		// 使输出的调试信息，便于阅读
		echo(htmlspecialchars($message)."<br>\n");
	}
	
	// 建立与pop3服务器连接的函数
	function open()
	{
		if ($this->hostname == "")
		{
			$this->err_str = "无效的主机名！！";
			return false;
		}
		if ($this->debug)
		{
			echo("正在打开$this->hostname, $this->port, $err_no, & $err_str, $this->timeout<BR>");
		}
		if (! $this->connection = fsockopen($this->hostname, $this->port, $err_no, $err_str, $this->timeout)) 	// 引用传值还是使用$err_no, 不使用&$err_no，定义的时候区别即可
		{
			$this->err_str = "连接到POP服务器失败，错误信息：".$err_str."错误号：".$err_no;
			return false;
		}
		else
		{
			$this->getresp();
			if ($this->debug)
			{
				$this->outdebug($this->resp);
			}
			if (substr($this->resp, 0, 3) != "+OK")
			{
				$this->err_str = "服务器返回无效信息：".$this->resp."请检查POP服务器是否正确";
				return false;
			}
			$this->state = "AUTHORIZATION";
			return true;
		}
	}
	
	// 建立获取返回信息的函数
	function getresp()
	{
		for ($this->resp = ""; ; )
		{
			if (feof($this->connection))
			{
				return false;
			}
			$this->resp.= fgets($this->connection, 100);
			$length = strlen($this->resp);
			if ($length >= 2 && substr($this->resp, $length-2, 2) == "\r\n")
			{
				$this->resp = strtok($this->resp, "\r\n");	// 去掉最后的回车换行符
				return true;
			}
		}
	}
	
	// 定义命令处理函数
	function command($command, $return_length = 1, $return_code = '+')
	{
		if ($this->connection == 0)
		{
			$this->err_str = "没有连接到任何服务器，请检查网络连接";
			return false;
		}
		if ($this->debug)
		{
			$this->outdebug(">>> $command");
		}
		if (! fputs($this->connection, "$command\r\n"))
		{
			$this->err_str = "无法发送命令".$command;
			return false;
		}
		else
		{
			$this->getresp();
			if ($this->debug)
			{
				$this->outdebug($this->resp);
			}
			if (substr($this->resp, 0, $return_length) != $return_code)
			{
				$this->err_str = $command."命令服务器返回无效".$this->resp;
				return false;
			}
			else return true;	
		}
	}
	
	// 定义服务器登录函数
	function login($user, $password)
	{
		if ($this->state != "AUTHORIZATION")
		{
			$this->err_str = "还没有连接到服务器或状态不对";
			return false;
		}
		if (! $this->apop)	// 服务器是否采用APOP用户认证
		{
			if (! $this->command("USER $user", 3, "+OK"))
			{
				return false;
			}
			if (! $this->command("PASS $password", 3, "+OK"))
			{
				return false;
			}
		}
		else
		{
			if (! $this->command("APOP $user".md5($this->greeting.$password), 3, "+OK"))
			{
				return false;
			}
		}
		$this->state = "TRANSACTION";	// 用户认证通过，进入传输模式
		return true;
	}
	
	// 获取邮件数与总的大小的方法
	function mail_stat()
	{
		if ($this->state != "TRANSACTION")
		{
			$this->err_str = "还没有连接到服务器或没有成功登陆";
			return false;
		}
		if (! $this->command("STAT", 3, "+OK"))
		{
			return false;
		}
		else
		{
			$this->resp = strtok($this->resp, "");
			$this->messages = strtok("" );	// 取得邮件总数
			$this->size = strtok("" );	// 获取总的字节大小
			return true;
		}
	}
	
	// 获取邮件列表的方法
	function listmail($mess = null, $uni_id = null)
	{
		if ($this->state != "TRANSACTION")
		{
			$this->err_str = "还没有连接到服务器或者没有登陆成功";
			return false;
		}
		if ($uni_id)
		{
			$command = "UIDL";
		}
		else
		{
			$command = "LIST";
		}
		if ($mess)
		{
			$command = $mess;
		}
		if (! $this->command($command, 3, "+OK"))
		{
			return false;
		}
		else
		{
			$i = 0;
			$this->mail_list = array();
			$this->getresp();
			while ($this->resp != ".")
			{
				$i++;
				if ($this->debug)
				{
					$this->outdebug($this->resp);
				}
				if ($uni_id)
				{
					$this->mail_list[$i][num] = strtok($this->resp, "");
					$this->mail_list[$i][size] = strtok(""); 
				}
				else
				{
					$this->mail_list[$i]["num"] = intval(strtok($this->resp, ""));
					$this->mail_list[$i]["size"] = intval(strtok(""));
				}
				$this->getresp();
			}
			return true;
		}
	}
	
	// 获取邮件内容的方法
	// num邮件序号，line获取邮件正文行数，默认值-1，取回邮件所有内容。
	function getmail($num = 1, $line = -1)
	{
		if ($this->state != "TRANSACTION")
		{
			$this->err_str = "不能收取信件，还没有连接到服务器或者没有登陆成功";
			return false;
		}
		if ($line < 0)
		{
			$command = "RETR $num";
		}
		else
		{
			$command = "TOP $num $line";
		}
		if (! $this->command("$command", 3, "+OK"))
		{
			return false;
		}
		else
		{
			$this->getresp();
			$is_head = true;
			while ($this->resp != ".")	// . 号是邮件结束的标志
			{
				if ($this->debug) 
				{
					$this->outdebug($this->resp);
				}
				if (substr($this->resp, 0, 1) == ".")
				{
					$this->resp = substr($this->resp, 1, strlen($this->resp) - 1);
				}
				if (trim($this->resp) == "")	// 邮件头与正文部分是一个空行
				{
					$is_head = false;
				}
				if ($is_head)
				{
					// 每个元素，代表邮件源代码的一行
					$this->head[] = $this->resp;
				}
				else
				{
					// 每个元素，代表邮件源代码的一行
					$this->body[] = $this->resp;
				}
				$this->getresp();
			}
			return true;
		}
	}
	
	// 删除指定序号的邮件
	function dele($num)
	{
		if ($this->state != "TRANSACTION")
		{
			$this->err_str = "不能删除远程信件，还没有连接到服务器或没有登录成功";
			return false;
		}
		if (! $num)
		{
			$this->err_str = "删除的参数不对";
			return false;
		}
		if ($this->command("DELE $num", 3, "+OK"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// 退出，关闭与服务器的连接
	// 中断连接的方法
	function close()
	{
		if ($this->connection != 0)
		{
			if ($this->state == "TRANSACTION")
			{
				$this->command("QUIT", 3, "+OK");
			}
			fclose($this->connection);
			$this->connection = 0;
			$this->state = "DISCONNECTED";
		}
	}
}

?>