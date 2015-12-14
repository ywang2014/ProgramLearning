<?php
/*
	data_valid_fns.php 
*/

// 表单数据项完整性检查
function filled_out($form_vars)
{
	foreach ($form_vars as $key => $v)
	{
		if ((! isset($key)) || ($v == ''))
		{
			return false;
		}
	}
	
	return true;
}

// 邮箱正确性验证
function valid_email($email_add)
{
	return preg_match("/^([a-zA-Z0-9_\.\-])+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/", $email_add);
}
?>