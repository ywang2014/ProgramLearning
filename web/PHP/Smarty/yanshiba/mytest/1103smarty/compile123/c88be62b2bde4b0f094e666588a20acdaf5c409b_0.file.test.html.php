<?php /* Smarty version 3.1.27, created on 2015-11-03 15:07:10
         compiled from "D:\Soft\PHP\PHPnow-1.5.6\htdocs\127.0.0.100\www\mytest\template123\test.html" */ ?>
<?php
/*%%SmartyHeaderCode:139215638cd9e8a77a2_13933096%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'c88be62b2bde4b0f094e666588a20acdaf5c409b' => 
    array (
      0 => 'D:\\Soft\\PHP\\PHPnow-1.5.6\\htdocs\\127.0.0.100\\www\\mytest\\template123\\test.html',
      1 => 1446563209,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '139215638cd9e8a77a2_13933096',
  'variables' => 
  array (
    'title' => 0,
    'content' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_5638cd9e8c8d11_06048462',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_5638cd9e8c8d11_06048462')) {
function content_5638cd9e8c8d11_06048462 ($_smarty_tpl) {

$_smarty_tpl->properties['nocache_hash'] = '139215638cd9e8a77a2_13933096';
?>
<!DOCTYPE html PUBLIC "-//WAC//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml" lang = "zh-CN">
	<head>
	
		<title> <?php echo $_smarty_tpl->tpl_vars['title']->value;?>
 </title>
		
		<meta http-equiv = "Content-Type" content = "text/html" charset = "utf-8">
		<meta name = "description" content = "">
		<meta name = "keywords" content = "">
		
		<?php echo '<script'; ?>
 type = "text/javascript">
		
		<?php echo '</script'; ?>
>
		
		<style type = "text/css">
		
		</style>
	</head>
	
	<body>
		<h1> <?php echo $_smarty_tpl->tpl_vars['title']->value;?>
 </h1>
		<p> <?php echo $_smarty_tpl->tpl_vars['content']->value;?>
 </p>
		
	</body>
</html><?php }
}
?>