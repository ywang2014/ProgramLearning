# -*- coding: utf-8 -*-

# type()
	# 动态语言和静态语言最大的不同，就是函数和类的定义，不是编译时定义的，而是运行时动态创建的
# 写一个hello.py模块：
class Hello(object):
	def hello(self, name = 'world'):
		print('Hello, %s.' % name)
		
from hello import Hello		# Python解释器载入hello模块
h = Hello()
h.hello()	# Hello world
print(type(Hello))	# <class 'type'>
print(type(h))		# <class 'hello.Hello'>

# type()函数可以查看一个类型或变量的类型

# type()函数既可以返回一个对象的类型，又可以创建出新的类型
	# 我们可以通过type()函数创建出Hello类，而无需通过class Hello(object)...的定义：
def fn(self, name = 'world'):	# 先定义函数
	print('Hello, %s.' % name)
	
Hello type('Hello', (object,), dict(hello = fn))	# 创建Hello class
# 创建class对象时，type()函数依次传入3个参数：
	# 1.class的名称
	# 2.继承的父类集合，注意python支持多重继承！只有一个父类，使用tuple单元素写法：必须加个逗号，即使只有一个值：(object, )
	# 3.class的方法名称与函数绑定，这里我们把函数fn绑定到方法名hello上

# 通过type()函数创建的类和直接写class是完全一样的
	# Python解释器遇到class定义时，仅仅是扫描一下class定义的语法，然后调用type()函数创建出class

	# 正常情况下，我们都用class Xxx...来定义类，但是，type()函数也允许我们动态创建出类来
	# 动态语言本身支持运行期动态创建类
	# 静态语言运行期创建类，必须构造源代码字符串再调用编译器，或者借助一些工具生成字节码实现，本质上都是动态编译
	
	
# metaclass(元类)		要控制类的创建行为
	# 先定义类，然后创建实例，如何创建类？？？？
	# 必须根据metaclass创建出类，所以：先定义metaclass，然后创建类
	## 类可以看成是metaclass创建出来的“实例”

# metaclass可以给我们自定义的MyList增加一个add方法：
# 定义ListMetaclass，按照默认习惯，metaclass的"类名"总是以Metaclass结尾，以便清楚地表示这是一个metaclass：
# metaclass是类的模板，所以必须从'type'类型派生
class ListMetaclass(type):
	def __new__(cls, name, bases, attrs):
		attrs['add'] = lambda self, value: self.append(value)
		return type.__new__(cls, name, bases, attrs)

# 有了ListMetaclass，我们在定义类的时候还要指示使用ListMetaclass来定制类，传入关键字参数metaclass：
class MyList(list, metaclass = ListMetaclass):
	pass
	
# 当我们传入关键字参数metaclass时，魔术就生效了
# 它指示Python解释器在创建MyList时，要通过ListMetaclass.__new__()来创建
# 在此，我们可以修改类的定义，比如，加上新的方法，然后，返回修改后的定义。
# __new__()方法接收到的参数依次是：
	# 1.当前准备创建的类的对象；
	# 2.类的名字；
	# 3.类继承的父类集合；
	# 4.类的方法集合。
# test
L1 = MyList()
L.add(1)
L 	# [1]
L2 = list()
L2.add(1)	# AttributeError

# 直接在MyList定义中写上add()方法不是更简单
# 正常情况下，确实应该直接写，通过metaclass修改纯属变态。
# 总会遇到需要通过metaclass修改类定义的。ORM(Object Relational Mapping)就是一个典型的例子
# ORM ：对象-关系映射，就是把关系数据库的一行映射为一个对象，也就是一个类对应一个表
# 写代码更简单，不用直接操作SQL语句
# 要编写一个ORM框架，所有的类都只能动态定义，因为只有使用者才能根据表的结构定义出对应的类来
# 编写一个ORM框架
	# 编写底层模块的第一步，就是先把调用接口写出来
	# 比如，使用者如果使用这个ORM框架，想定义一个User类来操作对应的数据库表User
