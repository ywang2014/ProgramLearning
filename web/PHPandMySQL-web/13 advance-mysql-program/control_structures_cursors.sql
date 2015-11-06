/*
	control_structures_cursors.sql--使用游标和循环来处理一个结果集
	procedure to find the orderid with the largest amount
	could be done with max, but just to illustrate stored procedure principles
	
*/

delimiter //

create procedure largest_order(out largest_id int)
begin
	declare this_id int;
	declare this_amount float;
	declare max_amount float default 0.0;
	declare max_amount_id int;
	
	declare done int default 0;
	declare continue handler for sqlstate '02000' set done = 1;
	declare c1 cursor for select orderid, amount from orders;
	
	open c1;
	repeat
		fetch c1 into this_id, this_amount;
		if not done then
			if this_amount > max_amount then
				set max_amount = this_amount;
				set max_amount_id = this_id;
			end if;
			end if;
		until done end repeat;
	close c1;
	
	set largest_id = max_amount_id;
	
end
//

delimiter ;
			