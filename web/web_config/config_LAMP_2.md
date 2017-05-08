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
tar -zxvf *.tar.gz
tar -jxvf *.tar.bz2

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
	
	/usr/local/apache2/bin/apachectl start
	/usr/local/apache2/bin/apachectl stop

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
	
3. 安装PHP

	./configure --prefix=/usr/local/php --with-config-file-path=/usr/local/php/etc --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql=/usr/local/mysql/
	错误：error: xml2-config not found. Please check your libxml2 installation
	安装libxml2:
		1.	apt-get install libxml2
			sudo apt-get install libxml2-dev
			失败
		2. 	tar zxvf libxml2-2.7.0.tar.gz
			./configure  --prefix=/usr/local 
			make 	make install 	make clean
			export  LD_LIBRARY_PATH=/usr/local/lib 	// export 设置环境变量
			export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig 
	
	安装好libxml2后，再次编译，成功
	
		$tar zxvf libxml2-2.6.20.tar.gz
		./configure  --prefix=/usr/local 
		export  LD_LIBRARY_PATH=/usr/local/lib 
		export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig 
	
4. 安装GD库

	1.安装zlib 
	tar zxvf zlib-1.2.3.tar.gz 
	cd zlib-1.2.3 
		./configure --prefix=/usr/local/zlib 	// 这种编译有问题，导致正常系统include中找不到zlib.h 
		// 安装libpng会报错
	./configure
	make 
	make install 
	
	2.安装libpng 
	tar zxvf libpng-1.2.8.tar.tar 
	cd libpng-1.2.8 
	mv ./scripts/makefile.linux ./makefile 
		错误：png.h:359:18: fatal error: zlib.h: No such file or directory
		find / -name zlib.h
		make prefix=/usr/local/lib ZLIBINC=/usr/local/zlib/include ZLIBLIB=/usr/local/lib -f scripts/makefile.linux && make prefix=/usr/local/lib install -f scripts/makefile.linux 
	make 
	make install 
	注意，这里的makefile不是用./configure生成，而是直接从scripts/里拷一个 
	
	3.安装freetype 
	tar zxvf freetype-2.1.10.tar.gz 
	cd freetype-2.1.10 
	./configure --prefix=/usr/local/freetype  有错误
	解决方法：./configure --prefix=/usr/local/freetype --without-png
	make 
	make install 
	
	4.安装Jpeg 
	tar zxvf jpegsrc.v6b.tar.gz 
	cd jpeg-6b/ 
	./configure --enable-shared 
	make 
	make test 
	make install 
	注意，这里configure一定要带--enable-shared参数，不然，不会生成共享库 

	5.安装GD 
	tar zxvf gd-2.0.33.tar.gz 
	cd gd-2.0.33 
	./configure --with-png --with-jpeg --with-freetype=/usr/local/freetype 
	make 
	make install 
	
	重新编译PHP
	./configure --prefix=/usr/local/php --with-config-file-path=/usr/local/php/etc --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql --with-gd --enable-gd-native-ttf --with-zlib-dir=/usr/local/zlib --with-freetype-dir=/usr/local/freetype --disable-fileinfo
	
#### 配置基础文件
1.网站根目录

	/usr/local/apache2/conf/httpd.conf 
		DocumentRoot "/var/www/html"
		<Directory "/var/www/html">
		
		添加
		ServerName localhost:80
		
		找到 AddType application/x-gzip .gz .tgz 在其下添加如下内容
　　	AddType application/x-httpd-php .php      (.前面有空格)
　　	AddType application/x-httpd-php-source .phps        (.前面有空格)
	
		DirectoryIndex index.html，把此行修改成
		“DirectoryIndex index.html index.htm index.php”
		
2.创建数据库

	mysql -u root -p
	source *.sql
	
	错误：Access denied for user 'root'@'localhost' (using password: YES)
	//update user set host='localhost' where user='root' and host='%';
	关闭数据库，重启即可
	update user set host='localhost' where user='root' and host='%';
	将%变成localhost，否则必须每次重新启动，使用“mysqld_safe --skip-grant-tables”方式启动才可以！很复杂
	
	/etc/init.d/mysql start		// 启动数据库
	/etc/init.d/mysql stop		// 暂停数据库
	
	/usr/local/mysql/bin/mysqld_safe --skip-grant-tables		// 启动数据库
	
	insert into user select * from user where User='zedi2016';
	
3.修改PHP配置文件
	
	/usr/local/php/bin/php --ini	// 查看php.ini的路径
	从源码包中拷贝php.ini-development到/etc/php.ini
	找到date.timezone行修改为
	date.timezone = "UTC"
	
#### PHP扩展openssl
1.进去openssL扩展模块：
	cd /root/php-5.6.16/ext/openssl
2.执行phpize:
	/usr/local/php/bin/phpize
	# 如果错误，找不到config.m4，则：
	mv config0.m4 config.m4
	/usr/local/php/bin/phpize
	./configure --with-openssl --with-php-config=/usr/local/php/bin/php-config
	# 错误：configure: error: Cannot find OpenSSL's <evp.h>
	make 
	make install
	方法问题较大，无法解决：

重新编译php：./configure  --with-openssl-dir=/usr/lib/openssl --with-openssl

	./configure --prefix=/usr/local/php --with-config-file-path=/usr/local/php/etc --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql --with-mysqli=mysqlnd --with-pdo-mysql=mysqlnd --enable-mysqlnd --with-gd --enable-gd-native-ttf --with-zlib-dir=/usr/local/zlib --with-freetype-dir=/usr/local/freetype --disable-fileinfo --with-openssl-dir=/usr/bin/openssl --with-openssl 
	# 错误：configure: error: Cannot find OpenSSL's <evp.h>
	
**evp.h缺失问题**
此问题必须解决，网络上方法很多：
	yum install openssl openssl-dev 
	添加：--with-mysqli=mysqlnd --with-pdo-mysql=mysqlnd --enable-mysqlnd 
	。。。
	方法：
		sudo apt-get install libssl-dev(其他方法无效)
		ln -s /usr/lib/x86_64-linux-gnu/libssl.so  /usr/lib
	make 
	make install
	make clean
	
	/usr/local/apache2/bin/apachectl restart
	
#### autoconf问题：	

	1.Cannot find autoconf. Please check your autoconf installation and the $PHP_AUTOCONF environment variable. Then, rerun this script.
	解决方法：sudo apt-get install autoconf




	