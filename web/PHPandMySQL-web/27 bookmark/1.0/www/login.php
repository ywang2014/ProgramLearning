<?php
/*
	系统首页，提供登录界面
*/

require_once('bookmark_fns.php');
do_html_header('');

display_site_info();
display_login_form();

do_html_footer();

?>