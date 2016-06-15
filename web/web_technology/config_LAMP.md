#配置LAMP总结

1.tar zxvf *.tar.gz 	//解压缩	unzip *.zip

1.cd /usr/local/mysql 	//进入到安装的mysql软件目录中

chown -R root . //设定root能访问/usr/local/mysql 

chown -R mysql var //设定mysql用户能访问/usr/local/mysql/var ,里面存的是mysql的数据库文件.这个目录是在/etc/my.cnf中有配置，在mysql_install_db时产生。 

chown -R mysql var/ . //设定mysql用户能访问/usr/local/mysql/var/mysql下的所有文件 

chgrp -R mysql . //设定mysql组能够访问/usr/local/mysql 

**上面的已经把mysql完全安装完了**，也能正常使用了，但还不够，你要将mysql的数据库启动脚本加入系统启动目录 
cd /usr/local/mysql/lib/mysql/ 

ln -s libmysqlclient.so.15.0.0 libmysqlclient_r.so 

cp /tmp/mysql-5.0.16/support-files/my-huge.cnf /etc/my.cnf 

cp /tmp/mysql-5.0.16/support-files/mysql.server /etc/rc.d/init.d/mysqld 

chmod 700 /etc/rc.d/init.d/mysqld 

ln -s /etc/rc.d/init.d/mysqld /etc/rc.d/rc3.d/mysqld 

/etc/rc.d/init.d/mysqld start //来启动mysql进程 

#### 安装apache

编译	./configure --prefix=/usr/local/apache2	(指定目录)

	1.APR 问题 
	wget http://archive.apache.org/dist/apr/apr-1.5.2.tar.gz
	wget http://archive.apache.org/dist/apr/apr-util-1.5.4.tar.gz
	wget http://jaist.dl.sourceforge.net/project/pcre/pcre/8.37/pcre-8.37.tar.gz
	
	./configure --prefix=/usr/local/apr
	make	make install	make clean
	
	./configure --prefix=/usr/local/apr-util -with-apr=/usr/local/apr/bin/apr-1-config
	...
	
	./configure --prefix=/usr/local/pcre
	...
	
	./configure --prefix=/usr/local/apache2 --with-apr=/usr/local/apr --with-apr-util=/usr/local/apr-util/ --with-pcre=/usr/local/pcre
	...
	
	启动Apache：/usr/local/apache2/bin/apachectl start
	停止Apache：/usr/local/apache2/bin/apachectl stop
	重启Apache：/usr/local/apache2/bin/apachectl restart
	
	网站根目录 /usr/local/apache2/htdocs
	
	修改网站目录	--- 必须同时修改，否则用户没有访问权限
	DocumentRoot "/var/www/html"
	<Directory "/var/www/html">
	
**修改配置文件：httpd.conf**
	
	找到 AddType application/x-gzip .gz .tgz 在其下添加如下内容

　　AddType application/x-httpd-php .php      (.前面有空格)

　　AddType application/x-httpd-php-source .phps        (.前面有空格)

	LoadModule php5_module modules/libphp5.so	(配置php时，自动添加的)
	
	
#### 安装MySQL

	tar -zxvf mysql-5.7.10-linux-glibc2.5-x86_64.tar.gz -C /usr/local/src/ 
	
#### 安装PHP
	
	./configure --prefix=/usr/local/php --with-config-file-path=/usr/local/php/etc --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql=/usr/local/mysql/
	奇怪的错误，很多库文件找不到，使用下面的配置在编译一次，就好了。
	
	./configure --prefix=/usr/local/php --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql	(正确了)
	
	cp php.ini.development /usr/local/php/lib/php.ini 	// 或者安装的时候，指定目录 --with-config-file-path=/usr/local/php/etc
	
	安装GD
	wget http://www.boutell.com/gd/http/gd-2.0.33.tar.gz
	wget http://download.chinaunix.net/download.php?id=28882&ResourceID=5095
	wget http://nchc.dl.sourceforge.net/sourceforge/libpng/libpng-1.2.8-config.tar.gz
	wget http://zlib.net/zlib-1.2.8.tar.gz
	wget http://ftp.yzu.edu.tw/nongnu/freetype/freetype-2.6.2.tar.gz
	
