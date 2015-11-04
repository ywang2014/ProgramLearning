use test;
create table classes(
					id int primary key auto_increment,
					sname varchar(10) not null default '',
					gender char(1) not null default '',
					company varchar(20) not null default '',
					salary decimal(6,2) not null default 0.00,
					fanbu smallint not null default 0
					)engine myisam charset utf8;
					
/* 单行插入 */
insert into classes
(id, sname, gender, company, salary, fanbu)
values(1, '张三', '男', '百度', 8888.67, 234);

insert into classes
(id, sname, gender, company, salary, fanbu)
values(NULL, '李四', '男', '阿里', 8888.67, 234);



/* 多行插入 */
insert into classes
(sname, company, salary)
values
('刘备', '皇室成员', 15.20),
('刘表', '皇室成员', 115.20),
('刘协', '皇室成员', 1115.20);

/* 查询 */
select * from classes;

/* 修改列字段长度 **/
alter table classes modify column gender char(4);


/* 
	修改数据 
	UPDATE tablename SET
	column1 = ,
	column2 = ,
	column3 = ,
	WHERE expression;
*/
update classes set 
gender = '男',
company = '新浪'
where id = 1;

update classes set 
gender = '男',
company = '新浪'
where sname = '李四';

update classes set 
fanbu = fanbu + 200
where salary < 3000 and id != 3;

/* 全部修改 where 恒为真 */
update classes set 
gender = '女'
where 1;

update classes set 
gender = '男'
where id = 2 or id = 4 or id = 6;							/* id % 2 == 0; */

update classes set 
salary = salary + 200
where gender = '男';

/* 删除数据：整行 */
delete from classes
where id = 1;

delete from classes
where sname = 'abc';

delete from tablename;	/* 表中行全部删除了 */

insert into classes 
values(NULL, '小燕子', '女', '百度', 3500, 100);
/* 自增是，当前最大的id基础上，继续加 1 */



/* 充值修改 */
update user_account set
account = account + 100
where userid = id;
