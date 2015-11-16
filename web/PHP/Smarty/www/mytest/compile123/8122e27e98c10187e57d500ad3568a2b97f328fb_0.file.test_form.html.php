<?php /* Smarty version 3.1.27, created on 2015-11-13 04:38:26
         compiled from "D:\Soft\PHP\PHPnow-1.5.6\htdocs\127.0.0.100\www\mytest\template123\test_form.html" */ ?>
<?php
/*%%SmartyHeaderCode:4536564569421480e0_10622945%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '8122e27e98c10187e57d500ad3568a2b97f328fb' => 
    array (
      0 => 'D:\\Soft\\PHP\\PHPnow-1.5.6\\htdocs\\127.0.0.100\\www\\mytest\\template123\\test_form.html',
      1 => 1447388199,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '4536564569421480e0_10622945',
  'variables' => 
  array (
    'arr1' => 0,
    'key1' => 0,
    'item1' => 0,
    'forum' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_56456942263d98_06079122',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_56456942263d98_06079122')) {
function content_56456942263d98_06079122 ($_smarty_tpl) {

$_smarty_tpl->properties['nocache_hash'] = '4536564569421480e0_10622945';
?>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-Type" content = "text/html; charset = utf-8" />
		<title> 巢状循环测试 </title>
	</head>
	
	<body>
		<div>
			<table cellpadding = 10>
				<tr>
					<td> 
						<?php
$_from = $_smarty_tpl->tpl_vars['arr1']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$_smarty_tpl->tpl_vars['item1'] = new Smarty_Variable;
$_smarty_tpl->tpl_vars['item1']->_loop = false;
$_smarty_tpl->tpl_vars['key1'] = new Smarty_Variable;
foreach ($_from as $_smarty_tpl->tpl_vars['key1']->value => $_smarty_tpl->tpl_vars['item1']->value) {
$_smarty_tpl->tpl_vars['item1']->_loop = true;
$foreach_item1_Sav = $_smarty_tpl->tpl_vars['item1'];
?>
						<?php echo $_smarty_tpl->tpl_vars['key1']->value;?>
 : <?php echo $_smarty_tpl->tpl_vars['item1']->value;?>

						<?php
$_smarty_tpl->tpl_vars['item1'] = $foreach_item1_Sav;
}
?>
					</td>
				</tr>
			</table>  
			<p> <!-- <a href = "<?php echo '<?php ';?>echo $path; <?php echo '?>';?>template123/test.html"> 测试 </a> -->
				<a href = "/127.0.0.100/www/mytest/template123/test.html"> 测试 </a>
			</p>
			<!--- <p> <a href = "test.html"> 测试 </a> </p> 
				/127.0.0.100/www/mytest/test.html was not found on this server.
			-->
		</div>
		<div>
			<table width = "200" border = 0 align = "center" cellpadding = 10>
				<?php if (isset($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2'])) unset($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['name'] = 'sec2';
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['loop'] = is_array($_loop=$_smarty_tpl->tpl_vars['forum']->value) ? count($_loop) : max(0, (int) $_loop); unset($_loop);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['show'] = true;
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['max'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['loop'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['step'] = 1;
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['start'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['step'] > 0 ? 0 : $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['loop']-1;
if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['show']) {
    $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['total'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['loop'];
    if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['total'] == 0)
        $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['show'] = false;
} else
    $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['total'] = 0;
if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['show']):

            for ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['start'], $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration'] = 1;
                 $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration'] <= $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['total'];
                 $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index'] += $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['step'], $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration']++):
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['rownum'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index_prev'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index'] - $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['step'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index_next'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['index'] + $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['step'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['first']      = ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration'] == 1);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['last']       = ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['iteration'] == $_smarty_tpl->tpl_vars['smarty']->value['section']['sec2']['total']);
?>
				<tr>
					<td colspan = 2>
						<?php echo $_smarty_tpl->tpl_vars['forum']->value[$_smarty_tpl->getVariable('smarty')->value['section']['sec2']['index']]['category_name'];?>

					</td>
				</tr>
				<?php if (isset($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3'])) unset($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['name'] = 'sec3';
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['loop'] = is_array($_loop=$_smarty_tpl->tpl_vars['forum']->value[$_smarty_tpl->getVariable('smarty')->value['section']['sec2']['index']]['topic']) ? count($_loop) : max(0, (int) $_loop); unset($_loop);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['show'] = true;
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['max'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['loop'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['step'] = 1;
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['start'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['step'] > 0 ? 0 : $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['loop']-1;
if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['show']) {
    $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['total'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['loop'];
    if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['total'] == 0)
        $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['show'] = false;
} else
    $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['total'] = 0;
if ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['show']):

            for ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['start'], $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration'] = 1;
                 $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration'] <= $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['total'];
                 $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index'] += $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['step'], $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration']++):
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['rownum'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index_prev'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index'] - $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['step'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index_next'] = $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['index'] + $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['step'];
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['first']      = ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration'] == 1);
$_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['last']       = ($_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['iteration'] == $_smarty_tpl->tpl_vars['smarty']->value['section']['sec3']['total']);
?>
				<tr>
					<td width = "25"></td>
					<td width = "164">
						<?php echo $_smarty_tpl->tpl_vars['forum']->value[$_smarty_tpl->getVariable('smarty')->value['section']['sec2']['index']]['topic'][$_smarty_tpl->getVariable('smarty')->value['section']['sec3']['index']]['topic_name'];?>

					</td>
				</tr>
				<?php endfor; endif; ?>
				<?php endfor; endif; ?>
			</table>
		</div>
	</body>
</html>
<?php }
}
?>