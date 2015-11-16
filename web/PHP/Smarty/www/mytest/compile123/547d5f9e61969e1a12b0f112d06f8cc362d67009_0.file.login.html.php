<?php /* Smarty version 3.1.27, created on 2015-11-14 12:02:11
         compiled from "D:\Soft\PHP\PHPnow-1.5.6\htdocs\127.0.0.100\www\mytest\template123\login.html" */ ?>
<?php
/*%%SmartyHeaderCode:27089564722c366d5c3_38511138%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '547d5f9e61969e1a12b0f112d06f8cc362d67009' => 
    array (
      0 => 'D:\\Soft\\PHP\\PHPnow-1.5.6\\htdocs\\127.0.0.100\\www\\mytest\\template123\\login.html',
      1 => 1447502498,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '27089564722c366d5c3_38511138',
  'variables' => 
  array (
    'title' => 0,
    'content' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_564722c36a3a33_57061408',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_564722c36a3a33_57061408')) {
function content_564722c36a3a33_57061408 ($_smarty_tpl) {

$_smarty_tpl->properties['nocache_hash'] = '27089564722c366d5c3_38511138';
?>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-Type" content = "text/html; charset = utf-8"/>
		<title> <?php echo $_smarty_tpl->tpl_vars['title']->value;?>
 </title>
	</head>
	<body>
		<div>
			<?php echo $_smarty_tpl->tpl_vars['content']->value;?>

			<p> <a href = "index_path.php"> Homepage.php----可以访问  </a> </p>
			<p> <a href = "index.html"> Homepage.html----不能访问  </a> </p>
			<p> <a href = "www.sina.com"> www.sina.com----不能访问  </a> </p>
			<p> <a href = "http://www.sina.com"> http://www.sina.com ----可以访问  </a> </p>
		</div>
	</body>
</html><?php }
}
?>