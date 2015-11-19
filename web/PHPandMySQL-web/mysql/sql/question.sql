/*
	问题表：
*/
use wuliu;
set names utf8;

create table if not exists questions(
	qid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '提问者',
	questionname varchar(100) not null comment '问题主题',
	content text comment '问题内容',
	support int default 0 comment '点赞数量',
	ptime int(10) not null comment '发布时间',
	atime int(10) not null comment '最新回答时间'
)engine=MyISAM default charset=utf8;

/* drop table questions; */