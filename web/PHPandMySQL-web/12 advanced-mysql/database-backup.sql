/*
	MySQL数据库备份
	
	1. LOCK TABLES tablename lock_type
	
	2. mysqldump --opt -all-dstabases > all.sql
	
	3. mysqlhotcopy database /path/for/backup
	

*/

/*
	恢复数据库
	
	1.myisamchk -r 	修复破坏的表
	
	2.第一种方法备份：直接将数据文件复制到mysql数据文件中即可
		第二种方法备份：mysqlbinlog hostname-bin.[0-9]* | mysql

*/