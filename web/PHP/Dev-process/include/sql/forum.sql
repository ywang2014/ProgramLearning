/*
	论坛话题-头：
*/
use project;
set names utf8;

create table if not exists forums(
	postid int unsigned not null auto_increment primary key,
	parent int unsigned not null comment '话题的父节点',
	author char(30) not null comment '话题创建者',
	title char(100) not null,
	children int default 0 not null comment '回复数量',
	area int default 1 not null comment '用于创建多个论坛',
	post_time int(11) not null comment '发布时间'
)engine=MyISAM default charset=utf8;

create table if not exists forum_body
(
	postid int unsigned not null primary key,
	content text
)engine=MyISAM default charset=utf8;

/* drop table forums; */