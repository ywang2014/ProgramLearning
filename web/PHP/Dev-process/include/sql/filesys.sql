/*
	文件系统管理表：
*/
use project;
set names utf8;

create table if not exists files(
	fid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '上传文件者',
	filename varchar(30) not null comment '文件名',
	filepath varchar(100) not null comment '文件存储路径',
	uptime int(11) not null comment '上传时间'
)engine=MyISAM default charset=utf8;

/* drop table files; */