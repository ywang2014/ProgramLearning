<?php

require_once('bookmark_fns.php');
session_start();

do_html_header('Delete bookmark');

check_valid_user();

display_delete_bm_form($_SESSION['valid_user']);

do_html_footer();

?>