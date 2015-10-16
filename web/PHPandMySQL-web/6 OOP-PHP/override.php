<?php
// 面向对象---- 重载
class A
{
	public $attribute = "I am the base class!";
	
	public function operation()
	{
		echo "Somthing... <br>";
		echo "The value of \$attribute is ".$this->attribute."<br>";
	}
}

class B extends A
{
	public $attribute = "I am the derived class";
	
	public function operation()
	{
		echo "Something else...<br>";
		echo "The value of \$attribute is ".$this->attribute."<br>";
	}
}

// 动态语言不存在类型要求，任意声明变量，直接使用，如何体现多态呢？
$a_case = new A();
$b_case = new B();

$a_case->operation();
$b_case->operation();
$b_case->parent::operation();	// parent关键字可以访问父类的东西！

// 无继承关系的类也可以一样的使用？
class C
{
	function operation()
	{
		echo "I am C class. <br>";
	}
}

$c_case = new C();
$c_case->operation();


?>