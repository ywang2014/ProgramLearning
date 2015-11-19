/*
	用户表：
*/
use wuliu;
set names utf8;

create table if not exists users(
	uid int unsigned not null auto_increment primary key,
	username varchar(30) not null comment '用户名',
	password varchar(32) not null,
	email varchar(30) not null,
	token varchar(50) not null,
	token_exptime int(10) not null,
	status tinyint(1) not null default '0' comment '状态，0-未激活，1-已激活',
	regtime int(10) not null
)engine=MyISAM default charset=utf8;

/* drop table users; */
/* insert into email_user values (11, 'alice', 'alice', 'alice', 'alice', 123, 0, 123); */