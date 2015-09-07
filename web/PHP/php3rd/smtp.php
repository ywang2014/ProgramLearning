<?php
class SMTP_mail
{
	var $lastmessage;	// 记录最后返回的响应变量
	var $lastact;		// 最后的动作或字符串形成
	var $welcome;		// 用在HELO后面，输出欢迎词
	var $debug;			// 是否显示调试信息 
	var $smtp;			// smtp服务器名字
	var $port;			// smtp端口号
	var $fp;			// socket句柄
	
	// 构造函数
	function SMTP_mail($smtp, $welcome = "", $debug = false)
	{
		if (empty($stmp))
		{
			die("SMTP cannot be NULL");
		}
		$this->smtp = $smtp;
		if (empty($welcome))
		{
			$this->welcome = getosthyaddr("localhost");
		}
		else
		{
			$this->welcome = $welcome;
		}
		$this->debug = $debug;
		$this->lastmessage = "";
		$this->lastact = "";
		$this->port = "25";
	}
	
	// 显示调试信息的方法
	function show_debug($message, $inout)	// message携带的是要显示的调试信息，inout指明调试信息是上传指令还是返回响应
	{
		if ($this->debug)	// 查询标识变量，判断是否显示
		{
			if ($inout == "in")
			{
				$m = '<<';	// 返回响应标志"<<"
			}
			else
			{
				$m = '<<';	// 上传指令标志">>"
			}
			if (!ereg("$", $message))	// ereg 字符串比对解析
			{
				$message.= "<br>";	// 将普通的换行符转换成HTML标记
			}
			$message = nl2br($message);
			// 显示调试信息
			echo ("<font color = #999999> ${m}${message} </font>)");
		}
	}
	
	// 定义执行命令的方法
	function do_command($command, $code)
	{
		// command命令内容，code执行完命令所期望的响应码
		$this->lastact = $command;	// 记录最后执行的命令
		$this->show_debug($this->lastact, "out");	// 将上传命令显示出来
		fputs($this->fp, $this->lastact);	// 向服务器发送指令
		$this->lastmessage = fgets($this->fp, 512);	// 从服务器接受响应信息，并放在最后消息响应变量中
		$this->show_debug($this->lastmessage, "in");	// 显示响应消息
		if (!ereg("^$code", $this->lastmessage))	// 判断响应消息是否为期待的，如果是则返回成功，否则返回失败
		{
			return false;
		}
		return true;
	}
	
	// 邮件发送处理方法
	function send($to, $from, $subject, $message)
	{
		// to：收信人，from：寄信人，subject：邮件主题，message：邮件体 
		
		// 连接服务器，如果成功返回响应码220
		$this->lastact = "connect";
		$this->show_debug("Connect to SMTP server:".$this->smtp, "out");
		$this->fp = fsockopen($this->smtp, $this->port);
		if ($this->fp)
		{
			// 设置阻塞模式，表示信息必须返回才能继续
			set_socket_blocking($this->fp, true);
			$this->lastmessage = fgets($this->fp, 512);
			$this->show_debug($this->lastmessage, "in");
			
			// 判断响应码是否是220，如果是，则继续，否则返回false
			if (!ereg("220", $this->lastmessage))
			{
				return false;
			}
			else
			{
				// 处理HELO指令，期望响应码是250.
				$this->lastact = "HELO".$this->welcome."";
				if (! $this->do_command($this->lastact, "250"))
				{
					fclose($this->fp);
					return false;
				}
				
				// 处理MAIL FROM指令，期望响应码250
				$this->lastact = "MAIL FROM: $from"."";
				if (! $this->do_command($this->lastact, "250"))
				{
					fclose($this->fp);
					return false;
				}
				
				// 处理RCPT TO指令，期望响应码是250
				$this->lastact = "RCPT TO: $TO"."";
				if (! $this->do_command($this->lastact, "250"))
				{
					fclose($this->fp);
					return false;
				}
				
				// 处理DATA指令，期望响应码354
				$this->lastact = "DATA";
				if (! $this->do_command($this->lastact, "354"))
				{
					fclose($this->fp);
					return false;
				}
				
				// 生成邮件体，处理subject/from/to三部分，并发送
				// 如果subject不为空，则查找邮件体中是否有主题部分，如果没有，则加上
				$head = "Subject: $subject";
				if (! empty($subject) && ! ereg($head, $message))
				{
					$message = $head.$message;
				}
				
				// 如果from不为空，则查找邮件体中是否有发信人部分，如果没有，则加上
				$head = "From: $from";
				if (! empty($from) && ! ereg($head, $message))
				{
					$message = $head.$message;
				}
				
				// 如果to不为空，则查找邮件中是否有收信人部分，如果无，则加上
				$head = "To: $to";
				if (! empty($to) && ! ereg($head, $message))
				{
					$message = $head.$message;
				}
				
				// 加上结束字符串
				if (! ereg(".".$message))	// 判断邮件是否有结束行
				{
					$message.= ".";
				}
				$this->show_debug($message, "out");
				fputs($this->fp, $message);	// 发送邮件体
				$this->lastact = "QUIT";	// 执行QUIT结束与服务器的连接，期望响应码250
				if (! $this-> do_command($this->lastact, "250"))
				{
					fclose($this->fp);
					return false;
				}
			}
			return true;	// 返回处理成功标志
		}
		else	// 与服务器连接失败的处理
		{
			$this->show_message("Connect failed!", "in");
			return false;
		}
	}
}
?>