# oracle下一条SQL语句的优化过程
很简单的一次调整，语句加了适当的索引后性能就有大幅的提升。
当时看到这条语句的时候，第一感觉就是执行效率肯定低下。语句的功能是求某一客户当天产品的总销量。

#### 原来的语句： 

　　select sum(sl0000) from xstfxps2 where 
　　dhao00 in ( 
　　select dhao00 from xstfxps1 where trunc(ywrq00)=trunc(sysdate) 
　　and khdm00='500000003913'); 
　　
	已用时间: 00: 02: 49.04  
　　Execution Plan 
　　---------------------------------------------------------- 
　　0 SELECT STATEMENT Optimizer=CHOOSE 
　　1 0 SORT (AGGREGATE) 
　　2 1 NESTED LOOPS 
　　3 2 TABLE ACCESS (FULL) OF 'XSTFXPS2' 
　　4 2 TABLE ACCESS (BY INDEX ROWID) OF 'XSTFXPS1' 
　　5 4 INDEX (UNIQUE SCAN) OF 'XSTFXPS1_PK' (UNIQUE) 
　　 
　　Statistics 
　　---------------------------------------------------------- 
　　0 recursive calls 
　　0 db block gets 
　　17355138 consistent gets 
　　34141 physical reads 
　　2912 redo size 
　　198 bytes sent via SQL*Net to client 
　　275 bytes received via SQL*Net from client 
　　2 SQL*Net roundtrips to/from client 
　　0 sorts (memory) 
　　0 sorts (disk) 
　　1 rows processed 
　　
	我们看到统计信息里面进行了17355138次逻辑读，34141次物理IO，这是相当吓人的数字。在执行计划里面我们看到表XSTFXPS2来了一次全表扫描。 
　　
#### 我们首先看一下这两张表总的数据量： 
　　SQL> select count(*) from xstfxps2; 
　　 
　　COUNT(*) 
　　---------- 
　　5585018 
　　我们这里看到XSTFXPS2这张表有5585018条记录。 
　　SQL> select count(*) from xstfxps1; 
　　 
　　COUNT(*) 
　　---------- 
　　702121 
　　两张表的表结构如下所示： 
　　SQL> desc xstfxps1 
　　Name Type Nullable Default Comments 
　　------ ------------ -------- ------- -------- 
　　DHAO00 NUMBER(8) 
　　LHDH00 NUMBER(8) Y 
　　FLDH00 NUMBER(8) Y 
　　FPLB00 VARCHAR2(2) Y 
　　YWRQ00 DATE Y 
　　YWRY00 VARCHAR2(8) Y 
　　SHRQ00 DATE Y 
　　XSQRRQ DATE Y 
　　XSQRRY VARCHAR2(8) Y 
　　KHDM00 VARCHAR2(12) 
　　XKZH00 VARCHAR2(12) 
　　CKDM00 VARCHAR2(2) Y 
　　THCKDM VARCHAR2(2) Y 
　　XSFSDM VARCHAR2(2) Y 
　　FXRYDM VARCHAR2(4) Y 
　　SHRYDM VARCHAR2(4) Y 
　　SHBJ00 VARCHAR2(1) 'N' 
　　FXBJ00 VARCHAR2(1) 'N' 
　　SKBJ00 VARCHAR2(2) Y 
　　FKDM00 VARCHAR2(2) Y 
　　 
　　SQL> desc xstfxps2 
　　Name Type Nullable Default Comments 
　　------ ------------ -------- ------- -------- 
　　DHAO00 NUMBER(8) 
　　SPDM00 VARCHAR2(8) 
　　DJIA00 NUMBER(7,2) 0 
　　FXSL00 NUMBER Y 0 
　　SL0000 NUMBER Y 0 
　　THSL00 NUMBER Y 0 
　　JE0000 NUMBER Y 0 
　　SE0000 NUMBER Y 
　　FPBBH0 VARCHAR2(11) Y 
　　FPHAO0 VARCHAR2(10) Y 
　　RBDH00 NUMBER(8) Y 
　　 
　　其中XSTFXPS1的客户订单的表头，保存订单的客户信息、订货日期等信息。XSTFXPS2是订单的表体，详细记录了客户订单的商品、价格、数量等信息。 
　　 
#### 调整的第一步是把子查询提取出来，再看语句的执行计划。
通常来说，如果语句能够避免子查询的使用，就尽量不用子查询。因为子查询的开销是相当昂贵的。改写后的语句如下： 
　　
	select sum(sl0000) 
