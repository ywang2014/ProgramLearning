/*
	设置多个从服务器
	如果获得数据库快照，可在从服务器上安装它
	在从服务器上运行如下查询：
	
*/

change master to
master-host = 'servername',	/* 主服务器名称 */
master-user = 'username',	/* 在主服务器上设置的用户：grant */
master-password = 'password',
master-log-file = 'logfile',	/* show master status 得到 */
master-log-pos = 'logpos',
start slave;

load data from master;	/* 载入数据 */