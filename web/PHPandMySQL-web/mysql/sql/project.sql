/*
	项目表：
*/
use wuliu;
set names utf8;

create table if not exists projects(
	pid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '发布项目任务者',
	expert varchar(30) not null comment '专家',
	projectname varchar(100) not null comment '项目主题',
	summary text comment '项目总结',
	ptime int(10) not null comment '发布时间'
)engine=MyISAM default charset=utf8;

/* drop table projects; */