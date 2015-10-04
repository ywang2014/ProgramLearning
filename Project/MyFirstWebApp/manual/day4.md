## Day4
#### 编写Model
在编写ORM时，给一个Field增加一个default参数可以让ORM自己填入缺省值，非常方便

缺省值可以作为函数对象传入，在调用save()时自动计算

	主键id的缺省值是函数next_id，创建时间created_at的缺省值是函数time.time，可以自动设置当前日期和时间
	
日期和时间用float类型存储在数据库中，而不是datetime类型，这么做的好处是不必关心数据库的时区以及时区转换问题

	排序非常简单，显示的时候，只需要做一个float到str的转换，也非常容易。
	
###### 初始化数据库表
如果表的数量很少，可以手写创建表的SQL脚本：

如果表的数量很多，可以从Model对象直接通过脚本自动生成SQL脚本，使用更简单。

把SQL脚本放到MySQL命令行里执行：

	mysql -u root -p
	
	schema.sql
	
###### 编写数据访问代码
接下来，就可以真正开始编写代码操作对象了

	对于User对象，我们就可以做如下操作：

	import orm
	from models import User, Blog, Comment

	def test():
		yield from orm.create_pool(user='www-data', password='www-data', database='awesome')
	
		u = User(name='Test', email='test@example.com', passwd='1234567890', image='about:blank')

		yield from u.save()

	for x in test():
		pass

可以在MySQL客户端命令行查询，看看数据是不是正常存储到MySQL里面了

###### 传说正确的测试代码
	import orm,asyncio
	from models import User,Blog,Comment

	def test(loop):
		yield from orm.create_pool(loop=loop,user='www-data',password='www-data',db='awesome')
		u=User(name='test3',email='test4@test.com',passwd='test',image='about:blank')
		yield from u.save()

	loop = asyncio.get_event_loop()
	loop.run_until_complete(test(loop))
	loop.close()

