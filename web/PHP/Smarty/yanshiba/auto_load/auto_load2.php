<?php
/*
	自动加载方法
		此函数，自动运行，不需要主动调用，发现没有的类的时候，就会自动加载
	
	解决方法：自定义方法名，再注册。
*/

function autoMan($class)
{
	echo "man";
	include('./'.$class.'.class.php');
}

function autoWoman($class)
{
	echo "woman";
	include('./'.$class.'.php');
}

spl_autoload_register('autoMan');	// 把autoMan注册为自动加载函数
spl_autoload_register('autoWoman');	// 把autoWoman注册为自动加载函数

//$man = new Man();
//print_r($man);

$woman = new Woman();
print_r($woman);

/*
	注册了多个自动加载函数
	则按照先后顺序执行，试图找到需要的类
*/

/*
	spl_autoload_register('fun');
	它的优先级比__autoload高，把__autoload给覆盖了
	这就是多个框架、库自动加载不兼容的原因
	
	解决办法：不使用__autoload函数，换一个名字，然后注册成为自动加载函数

*/

function __autoloadBool($class)
{
	if (strtolower(substr($class, -5)) == 'model')
	{
		require(ROOT.'Model/'.$class.'.class.php');
	}
	else if (strtolower(substr($class, -4)) == 'tool')
	{
		require(ROOT.'tool/'.$class.'.class.php');
	}
	else	// 必须准确判断，不能else，否则还是有问题
	{
		require(ROOT.'includes/'.$class.'.class.php');
	}
}

spl_autoload_register('__autoloadBool');

?>