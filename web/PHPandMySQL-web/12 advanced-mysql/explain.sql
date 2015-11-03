/* *****************************************************************
* explain 语句：
*	explain tablename  显示表中的所有列
*	
*	explain select ...	查看mysql如何解释执行SELECT查询的
*/

explain
select customers.name
from customers, orders, order_items, books
where customers.customerid = orders.customerid
	and orders.orderid = order_items.orderid
	and order_items.isbn = books.isbn
	and books.title like '%Java%';
	
