/*
	问题回答表：
*/
use wuliu;
set names utf8;

create table if not exists qanswers(
	aid int unsigned not null auto_increment primary key comment '回答id', 
	qid int unsigned not null comment '问题id',
	username varchar(30) not null comment '回答者',
	content text comment '回答内容',
	support int default 0 comment '点赞数量',
	atime int(10) not null comment '回答时间'
)engine=MyISAM default charset=utf8;

/* drop table qanswers; */