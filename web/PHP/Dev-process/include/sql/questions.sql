/*
	问题：
*/
use project;
set names utf8;

create table if not exists questions(
	qid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '提问者',
	title varchar(200) not null comment '主题',
	content text comment '问题描述',
	notice varchar(2) not null default 'on' comment '是否邮件通知用户',
	wealth int not null default 0 comment '悬赏的财富值',
	ptime int(11) not null comment '提交时间'
)engine=MyISAM default charset=utf8;

/* drop table questions; */