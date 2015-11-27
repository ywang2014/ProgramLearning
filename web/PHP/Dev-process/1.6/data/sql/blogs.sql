/*
	博客文章：
*/
use project;
set names utf8;

create table if not exists blogs(
	bid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '博主',
	title varchar(200) not null comment '主题',
	types varchar(30) not null comment '类型',
	content text comment '内容',
	ptime int(11) not null comment '发布时间'
)engine=MyISAM default charset=utf8;

/* drop table blogs; */