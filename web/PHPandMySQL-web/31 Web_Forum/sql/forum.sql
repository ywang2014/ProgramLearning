/*
	Forum.sql
	创建论坛数据库脚本
	
	mysql -u root -p < forum.sql
*/

drop database if exists forum;
create database forum;
use forum;
set names utf8;

create table header
(
	postid int unsigned not null auto_increment primary key,
	parent int unsigned not null,
	author char(20) not null,
	title char(100) not null,
	children int default 0 not null,
	area int default 1 not null,
	post_time int(11) not null 
)engine = MyISAM default charset = utf8;

create table body
{
	postid int unsigned not null primary key,
	content text
}engine = MyISAM default charset = utf8;

grant select, insert, update, delete
on forum.*
to forum@localhost
identified by 'password';