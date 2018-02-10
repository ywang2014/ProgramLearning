## Day7
#### [编写MVC](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001432339095180ce91c53cdab841bfa9c342a297b886fe000)
ORM框架、Web框架、配置文件已经就绪，可以开始编写简单的MVC，启动起来了

####### 处理首页URL函数
通过Web框架的@get和ORM框架的Model支持实现

	@get('/')
	def index(request):
		users = yield from User.findAll()
		return {
			'__template__': 'test.html',
			'users': users
		}
		
	'__template__'指定的模板文件是test.html，其他参数是传递给模板的数据，
	在模板的根目录templates下创建test.html：
	<!DOCTYPE html>
	<html>
	<head>
		<meta charset = 'utf-8'>
		<title> Test users - Awesome Python Webapp </title>
	</head>
	<body>
		<h1> All users </h1>
		{% for u in users %}
		<p> {{ u.name }} / {{ u.email }} </p>
		{% endfor %}
	</body>
	</html>
	
接下来，如果一切顺利，可以用命令行启动Web服务器：$ python3 app.py

然后，在浏览器中访问http://localhost:9000/

如果数据库的users表什么内容也没有，你就无法在浏览器中看到循环输出的内容。可以自己在MySQL的命令行里给users表添加几条记录，然后再访问：


	