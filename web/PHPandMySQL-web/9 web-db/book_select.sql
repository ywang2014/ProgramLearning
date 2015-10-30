/*
* book_select.sql
*
* 多张表实现查询
*	关联多个表
*	弄清关联条件
*
*/

/* 
	功能：查找订购了java书籍的顾客的姓名 
	
		需要显示的内容 select后面
		需要关联的表 from后面
		where 后面关联条件
*/
select customers.name
from customers, orders, order_items, books
where customers.customerid = orders.customerid
	and orders.orderid = order_items.orderid
	and order_items.isbn = bokks.isbn
	and books.title like '%Java%';
	
/*
	左关联
	from tableone left join tabletwo
*/

select customers.customerid, customers.name, orders.orderid
from customers left join orders
on customers.customerid = orders.customerid;

/*
*	查看没有订购任何商品的顾客
*	检查右边表的主键字段是否为NULL
*/
select customers.customerid, customers.name
from customers left join orders
using (customerid)
where orders.orderid is null;

/*
*	别名：Aliase
*
*	重命名方便使用
*   ** 关联一个表到表本身的时候，必须使用别名**
*
*	查找住在同一个城市的顾客
*/
select c1.name, c2.name, c1.city
from customers as c1, customers as c2
where c1.city = c2.city
	and c1.name != c2.name;

