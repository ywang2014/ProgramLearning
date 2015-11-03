/*
	创建使用外键的表格
	
*/

create table order_items(
							orderid int unsigned not null references orders(orderid),
							isbn char(13) not null,
							quantity tinyint unsigned,
							primary key (orderid, isbn)
						) type = InnoDB;
						
/* 直接修改表格 */
alter table order_items type = InnoDB;
alter table order_items	add foreign key (orderid) references orders(orderid);