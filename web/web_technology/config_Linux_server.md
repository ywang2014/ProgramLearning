#配置LNMP--linux+nginx+mysql+php
1.Xshell登录远程服务器	(使用putty或类似的SSH工具登陆VPS或服务器)

	新建会话(协议：SSH)
	输入主机：ip地址
	输入用户名：root
	输入密码：password
	
上传文件 rz(sz)

Linux安装命令：apt-get install lrzsz
	
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

5.file /sbin/init 或者 file /bin/ls		查看linux机器是32位还是64位的方法

6.cat /etc/issue						查看当前正在运行的 Ubuntu 的版本号

7.screen 命令		

只要Screen本身没有终止，在其内部运行的会话都可以恢复。这一点对于远程登录的用户特别有用——即使网络连接中断，用户也不会失去对已经打开的命令行会话的控制。只要再次登录到主机上执行screen -r就可以恢复会话的运行

	screen -S lnmp 创建screen会话
	如果网络掉线，可以重新连接，再执行 screen -r lnmp 就会看到你的lnmp安装进程
	
安装软件：
	
	1.apt-get install
	
	2.tar xvzf xxx.tar.gz  (install 文件安装 ./configure	make	make install	make clean)
	
	3.rpm -i xxx.rpm 	rpm -ivh *.rpm 
	
	rpm -q -a  查询到当前系统中安装的所有的软件包
	
	rpm -e [package name]	(rpm -e [package name] -nodeps 忽略依赖关系) 卸载

1、以“rpm”为后缀的二进制软件包
    
	安装：rpm -ivh *.rpm
	卸载：rpm -e packagename
	参数-i表示安装，-v是校验，-h是用散列符显示安装进度，-e是删除软件包，packgename代表软件包名，也就是版本号前面那个字符串。
卸载软件前，应首先知道软件包在系统中注册的名称，可以使用命令：rpm -q -a 结合grep来查询。确定了要卸载的软件包名后，就可以开始卸载了，命令如上所示。
由于系统中各个软件包之间相互有依赖关系，如果因存在这种依赖关系而不能卸载，rpm将给予提示并停止卸载，此时，可以使用命令 rpm -e --nodeps packagename 来忽略依赖关系，直接进行卸载。当然，忽略依赖关系的卸载，可能导致系统中其它一些软件无法正常使用，卸载前应三思。

2、以“src.rpm”为后缀的源码软件包
    
	安装：先使用命令 rpm -rebuild *.src.rpm 将源代码编译并在/usr/src/dist/RPMS下生成二进制的rpm包，然后再 rpm -ivh *.rpm 安装该二进制包即可。
    卸载：同上，rpm -e packgename

3、以“tar.gz”、“.bz2”为后缀的二进制软件包
       
	安装：tar zxvf *.tar.gz 、tar jxvf *.bz2
    参数-z调用gzip，-x是解包，-v是校验，-f指定包的文件名，此项通常必选，-j调用bzip。当然，这些参数也不是绝对要加上的，比如-v参数，或者也可以使用其它一些参数，只不过我习惯上这么写。
    卸载：手动删除
	
	指定软件将要安装到的目标路径，即 “./configure --prefix=目录名”，这样可以使用 “rm -rf  软件的目录名”这一命令来进行干净彻底的卸载。