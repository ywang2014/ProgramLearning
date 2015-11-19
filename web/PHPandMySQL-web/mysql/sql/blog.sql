/*
	博客表：
*/
use wuliu;
set names utf8;

create table if not exists blogs(
	bid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '博主名',
	blogname varchar(100) not null comment '博文名称',
	content text comment '博文内容',
	support int default 0 comment '点赞数量',
	ptime int(10) not null comment '发布时间',
	ctime int(10) not null comment '最新评论时间'
)engine=MyISAM default charset=utf8;

/* drop table blogs; */