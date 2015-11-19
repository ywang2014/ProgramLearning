/*
	博客评论表：
*/
use wuliu;
set names utf8;

create table if not exists bcomments(
	cid int unsigned not null auto_increment primary key comment '评论id', 
	bid int unsigned not null comment '博客id',
	username varchar(30) not null comment '评论者',
	content text comment '评论内容',
	support int default 0 comment '点赞数量',
	ctime int(10) not null comment '评论时间'
)engine=MyISAM default charset=utf8;

/* drop table bcomments; */