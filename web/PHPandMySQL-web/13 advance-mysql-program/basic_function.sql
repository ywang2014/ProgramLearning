/*
	basic_function.sql--声明一个存储函数
	basic syntax to create a function

*/

delimiter //

create function add_tax (price, float) returns float
return price * 1.1;
//

delimiter ;

select add_tax(100);	/* 调用内置函数的方式，调用一个存储函数 */

/*
	show 查看定义的过程、函数的源代码
*/
show create procedure total_orders
show create function add_tax;

/*
	删除
*/
drop procedure total_orders;
drop function add_tax;