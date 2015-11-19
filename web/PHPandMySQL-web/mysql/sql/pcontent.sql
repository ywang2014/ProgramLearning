/*
	项目内容表：
*/
use wuliu;
set names utf8;

create table if not exists pcontents(
	coid int unsigned not null auto_increment primary key comment '内容id', 
	pid int unsigned not null comment '项目id',
	username varchar(30) not null comment '说话者',
	topic varchar(100) not null comment '谈论主题',
	content text comment '谈论内容',
	ptime int(10) not null comment '发言时间'
)engine=MyISAM default charset=utf8;

/* drop table pcontents; */