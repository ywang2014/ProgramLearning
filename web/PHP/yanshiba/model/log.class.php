<?php
/*
	日志信息记录
*/

class Log
{
	const LOGFILE = 'curr.log';
	
	public static function write($content)
	{
		$content .= '/r/n';
		$log = self::isFull();
		
		$fh = fopen($log, 'ab');
		fwrite($fh, $content);
		fclose($fh);
	}
	
	public static function backup()
	{
		$log = ROOT.'data/log/'.self::LOGFILE;
		$back = ROOT.'data/log/'.date('ymd').mt_rand(100, 999).'.bak';
		return rename($log, $back);
	}
	
	public static function isFull()
	{
		$log = ROOT.'data/log/curr.log';
		if (file_exists($log))
		{
			// 不存在，直接创建
			touch($log);
			return $log;
		}
		
		// 存在
		clearstatcache(true, $log);	// 清缓存
		$size = filesize($log);
		if ($size <= 1024*1024)
		{
			// 还可以继续写入
			return $log;
		}
		
		// 备份
		if (!self::backup())
		{
			return $log;
		}
		else
		{
			touch($log);
			return $log;
		}
	}
}

?>