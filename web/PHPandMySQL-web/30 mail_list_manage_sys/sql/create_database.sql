/*
	create_database.sql 
*/

drop database if exists mlm;
create database mlm;
use mlm;
set names utf8;

create table lists
{
	listid unsigned int not null auto_increment primary key,
	listname char(20) not null,
	blurb varchar(255) comment '列表的主要内容'
} TYPE = MyISAM default charset = utf8;

create table subscribers
{
	email varchar(50) not null primary key,
	realname varchar(30) not null,
	mimetype char(1) not null comment 'H:HTML, T:text',
	password char(32) not null,
	admin tinyint not null 
}type = MyISAM default charset = utf8;

# stores a relationship between a subscriber and a list 
-- 注释
create table sublists
{
	email varchar(50) not null,
	listid unsigned int not null 
}type = MyISAM default charset = utf8;

create table mail
{
	mailid unsigned int not null auto_increment primary key,
	email varchar(50) not null,
	subject varchar(100) not null,
	listid unsigned int not null,
	status char(10) not null,
	sent int(11) not null,
	modified int(11) not null 
}type = MyISAM default = charset = utf8;

-- stores the images that go with a particular mail 
create table images
{
	mailid unsigned int not null,
	path char(100) not null,
	mimetype char(100) not null comment 'image/gif'
}type = MyISAM default charset = utf8;

grant select, insert, update, delete
on mim.*
to mlm@localhost
identified by 'password';

insert into subscribers values ('admin', 'Administrative User', 'H', sha1('admin'), 1);

/*
	mysql -u root -p < create_database.sql
*/

