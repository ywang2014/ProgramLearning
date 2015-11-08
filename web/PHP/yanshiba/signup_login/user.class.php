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
					break;
				case 0:
					if (isset($arr[$v[0]]))
					{
						if (!$this->check($arr[$v[0]], $v[3], $v[4]))
						{
							$this->error[] = $v[2];
							return false;
						}
					}
					break;
				case 2:
					if (isset($arr[$v[0]]) && !empty($arr[$v[0]]))
					{
						if (!$this->check($arr[$v[0]], $v[3], $v[4]))
						{
							$this->error[] = $v[2];
							return false;
						}
					}
					break;
			}
		}
		return true;
	}
	
	public function getErr()
	{
		return $this->error;
	}
	
	protected function check($value, $rule = '', $parm = '')
	{
		switch ($rule)
		{
			case 'require':
				return !empty($value);
				
			case 'number':
				return is_numeric($value);
				
			case 'in':
				$tmp = explode(',', $parm);
				return in_array($value, $tmp);
				
			case 'between':
				list($min, $max) = explode(',', $parm);
				return $value >= $min && $value <= $max;
				
			case 'length':
				list($min, $max) = explode(',', $parm);
				return strlen($value) >= $min && strlen($value) <= $max;
				
			case 'email':
				// 正则表达式 或 系统函数
				return filter_var($value, FILTER_VALIDATE_EMAIL) !== false;
				
			default:
				return false;
		}
	}
	
	/* model中定义最基本的增、删、改、查 */
	
	public function add($data)
	{
		return $this->db->autoExecute($this->table, $data);
	}
	
	public function deletes($id)
	{
		$sql = 'delete from '.$this->table.' where '.$this->pk.'='.$id;
		if ($this->db->query($sql))
		{
			return $this->db->affected_rows();
		}
		else
		{
			return false;
		}
	}
	
	
	public function update($data, $id)
	{
		$rs = $this->db->autoExecute($this->table, $data, 'update', ' where '.$this->pk.'='.$id);
		if ($rs)
		{
			return $this->db->affected_rows();
		}
		else
		{
			return false;
		}
	}
	
	public function select()
	{
		$sql = 'select * from '.$this->table;
		return $this->db->getAll($sql);
	}
	
	public function find($id)
	{
		$sql = 'select * from '.$this->table.' where '.$this->pk.'='.$id;
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
	
	protected $_valid = array(
							array('username', 1, '用户名不能为空', 'require'),
							array('username', 0, '用户名必须在4-16字符内', 'length', '4,16'),
							array('email', 1, 'email不能为空', 'require'),
							array('email', 1, 'email非法', 'email'),
							array('password', 1, 'password不能为空', 'require')
							);
							
	protected $_auto = array(
							array('regtime', 'function', 'time')
							);
	
	// 加密密码
	protected function MD5password($password)
	{
		return md5($password);
	}
	
	// 用户注册
	public function reg($data)
	{
		if ($data['password'])
		{
			$data['password'] = $this->MD5password($data['password']);
		}
		
		return $this->add($data);
	}
	
	// 根据用户名查询用户信息
	public function checkUser($username, $password = '')
	{
		if ($password == '')
		{
			$sql = 'select count(*) from '.$this->table." where username='$username'";
			return $this->db->getOne($sql);
		}
		else
		{
			$sql = 'select user_id, username, email, from '.$this->table. " where username='$username'";
			
			$row = $this->db->getRow($sql);
			
			if (empty($row))
			{
				echo '用户名不存在';
				return false;
			}
			
			if ($row['password'] != $this->MD5password($password))
			{
				echo "密码错误";
				return false;
			}
			
			unset($row['password']);
			return $row;
		}
		
	}
}

?>