　　from xstfxps2 a,(select dhao00 from xstfxps1 where trunc(ywrq00)=trunc(sysdate) 
　　and khdm00='500000003913') b 
　　where a.dhao00=b.dhao00; 
　　
	已用时间: 00: 00: 03.05 
　　Execution Plan 
　　---------------------------------------------------------- 
　　0 SELECT STATEMENT Optimizer=CHOOSE 
　　1 0 SORT (AGGREGATE) 
　　2 1 TABLE ACCESS (BY INDEX ROWID) OF 'XSTFXPS2' 
　　3 2 NESTED LOOPS 
　　4 3 TABLE ACCESS (FULL) OF 'XSTFXPS1' 
　　5 3 INDEX (RANGE SCAN) OF 'XSTFXPS2_PK' (UNIQUE) 
　　Statistics 
　　---------------------------------------------------------- 
　　0 recursive calls 
　　0 db block gets 
　　11974 consistent gets 
　　225 physical reads 
　　832 redo size 
　　211 bytes sent via SQL*Net to client 
　　275 bytes received via SQL*Net from client 
　　2 SQL*Net roundtrips to/from client 
　　0 sorts (memory) 
　　0 sorts (disk) 
　　1 rows processed 
　　 
　　我们可以看到逻辑IO由原来的17355138次下降到11974次，有了数量级的提升。执行时间也有原来将近3分钟下降到现在的3秒多一些。很显然性能有了大幅的提升。不过我们看到执行计划里面表XSTFXPS1还是有一个全表扫描存在。

	通常来说我们应该尽量避免全表扫描的存在，尤其对于大表，应该建立合适的索引以避免FTS的产生。我们来看这两张表的索引信息： 
　　 
　　select index_name,column_name from dba_ind_columns where table_name like 'XSTFXPS%' 
　　INDEX_NAME COLUMN_NAME 
　　------------------------------ ----------------------------------- 
　　XSTFXPS1_PK DHAO00 
　　XSTFXPS2_PK DHAO00 
　　XSTFXPS2_PK SPDM00 
　　 
　　我们看到这两张表除了主键约束外都没有建另外的索引。根据语句的查询情况，我们建立了如下的复合索引： 
　　create index idx_xstfxps1_khdm00_ywrq00 on xstfxps1(khdm00,ywrq00) tablespace indx; 
　　 
　　为了使用索引，我们必须对原来的日期字段的条件进行一些调整。因为有个trunc()函数的存在，语句将不会使用到索引。
	我们只要明白trunc(ywrq00)=trunc(sysdate)事实上等同于ywrq00大于trunc(sysdate)，小于trunc(sysdate+1)减去一秒，我们就有了比较好的办法来处理 这个条件。
	
#### 最终改写后的语句如下： 
　　select sum(sl0000) 
　　from xstfxps2 a, xstfxps1 b 
　　where a.dhao00=b.dhao00 
　　and b.khdm00='500000003913' 
　　and b.ywrq00 between trunc(sysdate) 
　　and trunc(sysdate)+1-1/(24*60*60); 
　　Execution Plan 
　　---------------------------------------------------------- 
　　0 SELECT STATEMENT Optimizer=CHOOSE 
　　1 0 SORT (AGGREGATE) 
　　2 1 TABLE ACCESS (BY INDEX ROWID) OF 'XSTFXPS2' 
　　3 2 NESTED LOOPS 
　　4 3 TABLE ACCESS (BY INDEX ROWID) OF 'XSTFXPS1' 
　　5 4 INDEX (RANGE SCAN) OF 'IDX_XSTFXPS1_KHDM00_YWRQ00' 
　　(NON-UNIQUE) 
　　 
　　6 3 INDEX (RANGE SCAN) OF 'XSTFXPS2_PK' (UNIQUE) 
　　Statistics 
　　---------------------------------------------------------- 
　　0 recursive calls 
　　0 db block gets 
　　3 consistent gets 
　　0 physical reads 
　　0 redo size 
　　210 bytes sent via SQL*Net to client 
　　275 bytes received via SQL*Net from client 
　　2 SQL*Net roundtrips to/from client 
　　0 sorts (memory) 
　　0 sorts (disk) 
　　1 rows processed 
　　
	我们这时候看逻辑IO已经降为3次，语句的执行计划也符合我们的调整目标，创建的索引产生了比较大的效果。这条语句的调整至此告一段落。