<?php

class Model
{
	protected $table = NULL;	// model控制的表
	protected $db = NULL;		// 引入的mysql对象
	
	protected $pk;	// 主键
	protected $fields = array();	// 表单域
	protected $_auto = array();
	protected $_valid = array();
	protected $error = array();
	
	public function __construc()
	{
		$this->db = mysql::getIns();
	}
	
	public function table($table)
	{
		$this->table = $table;
	}
	
	
	/*	
		自动过滤：
		负责处理接收自表单的数据
		清除不用的单元
		留下与表单对应的字段
		
		表字段：desc分析表名获得
			自己手写好
		
	*/
	public function _facade($arr = array())
	{
		$data = array();
		foreach ($arr as $k=>$v)
		{
			if (in_array($k, $this->fields))	// 判断 $k 是否是对应的表单域
			{
				$data[$k] = $v;
			}
		}
		return $data;
		
	}
	
	/* 
		自动填充功能:
			负责把表中需要，但是$_POST 没有传过来的字段，赋值
			比如：时间字段，自动把time()返回值赋过来
	*/
	public function _autoFill($arr)
	{
		foreach ($this->_auto as $k=>$v)
		{
			if (!array_key_exists($v[0], $arr))
			{
				switch($v[1])
				{
					case 'value':
						$arr[$v[0]] = $v[2];
						break;
					case 'function':
						$arr[$v[0]] = call_user_func($v[2]);
						break;
				}
			}
		}
		return $arr;
	}
	
	/* 验证有效性 */
	public function _validate($arr)
	{
		if (empty($this->_valid))
		{
			return true;
		}
		
		$this->error = array();
		
		foreach ($this->_valid as $k=>$v)
		{
			switch ($v[1])
			{
				case 1:
					if (!isset($arr[$v[0]]))
					{
						$this->error[] = $v[2];
						return false;
					}
					
					if (!this->check($arr[$v[0]], $v[3]))
					{
						$this->error[] = $v[2];
						return false;
					}
			}
		}
	}
}

/*
	面向对象，使用model开发
	user.class.php
*/
class UserModel extends Model
{
	protected $table = 'users';
	protected $id = 'user_id';
	
	protected $fields = array('user_id', 'username', 'email', 'password', 'regtime', 'lastlogin');
	
	
}

?>