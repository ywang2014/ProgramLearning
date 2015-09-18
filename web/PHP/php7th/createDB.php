<?php
// 建立数据库表guest_book
CREATE TABLE guest_book(
	name varchar(30) null,
	email varchar(30) null,
	title varchar(200) null,
	content text not null,
	date datetime null,
	reply text null,
	replydate datetime null,
	primary key auto_increment,
	postno int(11) not null, 
	default()
);


?>