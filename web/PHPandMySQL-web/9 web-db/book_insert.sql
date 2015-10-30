/*
*	book_insert.sql 多行插入
*	insert 语句
*/

use books

insert into customer values
	(3, 'Julie Smith', '25 Oak Street', 'Airport West'),
	(4, 'Alan', '1/47 Hains Avenue', 'Box Hill'),
	(5, 'Michelle Arthur', '357 North Road', 'Yarraville');
	
insert into orders values
	(NULL, 3, 69.98, '2015-10-30'),
	(NULL, 1, 21.22, '2015-10-31'),
	(NULL, 5, 45.22, '2015-11-02'),
	(NULL, 2, 33.22, '2015-11-11');
	
insert into books values
	('0-672-31697-8', 'Michael Morgan', 'Java 2 for professional developers', 50.99),
	('0-672-31745-1', 'Thomas Dwon', 'Installing debian GNU/Linux', 21.99),
	('0-672-31769-9', 'Thomas Schenk', 'Caldera OpenLinux System Administration Unleashed', 50.99);
	
insert into order_items values
	(1, '0-672-31697-8', 2),
	(2, '0-672-31769-9', 2),
	(3, '0-672-31769-9', 1),
	(4, '0-672-31509-2', 2),
	(5, '0-672-31745-1', 3);
	
insert into book_reviews values
	('0-672-31697-8' 'The Morgan book is clearly written and goes well beyond most of the basic Java books out there.');
	