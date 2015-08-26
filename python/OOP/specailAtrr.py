# -*- coding: utf-8 -*-

# 定制类

	# __str__  定义好__str__()方法，返回一个好看的字符串
class Student(object):
	def __init__(self, name):
		self.name = name
		
	def __str__(self):
		return 'Student object (name: %s)' % self.name
		
print(Student('Tom'))	# Student object (name: Tom)
s = Student('Tom')
s		# <__main__.Student object at 0x...>
# 直接显示变量调用的不是__str__()，而是__repr__()
# __str__()返回用户看到的字符串，而__repr__()返回程序开发者看到的字符串，也就是说，__repr__()是为调试服务的
# 解决办法是再定义一个__repr__()。但是通常__str__()和__repr__()代码都是一样的，所以，有个偷懒的写法：
class Student(object):
	def __init__(self, name):
		self.name = name
	def __str__(self):
		return 'Student object (name: %s)' % self.name
	__repr__ = __str__
	
	
# __iter__  如果一个类想被用于for ... in循环，类似list或tuple那样，就必须实现一个__iter__()方法，该方法返回一个迭代对象
	# 以斐波那契数列为例，写一个Fib类，可以作用于for循环：
class Fib(object):
	def __init__(self):
		self.a, self.b = 0, 1		# 初始化两个计数器
			
	def __iter__(self):
		return self		# 实例本身就是迭代对象，所以返回自己
			
	def __next__(self):
		self.a, self.b = self.b, self.a + self.b	# 递推公式
		if self.a > 100000:		# 退出循环条件
			raise StopIteration():
		return self.a 
		
for n in Fib():
	print(n)
	
# __getitem__
	# Fib实例虽然能作用于for循环，看起来和list有点像，但是，把它当成list来使用还是不行，比如，取第5个元素：
	# 要表现得像list那样按照下标取出元素，需要实现__getitem__()方法：
class Fib(object):
	def __getitem__(self, n):
		a, b = 1, 1
		for x in range(n):
			a, b = b, a + b
		return a 

f = Fib()
f[3]  # 3

# list有个神奇的切片方法：list(range(100))[5: 10]
# __getitem__()传入的参数可能是一个int，也可能是一个切片对象slice，所以要做判断： 
class Fib(object):
	def __getitem__(self, n):
		if isinstance(n, int):		# n是索引
			a, b = 1, 1
			for x in range(n):
				a, b = b, a + b
			return a
		if isinstance(n, slice):	# n是切片
			start = n.start
			stop = n.stop
			if start is None:
				start = 0
			a, b = 1, 1 
			L = []
			for x in range(stop):
				if x >= start:
					L.append(a)
				a, b = b, a + b
			return L
			
f = Fib()
f[0:5] # [1, 1, 2, 3, 5]

# 但是没有对step参数作处理, 也没有对负数作处理
# 要正确实现一个__getitem__()还是有很多工作要做的

# 如果把对象看成dict，__getitem__()的参数也可能是一个可以作key的object，例如str

# __setitem__()方法，把对象视作list或dict来对集合赋值
# __delitem__()方法，用于删除某个元素

## 通过上面的方法，我们自己定义的类表现得和Python自带的list、tuple、dict没什么区别
	# 这完全归功于动态语言的“鸭子类型”，不需要强制继承某个接口
	
	
# __getattr__
	# 正常情况下，当我们调用类的方法或属性时，如果不存在，就会报错
	# 要避免这个错误，除了可以加上一个score属性外
	# Python还有另一个机制，那就是写一个__getattr__()方法，动态返回一个属性
class Student(object):
	def __init__(self):
		self.name = 'Tom'
		
	def __getattr__(self, attr):
		if attr == 'score':
			return 99

s.score # 调用

# 当调用不存在的属性时，比如score，Python解释器会试图调用__getattr__(self, 'score')来尝试获得属性
	# 返回函数也是完全可以的：
class Student(object):
	def __getattr__(self, attr):
		if attr == 'age':
			return lambda: 25
			
s.age() # 调用

## 只有在没有找到属性的情况下，才调用__getattr__，已有的属性，比如name，不会在__getattr__中查找
	# 注意到任意调用如s.abc都会返回None，这是因为我们定义的__getattr__默认返回就是None
	# 要让class只响应特定的几个属性，我们就要按照约定，抛出AttributeError的错误：
class Student(object):
	def __getattr__(self, attr):
		if attr == 'age':
			return lambda: 25
		raise AttributeError('\'Student\' object has no \'%s\'' % attr)
# 这实际上可以把一个类的所有属性和方法调用全部动态化处理了，不需要任何特殊手段

# 调用API的URL类似： http://api.server/user/friends		http://api.server/user/timeline/list
# 如果要写SDK，给每个URL对应的API都写一个方法，那得累死，而且，API一旦改动，SDK也要改
# 利用完全动态的__getattr__，我们可以写出一个链式调用：
class Chain(object):
	def __init__(self, path = ''):
		self._path = path
		
	def __getattr__(self, path):
		return Chain('%s/%s' % (self._path, path))
	
	def __str__(self):
		return self._path
		
	__repr__ = __str__
	
Chain().status.user.timeline.list
 # 无论API怎么变，SDK都可以根据URL实现完全动态的调用，而且，不随API的增加而改变！
 # 还有些REST API会把参数放到URL中，比如GitHub的API：GET /users/:user/repos
Chain().users('michael').repos		# 链式调用：调用时，需要把:user替换为实际用户名

__call__

一个对象实例可以有自己的属性和方法，当我们调用实例方法时，我们用instance.method()来调用。能不能直接在实例本身上调用呢？在Python中，答案是肯定的。

任何类，只需要定义一个__call__()方法，就可以直接对实例进行调用。请看示例：

class Student(object):
    def __init__(self, name):
        self.name = name

    def __call__(self):
        print('My name is %s.' % self.name)

调用方式如下：

>>> s = Student('Michael')
>>> s() # self参数不要传入
My name is Michael.

__call__()还可以定义参数。对实例进行直接调用就好比对一个函数进行调用一样，所以你完全可以把对象看成函数，把函数看成对象，因为这两者之间本来就没啥根本的区别。

如果你把对象看成函数，那么函数本身其实也可以在运行期动态创建出来，因为类的实例都是运行期创建出来的，这么一来，我们就模糊了对象和函数的界限。

那么，怎么判断一个变量是对象还是函数呢？其实，更多的时候，我们需要判断一个对象是否能被调用，能被调用的对象就是一个Callable对象，比如函数和我们上面定义的带有__call__()的类实例：

>>> callable(Student())
True
>>> callable(max)
True
>>> callable([1, 2, 3])
False
>>> callable(None)
False
>>> callable('str')
False

通过callable()函数，我们就可以判断一个对象是否是“可调用”对象。
小结

Python的class允许定义许多定制方法，可以让我们非常方便地生成特定的类。

本节介绍的是最常用的几个定制方法，还有很多可定制的方法，请参考Python的官方文档。
