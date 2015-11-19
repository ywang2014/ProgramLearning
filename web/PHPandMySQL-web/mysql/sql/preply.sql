/*
	项目内容回复表：
*/
use wuliu;
set names utf8;

create table if not exists preplys(
	rid int unsigned not null auto_increment primary key comment '回复id', 
	coid int unsigned not null comment '内容id',
	username varchar(30) not null comment '说话者',
	content text comment '回复内容',
	rtime int(10) not null comment '回复时间'
)engine=MyISAM default charset=utf8;

/* drop table preply; */