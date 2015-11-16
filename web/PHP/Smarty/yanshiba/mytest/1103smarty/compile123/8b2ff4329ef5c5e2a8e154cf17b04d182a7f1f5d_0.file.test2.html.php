<?php /* Smarty version 3.1.27, created on 2015-11-03 15:06:04
         compiled from "D:\Soft\PHP\PHPnow-1.5.6\htdocs\127.0.0.100\www\mytest\template123\test2.html" */ ?>
<?php
/*%%SmartyHeaderCode:96725638cd5ce28326_28120236%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '8b2ff4329ef5c5e2a8e154cf17b04d182a7f1f5d' => 
    array (
      0 => 'D:\\Soft\\PHP\\PHPnow-1.5.6\\htdocs\\127.0.0.100\\www\\mytest\\template123\\test2.html',
      1 => 1446563162,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '96725638cd5ce28326_28120236',
  'variables' => 
  array (
    'title' => 0,
    'name' => 0,
    'tel' => 0,
    'email' => 0,
    'us' => 0,
    'us2' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_5638cd5ce91999_17874004',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_5638cd5ce91999_17874004')) {
function content_5638cd5ce91999_17874004 ($_smarty_tpl) {

$_smarty_tpl->properties['nocache_hash'] = '96725638cd5ce28326_28120236';
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
			table
			{
				background:gray;
			}
		</style>
	</head>
	
	<body>
		<h1> <?php echo $_smarty_tpl->tpl_vars['title']->value;?>
 </h1>
		<table>
			<tr> 
				<td> 姓名：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['name']->value;?>
 </td>
			</tr>
			<tr> 
				<td> 电话：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['tel']->value;?>
 </td>
			</tr>
			<tr> 
				<td> 邮箱：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['email']->value;?>
 </td>
			</tr>
			<tr> <td> <br> </td></tr>
			
			<tr> 
				<td> 姓名：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us']->value['name'];?>
 </td>
			</tr>
			<tr> 
				<td> 电话：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us']->value['tel'];?>
 </td>
			</tr>
			<tr> 
				<td> 邮箱：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us']->value['email'];?>
 </td>
			</tr>
			<tr> <td> <br> </td></tr>
			
			<tr> 
				<td> 姓名：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us2']->value[0];?>
 </td>
			</tr>
			<tr> 
				<td> 电话：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us2']->value[1];?>
 </td>
			</tr>
			<tr> 
				<td> 邮箱：</td>
				<td> <?php echo $_smarty_tpl->tpl_vars['us2']->value[2];?>
 </td>
			</tr>
		
		</table>
	</body>
</html><?php }
}
?>