class User(Model):
	# 定义类的属性到列的映射
	id = IntegerField('id')
	name = StringField('username')
	email = StringField('email')
	password = StringField('password')
	
# 创建一个实例
u = User(id = 123, name = 'root', email = 'test@orm.org', password = 'root')
# 保存到数据库
u.save()
# 父类Model和属性类型StringField、IntegerField是由ORM框架提供的，剩下的魔术方法比如save()全部由metaclass自动完成
# metaclass的编写会比较复杂，但ORM的使用者用起来却异常简单
# 按上面的接口来实现该ORM
class Field(object):
	def __init__(self, name, column_type):
		self.name = name
		self.column_type = column_type
		
	def __str__(self):
		return '<%s: %s>' % (self.__class__.__name__, self.name)
		
# 在Field的基础上，进一步定义各种类型的Field, 比如StringField，IntegerField等等：
class StringField(Field):
	def __init__(self, name):
		super(StringField, self).__init__(name, 'varchar(100)')
		
class IntegerField(Field):
	def __init__(self, name):
		supper(IntegerField, self).__init__(name, 'bigint')
		
# 编写最复杂的ModelMetaclass了：
class ModelMetaclass(type):
	def __new__(cls, name, bases, attrs):
		if name == 'Model':
			return type.__new__(cls, name, bases,attrs)
		print('Found model: %s' % name)
		mappings = dict()
		for k, v in attrs.items():
			if isinstance(v, Field):
				print('Found mapping: %s ==> %s' % (k, v))
				mappings[k] = v 
		for k in mappings.keys():
			attrs.pop(k)
		attrs['__mappings__'] = mappings	# 保存属性和列的映射关系
		attrs['__table__'] = name			# 假设表名和类名一致
		return type.__new__(cls, name, bases, attrs)
		
# 以及基类Model：
class Model(dict, metaclass = ModelMetaclass):
	def __init__(self, **kw):
		supper(Model, self).__init__(**kw)
	
	def __getattr__(self, key):
		try:
			return self[key]
		except KeyError:
			raise AttributeError(r"'Model' object has no attribute '%s'" % key)
			
	def __setattr__(self, key, value):
		self[key] = valuee
		
	def save(self):
		fields = []
		params = []
		args = []
		for k, v in seif.__mappings__.items():
			fields.append(v.name)
			params.append('?')
			args.append(getattr(self, k, None))
		sql = 'insert into %s (%s) value (%s)' % (self.__table, ','.join(fields), ','.join(params))
		print('SQL: %s' % sql)
		print('ARGS: %s' % str(args))
		
	# 当用户定义一个class User(Model)时，Python解释器首先在当前类User的定义中查找metaclass
	# 如果没有找到，就继续在父类Model中查找metaclass
	# 找到了，就使用Model中定义的metaclass的ModelMetaclass来创建User类，
	# metaclass可以隐式地继承到子类，但子类自己却感觉不到
		
	# 在ModelMetaclass中，一共做了几件事情：
		# 1.排除掉对Model类的修改；
		# 2.在当前类（比如User）中查找定义的类的所有属性，如果找到一个Field属性，就把它保存到一个__mappings__的
		#   dict中，同时从类属性中删除该Field属性，否则，容易造成运行时错误（实例的属性会遮盖类的同名属性）；
		# 3.把表名保存到__table__中，这里简化为表名默认为类名。
	# 在Model类中，就可以定义各种操作数据库的方法，比如save()，delete()，find()，update等等
	# 我们实现了save()方法，把一个实例保存到数据库中。因为有表名，属性到字段的映射和属性值的集合，就可以构造出INSERT语句
# test
class User(Model):
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')
	
u = User(id = 123, name = 'root', email = '163@163.com', password = 'root')
u.save()
	# save()方法可以打印出可执行的SQL语句，以及参数列表
	# 只需要真正连接到数据库，执行该SQL语句，就可以完成真正的功能。
	# 不到100行代码，我们就通过metaclass实现了一个精简的ORM框架
		
## metaclass是Python中非常具有魔术性的对象，它可以改变类创建时的行为，功能强大

