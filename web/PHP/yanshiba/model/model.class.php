<?php
/*
	Model 类
*/
class Model
{
	protected $table = null;
	protected $db = null;
	protected $pk = null;
	
	public function _construct()
	{
		$this->db = mysql::getIns();
	}
	
	public function table($table)
	{
		$this->table = $table;
	}
	
	public function add($data)
	{
		return $this->db->autoExecute($this->table, $data);
	}
	
	public function deletes($id)
	{
		$sql = "delete from ".$this->table." where ".$this->pk."=".$id;
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
		$this->db->autoExecute($this->table, $data, 'update', " where ".$this->pk."=".$id);
		if ($this->db->query($sql))
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
		return $this->db->getRow($id);
	}
}