<?php
/*
	模板类：
	
	模板文件-->php文件
	{ $value } --> <?php echo $value; ?>
*/

class mini
{
	/* 分离模板和解析文件的目录，便于区分 */
	public $template_dir = '';	// 模板文件路径
	public $compile_dir = '';	// 模板编译后的文件位置
	
	/* 
		string $template 模板文件名
		return string
		
		读指定模板的内容，编译成php
	*/
	public function compile($template)
	{
		$source = file_get_contents($this->template_dir.'/'.$template);
		//echo $source;
		
		// 替换模板内容
		$source = str_replace('{', '<?php echo ', $source);
		$source = str_replace('}', '; ?>', $source);
		//echo $source;
		
		// 把编译的内容，保存成 .php文件
		$path = $this->compile_dir.'/'.$template.'.php';
		file_put_contents($path, $source);
		
		return $path;
	}
}
?>
