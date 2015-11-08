<?php
/*
	数据库封装
	方便修改数据库
	db.class.php
	
	抽象类，可以实现接口的统一  
*/

abstract class db
{
	// 连接服务器
	public abstract function connect($hostaddress, $username, $password);
	
	// 发送查询
	public abstract function query($sql);
	
	// 查询多行数据
	public abstract function getAll($sql);
	
	// 查询单行数据
	public abstract function getRow($sql);
	
	// 查询单个数据
	public abstract function getOne($sql);
	
	// 自动执行插入、更新
	public abstract function autoExecute($table, $data, $act = 'insert', $where = '');
}


?>