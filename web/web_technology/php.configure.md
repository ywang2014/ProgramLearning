# PHP编译
php编译参数选项

	PHP_INSTALL_PATH=/data/web/php
	MYSQL_INSTALL_PATH=/data/web/mysql

./configure --prefix=${PHP_INSTALL_PATH} --with-config-file-path=${PHP_INSTALL_PATH}/etc --with-mysql=${MYSQL_INSTALL_PATH} --with-mysqli=${MYSQL_INSTALL_PATH}/bin/mysql_config --with-iconv-dir=/usr/local --with-freetype-dir --with-jpeg-dir --with-png-dir --with-zlib --with-libxml-dir=/usr/lib64 --enable-xml --disable-rpath --enable-bcmath --enable-shmop --enable-sysvsem --enable-inline-optimization --with-curl --with-curlwrappers --enable-mbregex --enable-fpm --enable-mbstring --with-mcrypt --with-gd --enable-gd-native-ttf --with-openssl --with-mhash --enable-pcntl --enable-sockets --with-ldap --with-ldap-sasl --with-xmlrpc --enable-zip --enable-soap --without-pear --enable-pdo --with-pdo-mysql --without-pear
 
如果加的参数有不支持的，提示比如：configure: WARNING: unrecognized options: --enable-discard-path, --enable-safe-mode, --enable-fastcgi, --enable-force-cgi-redirect
说明上述这些参数废弃了
 
具体参数含义可以用./configure --help来查看。

列表如下（部分参数未得到解释）：

	--prefix=/usr/local/php 							指定 php 安装目录
	
	--with-config-file-path=/usr/local/php/etc 			指定php.ini位置

	--with-mysql=/usr/local/mysql						mysql安装目录，对mysql的支持
	
	--with-mysqli=/usr/local/mysql/bin/mysql_config   	mysqli
	扩展技术不仅可以调用MySQL的存储过程、处理MySQL事务，而且还可以使访问数据库工作变得更加稳定。	

	--with-apxs2=/usr/local/apache/bin/apxs 
	整合 apache，apxs功能是使用mod_so中的LoadModule指令，加载指定模块到 apache，要求 apache 要打开SO模块
	
**选项指令**

	--with-iconv-dir 		用于 PHP 编译时指定 iconv 在系统里的路径，否则会扫描默认路径。	--with-iconv-dir=/usr/local 
 
	--with-freetype-dir   	打开对freetype字体库的支持 
	--with-jpeg-dir   		打开对jpeg图片的支持 
	--with-png-dir   		打开对png图片的支持 
	--with-zlib-dir   		打开zlib库的支持，用于http压缩传输
	--with-libxml-dir  		打开libxml2库的支持
	--disable-rpath    		关闭额外的运行库文件 
	--enable-bcmath    		打开图片大小调整,用到zabbix监控的时候用到了这个模块
	--enable-shmop --enable-sysvsem  这样就使得你的PHP系统可以处理相关的IPC函数了。
	--enable-inline-optimization  优化线程
	--with-curl    			打开curl浏览工具的支持 
	--with-curlwrappers    	运用curl工具打开url流 
	--enable-mbregex
	--enable-fpm 			打上PHP-fpm 补丁后才有这个参数，CGI方式安装的启动程序
	--enable-mbstring    	多字节，字符串的支持 
	--with-mcrypt           mcrypt算法扩展
	--with-mhash          	mhash算法扩展
	--with-gd    			打开gd库的支持 
	--enable-gd-native-ttf  支持TrueType字符串函数库
	--with-openssl     		openssl的支持，加密传输https时用到的
	--enable-pcntl   		freeTDS需要用到的，可能是链接mssql 才用到
	--enable-sockets     	打开 sockets 支持
	--with-xmlrpc    		打开xml-rpc的c语言 
	--enable-zip   			打开对zip的支持 
	--enable-ftp   			打开ftp的支持 
 
	--with-bz2    			打开对bz2文件的支持        
	--without-iconv   		关闭iconv函数，字符集间的转换 
	--with-ttf     			打开freetype1.*的支持，可以不加了 
	--with-xsl     			打开XSLT 文件支持，扩展了libXML2库 ，需要libxslt软件 
	--with-gettext     		打开gnu 的gettext 支持，编码库用到 
	--with-pear    			打开pear命令的支持，PHP扩展用的 
	--enable-calendar    	打开日历扩展功能
	--enable-exif    		图片的元数据支持 
	--enable-magic-quotes   魔术引用的支持 
 
	--disable-debug    		关闭调试模式 
	--with-mime-magic=/usr/share/file/magic.mime      魔术头文件位置
	
CGI方式安装才用的参数
 
	--enable-fastCGI            		支持fastcgi方式启动PHP
	--enable-force-CGI-redirect       	重定向方式启动PHP
	--with-ncurses         				支持ncurses 屏幕绘制以及基于文本终端的图形互动功能的动态库
	--with-gmp  						应该是支持一种规范
	--enable-dbase                     	建立DBA 作为共享模块
	--with-pcre-dir=/usr/local/bin/pcre-config      perl的正则库案安装位置
	--disable-dmalloc
	--with-gdbm                     dba的gdbm支持
	--enable-sigchild
	--enable-sysvshm
	--enable-zend-multibyte         支持zend的多字节
	--enable-wddx
	--enable-soap