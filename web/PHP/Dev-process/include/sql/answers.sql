/*
	问题回答表：
*/
use project;
set names utf8;

create table if not exists answers(
	aid int unsigned not null auto_increment primary key,
	qid int unsigned not null,
	username varchar(30) not null comment '提问者',
	content text comment '问题描述',
	ptime int(11) not null comment '提交时间'
)engine=MyISAM default charset=utf8;

/* drop table questions; */