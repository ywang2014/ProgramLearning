/*
	basic_stored_procedure.sql--声明一个存储过程
	basic stored procedure example
	basic syntax to create a procedure
*/
delimiter //	/* 将语句末尾的分隔符从当前值改为双斜杠字符(分隔符一般就是分号 ';') */
/*
	可以在存储过程中使用分号分隔符了，mysql就会将分号当做是存储过程代码，而不会直接执行这些代码
*/


create procedure total_orders (out total float)	/* 创建实际的存储过程 */
/*
	存储过程名称：total_orders
	参数：total
		out表示该参数需要被传出或返回
		in 表示参数必须传入到存储过程
		inout表示该值必须传入但是可以被存储过程修改
		float表示参数类型，orders列的类型为float，所以为float
		
		多个参数：','逗号间隔的参数列表
	
	过程必须封闭在BEGIN/END语句中，类似php的'{','}'。标识语句块
	
*/
BEGIN
	select sum(amount) into total from orders; /* into total 将查询结果载入到total参数 */
END
//

delimiter ;	/* 将分隔符重新设置为分号 */

call total_orders(@res);	/* call调用该过程，传入@res用来保存结果 */

select @res;	/* 查看结果 */