#### 安装GD库
	
	1.安装zlib 
	tar zxvf zlib-1.2.3.tar.gz 
	cd zlib-1.2.3 
	./configure --prefix=/usr/local/zlib 
	make 
	make install 
	
	2.安装libpng 
	tar zxvf libpng-1.2.8.tar.tar 
	cd libpng-1.2.8 
	mv ./scripts/makefile.linux ./makefile 
	make 
	make install 
	注意，这里的makefile不是用./configure生成，而是直接从scripts/里拷一个 
	
	3.安装freetype 
	tar zxvf freetype-2.1.10.tar.gz 
	cd freetype-2.1.10 
	./configure --prefix=/usr/local/freetype  有错误
	解决方法：./configure –prefix=/usr/local/freetype –without-png
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
	
	
###### 不重新编译php
	
	cd /root/tmp/php-5.6.16/ext/gd
	/usr/local/php/bin/phpize
	./configure --with-zlib-dir=/usr/local/zlib --with-php-config=/usr/local/php/bin/php-config
		--with-gd=/usr/local/gd --with-jpeg-dir=/usr/local/jpeg --with-png-dir=/usr/local/libpng --with-freetype-dir=/usr/local/freetype
	遇到了错误！configure: error: Problem with libpng.(a|so) or libz.(a|so). Please check config.log for more information. 
	make && make install
	
###### 重新编译PHP

	cd /root/tmp/php-5.6.16
	./configure --prefix=/usr/local/php --with-apxs2=/usr/local/apache2/bin/apxs --with-mysql
		--with-gd --enable-gd-native-ttf --with-zlib-dir=/usr/local/zlib --with-freetype-dir=/usr/local/freetype 
	
	这两个参数已经被舍弃 --with-png --with-jpeg yum自带的有！
	遇到问题：
		virtual memory exhausted: Cannot allocate memory
		make: *** [ext/fileinfo/libmagic/apprentice.lo] Error 1
		
		解决方法：在php安装配置文件中添加了引号中的配置（不包括引号）“--disable-fileinfo”后，终于编译通过。

[官方解释](https://bugs.php.net/bug.php?id=48809)
	
	Adding --disable-fileinfo to ./configure solves the problem.
	
	方法二：
		发生该问题的原因是服务器的内存不够，从而导致编译失败。
		而购买的Linux服务器，未给你分配虚拟内存，所以可以通过自行增加虚拟内存的方法予以解决：
		
		dd if = / dev / zero of = / swap bs = 1024 count = 1M
		mkswap / swap
		swapon / swap
		echo "/swap  swap  swap  sw  0  0"  >> / etc / fstab
	不懂！

	
**修改配置文件：php.ini**

	data.timezone = UTC		// 否则报错
	

#### 复制文件夹

	cp -rf httpd-2.4.17 /usr/local/src
	
	cp -rf /home/wwwroot/* /home/wwwroot/abc
	
	
	sudo apt-get remove –purge $(dpkg -l apache* | grep ii | awk ‘{print $2}’) && sudo apt-get install apache2
	
	sudo apt-get remove –purge $(dpkg -l apache* | grep ii | awk ‘{print $2}’) && sudo apt-get install apache2
	
#### make错误时  Error 127
	
	sudo autoreconf -ivf
	
#### 查找文件

	find / -name dirname
	
#### 服务器端口占用问题

	netstat -nat |grep “:80”	确认一下80端口是否被占用
	
	netstat -an|grep 80 		查看那些进程占用80端口
	
	netstat -tulnp |grep ':80'	查看到对应哪个应用占用了80端口
	
	kill 9 pid					杀掉进程
	
#### 命令行访问URL

	1.elinks --dump http://www.test.com	
	
	2.wget http://							直接下载首页
	
	3.curl http://							显示源代码
	
	4.lynx http://							
	
#### 文件权限问题

	chmod -R 777 ./dirname
	
#### Linux命令

	mv name name1	重命名
	
	cp ./name /var/www	复制到新文件夹下
	
	rm -rf /var/www	删除文件夹
	
	rm -f /var/www/index.html	删除文件
	
#### 总结
1.配置服务器，看似很复杂，很麻烦，我耽误了三个下午，和晚上吧，各种方法，尝试了很多，错误也是千奇百怪，网上的方法，可能和机器、操作系统等环境有关系

2.很多错误，可能是一些非常奇怪的错误，我一般是一种方法遇到的错误太多，或者感觉很难解决就放弃了，直接使用第二种方法。

	比如：apache支持PHP，网上方法很多，乱七八糟的，试了n久，没有解决，后来直接重新编译PHP，加上那些配置参数，第一次可能太多了，错误，很麻烦的错误
	直接放弃修改了，又编译了一次，使用简单的参数，没有想到成功了，然后服务器访问有些变化了，有变化就是好的。然后我去解决新问题，n久没有解决
	直接再次重启apache，没有想到就好了。php可以解析了，最开始php直接显示源代码，后来php文件，直接被下载到了本地，神奇的错误，也没有解决。
	现在终于可以解析php了，正常工作了。然后简单的几个配置问题，容易解决，就不多说，网上方法很多。
	
3.千万不要问题一路解决到底，可能一个个的解决，网上也有人有相同的问题，资源多是英文的，看不懂，不要太执着，还是换种方式配置吧。

4.服务器实在是太复杂了，问题不要畏惧，慢慢来，有耐心，总会解决的。

**最终的方法**

只有mysql是配置LNMP的时候，装好的，所以没有源代码单独的编译配置，apache、php都是单独编译配置的