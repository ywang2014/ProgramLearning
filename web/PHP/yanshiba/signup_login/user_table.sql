/*
	用户表
*/

create table users(
				user_id	int unsigned not null auto_increment primary key,
				username varchar(16) not null default '',
				email varchar(30) not null default '',
				password char(30) not null default '',
				regtime int unsigned not null default 0,
				lastlogin int unsigned not null default 0
				) engine myisam charset utf8;