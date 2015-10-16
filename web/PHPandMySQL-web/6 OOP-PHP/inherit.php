<?php
// 面向对象--继承

class A
{
	public $attribute;
	
	private function oper1()
	{
		echo "Operation one called!";
	}
	
	protected function oper2()
	{
		echo "Operation two called!";
	}
	
	public function oper3()
	{
		echo "Operation three called!"
	}
}

class B extends A
{
	function __construct()
	{
		//$this->oper1();	// fatal error 私有方法不能被继承！
		$this->oper2();
		$this->oper3();
	}
}
$a_case = new A();
$b_case = new B();

//$b_case->oper2();	// fatal error protected函数可以被继承，但是只能在子类内部使用
$b_case->oper3();

//$a_case->oper1();	// 私有方法，外部不能使用
$a_case->oper2();	// ??
$a_case->oper3();



?>