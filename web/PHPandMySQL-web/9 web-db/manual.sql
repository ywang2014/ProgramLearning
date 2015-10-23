--数据库基本操作

mysql -u servername -p 	--登录数据库

> create database dbname;	-- 创建数据库

> create table tablename{};	-- 创建表

> use dbname;	-- 激活某个数据库为当前使用

> show tables;	-- 显示当前数据库所有的表

> show databases;	-- 显示服务器所有的数据库

> describe tablename;	-- 查看某表的所有列信息

-- 创建索引
> create [unique|fulltext] index index_name on tablename (index_column_name [(length)] [asc|desc], ...)
-- FULLTEXT索引用于索引文本字段
-- length字段表明，只有该字段的前length个字符被索引