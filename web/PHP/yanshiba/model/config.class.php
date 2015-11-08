<?php
/*
	配置文件，操作类
*/

class config
{
	protected static $ins = null;
	protected $data = array();
	
	final protected function __construct()
	{
		include(ROOT.'include/config.inc.php');
		$this->data = $_CFG;	// 读取配置文件信息
	}
	
	final protected function __clone()
	{
		
	}
	
	public static function getInstance()
	{
		if (! (self::$ins instanceof self))
		{
			self::$ins = new self();
		}
		return self::$ins;
	}
	
	// 用魔术方法，读取数据
	public function __get($key)
	{
		if (array_key_exists($key, $this->data))
		{
			return $this->data[$key];
		}
		else
		{
			return null;
		}
	}
	
	// 魔术方法，动态增加、修改配置选项
	public function __set($key, $value)
	{
		$this->data[$key] = $value;
	}
}

// test
$conf = config::getInstance();
print_r($conf);

echo $conf->hostname;

var_dump($conf->template_dir);
$conf->template_dir = 'D:/www/smarty';

echo $conf->template_dir;


?>