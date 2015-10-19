<?php
// 迭代器和迭代的实例基类
// 必须实现Iterator接口

class ObjectIterator implements Iterator
{
	private $obj;
	private $count1;
	private $currentIndex;
	
	function __construct($obj)
	{
		$this->obj = $obj;
		$this->count1 = count($this->obj->data);
	}
	
	function rewind()	// 将数组索引设置为0
	{
		$this->currentIndex = 0;
	}
	
	function valid()	// 判断数组索引是否还有更多的数据
	{
		return $this->currentIndex < $this->count1;
	}
	
	function key()	// 返回数据索引
	{
		return $this->currentIndex;
	}
	
	function current()	// 返回数组当前索引项的值
	{
		return $this->obj->data[$this->currentIndex];
	}
	
	function next()	// 索引值++
	{
		$this->currentIndex++;
	}
}

class Object implements IteratorAggregate
{
	public $data = array();
	
	function __construct($in)
	{
		$this->data = $in;
	}
	
	function getIterator()
	{
		return new ObjectIterator($this);
	}
}

$myObject = new Object(array(2, 4, 5, 6));

$myIterator = $myObject->getIterator();
for ($myIterator->rewind(); $myIterator->valid(); $myIterator->next())	// 复位、判断是否到了最后一个元素、索引加1
{
	$key = $myIterator->key();			// 获取数组的索引
	$value = $myIterator->current();	// 获取数组当前值
	echo $key." => ".$value."<br>";		// 输出打印
}

?>