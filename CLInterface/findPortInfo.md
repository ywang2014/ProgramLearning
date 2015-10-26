# cmd命令行
#### 解决端口号被占用

tasklist 	查看所有进程信息

taskkill /im PID /f		强行杀死进程号为PID的进程

在任务管理器，进程中也可以看见 

	如果pid不可见，点击查看->选择列，勾选PID即可
	
	左下角勾选显示所有的用户进程
	
netstat -a -n  		显示各个端口占用
	
netstat -ano		显示所有端口号使用信息和占用进程的进程号

netstat -aon|findstr "port"

tasklist|findstr "PID"		查看进程程序名等信息