/*
	邮件数据库
*/

drop database if exists mail;

create database mail;

use mail;

set names utf8;

create table usermails
{
	username varchar(30) not null primary key,
	password char(32) not null,
	address varchar(50) not null,
	displayname varchar(50) not null
}default charset=utf8;

create table accounts
{
	accountid unsigned int not null auto_increment primary key,
	username varchar(30) not null,
	server varchar(100) not null,
	port int not null,
	remoteuser varchar(50) not null,
	remotepassword varchar(50) not null,
}default charset=utf8;

grant select, insert, update, delete 
on mail.*
to mail@localhost 
identified by 'mail';