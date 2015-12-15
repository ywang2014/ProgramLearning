/*
	创建数据库
*/

drop database if exists book_sc;
create database book_sc;
use book_sc;
set names utf8;

create table customers
(
	customerid int unsigned not null auto_increment primary key,
	name varchar(60) not null,
	address varchar(80) not null,
	city varchar(30) not null,
	states char(20),
	zip char(10),
	country char(20) not null
)type=InnoDB default charset=utf8;


create table orders
(
	orderid int unsigned not null auto_increment primary key,
	customerid int unsigned not null references customers(customerid),
	amount float(6, 2),
	otime int(11) not null,
	order_status char(10),
	ship_name char(60) not null,
	ship_address varchar(80) not null,
	ship_city varchar(30) not null,
	ship_state char(20),
	ship_zip char(10),
	ship_country char(20) not null 
)type=InnoDB default charset=utf8;


create table books
(
	isbn char(13) not null primary key,
	author varchar(50),
	title varchar(100),
	catid int unsigned,
	price float(4, 2) not null,
	description varchar(255)
)type=InnoDB default charset=utf8;


create table categories
(
	catid int unsigned not null auto_increment primary key,
	catname char(60) not null
)type=InnoDB default charset=utf8;

create table order_items
(
	orderid int unsigned not null references orders(orderid),
	isbn char(13) not null references books(isbn),
	item_price float(4, 2) not null,
	quantity tinyint unsigned not null,
	primary key (orderid, isbn)
)type=InnoDB default charset=utf8;

create table admin
(
	username varchar(16) not null primary key,
	password char(40) not null 
)default charset=utf8;

grant select. insert, update, delete
	on book_sc.*
	to book_sc@localhost 
	identified by 'password';