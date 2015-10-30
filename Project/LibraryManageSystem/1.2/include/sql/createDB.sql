/*创建数据库
	创建数据表
	
	直接在命令行启动 MySQL
	mysql -u root -p ******
*/
drop database if exists library;
create database library character set utf8;
use library;
create table manage(id int(10) auto_increment not null,
					name varchar(20),
					password char(50),
					primary key(id), unique id(id)
					)engine = innodb default charset = utf8;
/*	修改属性：alter table modify id int(11) primary key auto_increment;	(如果没有设置主键或自动增加，都可以通过此方法修改属性)
		默认值和 auto_increment 好像不能共存！！！
	desc manage;  (查看表)
	修改字段长度
	alter table manage modify column name varchar(50);
	
*/
create table reader(id int(10) auto_increment not null,
					name varchar(20) not null,
					sex varchar(10) not null,
					password char(50) not null,
					email char(30) not null,
					idnum int(20) not null,
					tel int(15) not null,
					job char(20) not null,
					addr varchar(40) not null,
					max tinyint,
					borrowed tinyint,
					primary key(id), unique id(id)
					)engine = innodb default charset = utf8;
/* id 从特定值开始计数 
	alter table reader AUTO_INCREMENT=10000;
*/
					
create table book(id int unsigned auto_increment not null,
					name varchar(40),
					author varchar(20),
					time char(20),
					pub varchar(40),
					memo char(200),
					num tinyint,
					lend tinyint,
					primary key(id), unique id(id)
					)engine = innodb default charset = utf8;
					
create table booked(id int(10) auto_increment not null,
					re_id int(100),
					book_id int(200),
					returnt int(10),
					able tinyint,
					endm tinyint,
					primary key(id), unique id(id)
					)engine = innodb default charset = utf8;