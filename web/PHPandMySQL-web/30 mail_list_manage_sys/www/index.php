<?php
/*
	index.php --- 金字塔式MLM的主要应用程序文件
	事件驱动方法
*/

/********************************************************************************************
	Section 1: pre-processing
********************************************************************************************/
include("include_fns.php");
session_start();

$action = isset($_GET['action']) ? $_GET['action'] : '';
$buttons = array();

// append to this string if anything processed before header has output_add_rewrite_var
$status = "";

// need to process log in or out requests before anything else
if (($_POST['email']) && ($_POST['password']))
{
	$login = login($_POST['email'], $_POST['password']);
	
	if ($login == 'admin')
	{
		$status .= "<p style = \"padding-bottom:50px; \" >".
				"<string>".get_real_name($_POST['email'])."</strong>".
				"logged in successfully as <strong> Administrator </strong> . </p>";
		$_SESSION['admin_user'] = $_POST['email'];
	}
	else if ($login == "normal")
	{
		$status .= "<p style = \"padding-bottom:50px; \" >".
				"<string>".get_real_name($_POST['email'])."</strong>".
				"logged in successfully . </p>";
		$_SESSION['normal_user'] = $_POST['email'];
	}
	else
	{
		$status .= "<p style = \"padding-bottom:50px; \" >".
				"Sorry, we could not log you in with this email address and password . </p>";
	}
}

if ($action == "log_out")
{
	unset($action);
	$_SESSION = array();
	session_destroy();
}


/********************************************************************************************
Section 2: set up and display headers
********************************************************************************************/

// set the buttons that will be on the tool bar
if (check_normal_user())
{
	// if a normal user 
	$buttons[0] = 'change_password';
	$buttons[1] = 'account_settings';
	$buttons[2] = 'show_my_lists';
	$buttons[3] = 'show_other_lists';
	$buttons[4] = 'log_out';
}
else if (check_admin_user())
{
	// if an administrator
	$buttons[0] = 'change_password';
	$buttons[1] = 'create_list';
	$buttons[2] = 'create_mail';
	$buttons[3] = 'view_mail';
	$buttons[4] = 'log_out';
	$buttons[5] = 'show_all_lists';
	$buttons[6] = 'show_my_lists';
	$buttons[7] = 'show_other_lists';
}
else
{
	// if not logged in at all
	$buttons[0] = "new_account";
	$buttons[1]= "show_all_list";
	$buttons[2] = "log_in";
}

if ($action)
{
	// display header with application name and description of page or action 
	do_html_header("Pyramid-MLM - ".format_action($action));
}
else
{
	// display header with just application name 
	do_html_header("Pyramid-MLM");
}

display_localbar($buttons);

// display any text generated by login functions called before header 
echo $status;


/********************************************************************************************
	Section 3: perform action 
********************************************************************************************/

// only these action can be done if not logged in
switch ($action)
{
	case "new_account":
		// get rid of session variables
		session_destroy();
		display_account_form();
		break;
		
	case "store_account":
		if (store_account($_SESSION['normal_user'], $_SESSION['admin_user'], $_POST))
		{
			$action = '';
		}
		
		if (!check_logged_in())
		{
			display_login_form($action);
		}
		break;
		
	case 'log_in':	// 归并到 default中
	
	case '':
		if (!check_logged_in())
		{
			display_login_form($action);
		}
		break;
		
	case 'show_all_lists':
		display_items('Archive For '.get_list_name($_GET['id']), get_archive($_GET['id']), 'view_html', 'view_text', '');
		break;
		
	case 'information':
		display_information($_GET['id']);
		break;
		
	default:
		if (!check_logged_in())
		{
			display_login_form($action);
		}
		break;
}

// all other actions require user to be logged in
if (check_logged_in())
{
	switch ($action)
	{
		case 'account_settings':
			display_account_form(get_email(), get_real_name(get_email()), get_mimetype(get_email()));
			break;
			
		case 'show_other_lists':
			display_items('Unsubscribed Lists', get_unsubscribed_lists(get_email()), 'information', 'show_archive', 'subscribe');
			break;
			
		case 'subscribe':
			subscribe(get_email(), $_GET['id']);
			display_items('Subscribed Lists', get_subscribed_lists(get_email()), 'information', 'show_archive', 'unsubscribe');
			break;
			
		case 'unsubscribe':
			unsubscribe(get_email(), $_GET['id']);
			display_items('Subscribed Lists', get_subscribed_lists(get_email()), 'information', 'show_archive', 'unsubscribe');
			break;
			
		case '':
		
		case 'show_my_lists':
			display_items('Subscribed Lists', get_subscribed_lists(get_email()), 'information', 'show_archive', 'unsubscribe');
			break;
			
		case 'change_password':
			display_password_form();
			break;
			
		case 'store_change_password':
			if (change_password(get_email(), $_POST['old_password'], $_POST['new_password'], $_POST['new_password2']))
			{
				echo "<p style = \"padding-bottom:50px; \" > OK: Password changed. </p>";
			}
			else
			{
				echo "<p style = \"padding-bottom:50px; \" > Sorry, your password could not be changed, </p>";
				display_password_form();
			}
			break;
	}
}

// The following actions may only be performed by an admin user 
if (check_admin_user())
{
	switch ($action)
	{
		case 'create_mail':
			display_mail_form(get_email());
			break;
			
		case 'create_list':
			display_list_form(get_email());
			break;
			
		case 'store_list':
			if (store_list($_SESSION['admin_user'], $_POST))
			{
				echo "<p style = \"padding-bottom: 50px;\"> New list added. </p>";
				display_items('ALL Lists', get_all_lists(), 'information', 'show_archive', '');
			}
			else
			{
				echo "<p style = \"padding-bottom: 50px;\" > List could not be stored. Please try again. </p>";
			}
			break;
			
		case 'send':
			send($_GET['id'], $_SESSION['admin_user']);
			break;
			
		case 'view_mail':
			display_items('Unsent Mail', get_unsent_mail(get_email()), 'preview_html', 'preview_text', 'send');
			break;
	}
}


/********************************************************************************************
	Section 4: display footer
********************************************************************************************/

do_html_footer();

?>