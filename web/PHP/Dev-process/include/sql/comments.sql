/*
	博客评论：
*/
use project;
set names utf8;

create table if not exists comments(
	cid int unsigned not null auto_increment primary key,
	bid int unsigned not null,
	username varchar(30) not null comment '回复者',
	content text comment '内容',
	ptime int(11) not null comment '发布时间'
)engine=MyISAM default charset=utf8;

/* drop table blogs; */