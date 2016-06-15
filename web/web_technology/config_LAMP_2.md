# 配置LAMP服务器
#### 下载源文件
1. wget http://dev.mysql.com/get/Downloads/MySQL-5.7/mysql-5.7.10.tar.gz

2. wget http://php.net/downloads.php/php-5.6.22.tar.gz

3. wget http://httpd.apache.org/download.cgi/httpd-2.4.20.tar.gz 

4. wget http://archive.apache.org/dist/apr/apr-1.5.2.tar.gz
	
5. wget http://archive.apache.org/dist/apr/apr-util-1.5.4.tar.gz
	
6. wget http://jaist.dl.sourceforge.net/project/pcre/pcre/8.37/pcre-8.37.tar.gz

windows 下载，然后使用 X-shell rz命令复制上去

#### 解压缩
tar zxvf *.tar.gz

#### 编译安装
1.安装apache

	./configure --prefix=/usr/local/apr
	make	make install	make clean
	
	./configure --prefix=/usr/local/apr-util -with-apr=/usr/local/apr/bin/apr-1-config
	make	make install	make clean
	
	./configure --prefix=/usr/local/pcre
	make	make install	make clean
	
	./configure --prefix=/usr/local/apache2 --with-apr=/usr/local/apr --with-apr-util=/usr/local/apr-util/ --with-pcre=/usr/local/pcre
	make	make install	make clean

2. 安装mysql
	
	tar mysql-5.6.17-linux-glibc2.5-i686.tar.gz
	cp mysql-5.6.17-linux-glibc2.5-i686 /usr/local/mysql -r
	groupadd mysql				// 添加系统mysql组
	useradd -r -g mysql mysql	// 添加mysql用户到mysql组
	cd /usr/local/mysql
	chown -R mysql:mysql ./		// 修改当前目录拥有者为mysql用户
	./scripts/mysql_install_db --user=mysql		// 安装数据库
	chown -R root:root ./		// 修改当前目录拥有者为root用户
	chown -R mysql:mysql data	// 修改当前data目录拥有者为mysql用户
	cp support-files/mysql.server /etc/init.d/mysql		// 把启动脚本放到开机初始化目录
	service mysql start			// 启动mysql服务
	
	./bin/mysqladmin -u root password '' 	// 修改mysql的root用户密码
	ln -s /usr/local/mysql/bin/mysql /usr/local/bin/mysql	// 把mysql客户端放到默认路径
	