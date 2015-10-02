## Day3

#### 编写ORM
WebApp中，所有的数据(比如：用户信息、发布日志、评论etc)，都存储在数据库中

###### 访问数据库
	1.创建数据库连接
	
	2.游标对象
	
	3.执行SQL语句
	
	4.异常处理
	
	5.清理资源
	
系统维护方便和代码的复用，使用函数封装数据库的常用操作：SELECT INSERT UPDATE DELETE

###### Web框架
基于协程的异步模型 aiohttp
	
	有大量的用户请求，但是用户都是一个线程服务的，所以不能使用普通的同步IO操作
	
	否则等待耗时的IO操作，系统将无法响应任何其他用户
	
异步编程原则：一旦决定使用异步，则系统每一层都必须使用异步

aiomysql 为MySQl数据库提供了异步IO的驱动

###### 创建连接池
创建全局的连接池，使得每一个http请求可以直接通过连接池获取数据库连接

连接池不必频繁地打开和关闭数据库，尽可能复用

连接池由全局变量__pool存储，缺省情况下将编码设置为utf8，自动提交事务：

###### Select语句
使用select()函数，需要传入SQL语句和SQL参数

	SQL语句的占位符是?，而MySQL的占位符是%s，select()函数在内部自动替换
	
	始终坚持使用带参数的SQL，而不是自己拼接SQL字符串，这样可以防止SQL注入攻击
	
	注意到yield from将调用一个子协程（也就是在一个协程中调用另一个协程）并直接获得子协程的返回结果
	
	如果传入size参数，就通过fetchmany()获取最多指定数量的记录，否则，通过fetchall()获取所有记录
	
###### Insert Update Delete语句
使用execute()函数，传入参数SQL，args 返回影响的行数

execute()函数和select()函数所不同的是，cursor对象不返回结果集，而是通过rowcount返回结果数

###### ORM
有了基本的select()和execute()函数，我们就可以开始编写一个简单的ORM了

设计ORM需要从上层调用者角度来设计

	先考虑如何定义一个User对象，然后把数据库表users和它关联起来
	
		定义在User类中的__table__、id和name是类的属性，不是实例的属性
		在类级别上定义的属性用来描述User对象和表的映射关系，而实例属性必须通过__init__()方法去初始化，所以两者互不干扰
		
		'''
		# 创建实例:
		user = User(id=123, name='Michael')
		# 存入数据库:
		user.insert()
		# 查询所有User对象:
		users = User.findAll()
		'''
	
###### 定义Model
	首先要定义的是所有ORM映射的基类Model
	
	Model从dict继承，所以具备所有dict的功能
	
	实现了特殊方法__getattr__()和__setattr__()，因此又可以像引用普通字段那样写：user['id'] == user.id
	
###### Field和各种Field子类
###### 映射varchar的StringField类
###### ModelMetaclass
注意到Model只是一个基类，如何将具体的子类如User的映射信息读取出来呢？答案就是通过metaclass：ModelMetaclass

任何继承自Model的类（比如User），会自动通过ModelMetaclass扫描映射关系，并存储到自身的类属性如__table__、__mappings__中

然后，我们往Model类添加class方法，就可以让所有子类调用class方法：

	User类现在就可以通过类方法实现主键查找
	
		user = yield from User.find('123')
	
往Model类添加实例方法，就可以让所有子类调用实例方法：

	这样，就可以把一个User实例存入数据库：
	
		user = User(id=123, name='Michael')

		yield from user.save()
		
最后一步是完善ORM，对于查找，我们可以实现以下方法：

	findAll() - 根据WHERE条件查找
	
	findNumber() - 根据WHERE条件查找，但返回的是整数，适用于select count(*)类型的SQL
	
	以及update()和remove()方法
	
	所有这些方法都必须用@asyncio.coroutine装饰，变成一个协程
	
	调用时需要特别注意：user.save() 没有任何效果，因为调用save()仅仅是创建了一个协程，并没有执行它。
	
	一定要用：yield from user.save()才真正执行了INSERT操作。

###### 知识点积累

	类定义了类的对象实例有哪些属性和方法
	
	元类定义了元类的类有哪些属性和方法(类是元类的实例对象)
	



	