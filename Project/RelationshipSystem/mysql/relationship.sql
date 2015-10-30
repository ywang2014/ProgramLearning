/*
* 创建能够识别中文的数据库
* CREATE DATABASE friends CHARACTER SET utf-8;
* 或者 alter修改：
* ALTER DATABASE dbname CHARACTER SET utf-8;
*/

drop database if exists friends;
create database friends character set utf-8;

use friends;

create table classmates(
						cid int unsigned not null auto_increment primary key,
						name char(30) not null,
						gender char(10) not null,
						emial char(30) not null,
						school char(50),
						birthday int unsigned,
						qq int unsigned,
						tel int unsigned,
						city char(100),
						job char(30) not null,
						hobby text,
						introduce text,
						rtime date not null
						)engine = innodb default charset = utf8;
						
create table personalInfo(
						pid int unsigned not null auto_increment primary key,
						fid int unsigned not null,
						tele char(12),
						birthday date,
						address char(100),
						school char(50) not null
						)engine = innodb default charset = utf8;