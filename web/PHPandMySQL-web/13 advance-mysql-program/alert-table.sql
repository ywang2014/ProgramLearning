/*
	存储引擎
	--表格类型
*/
create table tablename type = typename ...

/*
表格类型：
	MyISAM	(indexed sequential access method) 默认类型：select/insert 速度快，支持全文搜索
	MEMORY	(heap) 临时表格 视图等
	MERGE	大量处理表格的时候，合并
	ARCHIVE 
	CSV		
	InnoDB	事物安全的，重要数据
	
*/
alter table orders type = innodb;
alter table order_items type = innodb;