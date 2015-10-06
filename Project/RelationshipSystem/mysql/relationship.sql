-- relationship.sql

/* 
把SQL脚本放到MySQL命令行里执行：

	mysql -u root -p
	
	relationship.sql;
	
	不能执行！！！！
	命令行输入！
*/

drop database if exists relationship;

create database relationship;

use relationship;

create table friends(
					id int(10) auto_increment not null,
					name varchar(20) not null,
					sex varchar(10),
					email varchar(50),
					city varchar(50),
					tel varchar(15) not null,
					birthday int(10),
					primary key (id), unique id(id)
				) engine = innodb default charset = utf8;

