create database test;
use test;
create table users{
			name varchar(20),
			password varchar(32),
			primary key (name)
			};
insert into users values ('username', 'password');
insert into users values ('testuser', sha1('password'));

/*    *.*所有数据库，所有表    */
grant select on test.* to 'admin' identified by 'admin';
flush privileges;	/* 立即生效，不需要重启 */

/* 
	grant select,insert,update,delete,create,drop on db.table
	to username
	identified by ‘123′ with grant option;  
*/


