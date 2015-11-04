/*
	数据库编码问题-->不乱码
	
*/

/* 告诉客户端，使用的编码为：gbk */
set character_set_client-gbk;

/* 告诉连接器，utf-8 */
set character_set_connection-utf8;

/* 设置返回值，gbk */
set character_set_results=gbk;

/* *********** 方法二 *********************************************/
set character_set_client-gbk;

set character_set_connection-gbk;

set character_set_results=gbk;

/*
	编码：服务器>connection>client
*/
set names GBK;	/* 三个都是GBK的时候，简写 */

