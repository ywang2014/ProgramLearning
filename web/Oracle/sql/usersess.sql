/*
	usersess.sql
	创建一个在 SQL*Plus 中运行的 SQL*Plus 脚本文件
*/

column username format a30
column logon_time format a18
set pagesize 1000 feedback off echo on
alter session set nls_date_format = 'DD-MON-YY HH:MI:SS';
select username, logon_time from v$session where username is not null;

/*
*	在 SQL*Plus 会话中，输入以下命令，以 HR 用户身份登录到数据库并创建一个新表：
	
	connect hr/hrpwd@//localhost/orcl
	create table mytable (col1 date);
*
*/