## Day1
#### [搭建开发环境](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001432170937506ecfb2f6adf8e4757939732f3e32b781c000)
	安装python (3.4.x)
	
	建议在管理员权限下安装，否则可能有奇怪错误 cmd(管理员)--> pip3所在文件夹(Scripts/)
	
	安装异步框架aiohttp
		
		$pip3 install aiohttp
	
	安装前端模板引擎jinja2
	
		$pip3 install jinja2
		
	安装数据库MySQL 5.x
	
	安装MySQL异步驱动程序aiomysql
	
		$pip3 install aiomysql
		
#### Project Construction

	/				根目录

		backup/		备份目录

		conf/		配置文件

		dist/		打包目录

		www/		Web目录

			static/		静态文件
			
			templates/	模板文件
		
		ios/		IOS App 工程
		
		manual/		项目开发过程说明
		
		sql/		数据库创建文件
		
		LICENSE		代码license
