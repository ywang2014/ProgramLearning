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
	status tinyint not null default 1 comment '1 文件正常，0文件删除',
	uptime int(11) not null comment '上传时间',
	del_time int(11) not null comment '删除时间'
)engine=MyISAM default charset=utf8;

/* drop table files;
update files set status = 1 where 1;	// 全部修改

 */