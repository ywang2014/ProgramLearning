# 安装lnmp--linux+nginx+mysql+php
1.Xshell登录远程服务器	(使用putty或类似的SSH工具登陆VPS或服务器)

	新建会话(协议：SSH)
	输入主机：ip地址
	输入用户名：root
	输入密码：password
	
2.下载lnmp

	wget -c http://soft.vpser.net/lnmp/lnmp1.0.tar.gz	(wget url 下载文件)
	tar zxvf lnmp1.0.tar.gz		(解压)
	cd lnmp1.0		进入文件夹
	安装	Centos执行：./centos.sh  ,Debian 执行：./debian.sh  进行安装,Ubuntu 执行：./ubuntu.sh 进行安装
	
(安装LNMP执行：wget -c http://soft.vpser.net/lnmp/lnmp1.2-full.tar.gz && tar zxf lnmp1.2-full.tar.gz && cd lnmp1.2-full && ./install.sh lnmp
如需要安装LNMPA或LAMP，将./install.sh 后面的参数替换为lnmpa或lamp即可)
	
#### 帮助分析
1.more /proc/cpuinfo					查看服务器cpu等基本信息

2.cat /proc/meminfo |grep MemTotal		查看内存大小

3.fdisk -l |grep Disk					查看硬盘大小

4.cat /proc/version						查看系统版本信息

5.screen 命令		

只要Screen本身没有终止，在其内部运行的会话都可以恢复。这一点对于远程登录的用户特别有用——即使网络连接中断，用户也不会失去对已经打开的命令行会话的控制。只要再次登录到主机上执行screen -r就可以恢复会话的运行

	screen -S lnmp 创建screen会话
	如果网络掉线，可以重新连接，再执行 screen -r lnmp 就会看到你的lnmp安装进程