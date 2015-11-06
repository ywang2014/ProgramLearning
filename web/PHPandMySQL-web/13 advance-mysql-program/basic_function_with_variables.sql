/*
	basic_function_with_variables.sql--声明一个具有变量的存储函数
	basic syntax to create a function with variables
*/

delimiter //

create function add_tax(price float) returns float
begin
	declare tax float default 0.10;
	return price * (1 + tax);
end
//

delimiter ;