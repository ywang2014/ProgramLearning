/*
	应用程序数据库表
	mysql -uroot -p < bookmark.sql
*/

use friends;

set names utf8;

create table users(
					uid int unsigned not null auto_increment primary key,
					username char(30) not null,
					password char(32) not null,
					email char(30) not null,
					rtime int(11) not null
					)engine=MyISAM default charset=utf8;
				/*	engine = innodb default charset = utf8; */
			
create table bookmark(
						bid int unsigned not null auto_increment primary key,
						username varchar(30) not null,
						bm_url varchar(255) not null,
						index (username),
						index (bm_url)
						)engine = MyISAM default charset=utf8;

/* drop table bookmark; */						
/*
// grant 权限 on 数据库.* to 用户名@登录主机 identified by "密码";

grant all privileges on friends.*
	to 'friend'
	identified by 'friend' with grant option;
	
set password for 'username@%' = password('newpassword');

Delete FROM user Where User='test' and Host='localhost';

drop user 用户名@'%';
drop user 用户名@ localhost;
*/
grant select, insert, update, delete
	on friends.*
	to friend@'localhost'
	identified by 'friend';
	
flush privileges;
