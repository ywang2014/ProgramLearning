<?php
/*
	继承方式：统一配置Smarty
*/

class Mysmarty extends Smarty
{
	public function __construct()
	{
		/*
			template_dir
			compile_dir
			属于私有属性，不能直接重写，直接报错。必须通过开放的接口访问
		*/
		parent::__construct();
		
		$this->setTemplateDir('./tempalte');
		$this->setCompileDir('./compile');
	}
}
?>