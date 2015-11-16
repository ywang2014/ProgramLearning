<?php /* Smarty version 3.1.27, created on 2015-11-14 12:02:15
         compiled from "D:\Soft\PHP\PHPnow-1.5.6\htdocs\127.0.0.100\www\mytest\template123\index.html" */ ?>
<?php
/*%%SmartyHeaderCode:27702564722c7432d65_42690596%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '3e5078e2727e70da285d9caef13396a5b2e73d35' => 
    array (
      0 => 'D:\\Soft\\PHP\\PHPnow-1.5.6\\htdocs\\127.0.0.100\\www\\mytest\\template123\\index.html',
      1 => 1447502529,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '27702564722c7432d65_42690596',
  'variables' => 
  array (
    'title' => 0,
    'content' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_564722c745fea1_33206072',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_564722c745fea1_33206072')) {
function content_564722c745fea1_33206072 ($_smarty_tpl) {

$_smarty_tpl->properties['nocache_hash'] = '27702564722c7432d65_42690596';
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

			<p> <a href = "login.php"> login.php---能 </a> </p>
			<p> <a href = "login.html"> login.html---不能 </a> </p>
			<p> <a href = "www.baidu.com"> www.baidu.com---不能 </a> </p>
			<p> <a href = "http://www.baidu.com"> http://www.baidu.com---能  </a> </p>
		</div>
	</body>
</html><?php }
}
?>