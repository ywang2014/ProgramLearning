# -*- coding: utf-8 -*-

# 装饰器
# 在代码运行期间动态增加功能的方式，称之为“装饰器”（Decorator）
# 本质上，decorator就是一个返回函数的高阶函数

# 定义一个能打印日志的decorator
def log(func):
	def wrapper(*rags, ** kw):
		print('call %s():' % func.__name__) ### __两个下划线
		return func(*args, **kw)
	return wrapper
	
# 借助Python的@语法，把decorator置于函数的定义处：
@log
def now():
	print('2015-8-22')
	
# 调用now()函数，不仅会运行now()函数本身，还会在运行now()函数前打印一行日志：
now() # call now(): 2015-8-22
# 把@log放到now()函数的定义处，相当于执行了语句：now = log(now)
# 由于log()是一个decorator，返回一个函数，所以，原来的now()函数仍然存在，只是现在同名的now变量指向了新的函
# 数，于是调用now()将执行新函数，即在log()函数中返回的wrapper()函数。
# wrapper()函数的参数定义是(*args, **kw)，因此，wrapper()函数可以接受任意参数的调用。在wrapper()函数内，
# 首先打印日志，再紧接着调用原始函数

# 如果decorator本身需要传入参数，那就需要编写一个返回decorator的高阶函数，写出来会更复杂。比如，要自定义log的文本：
def log(text):
	def decorator(func):
		def wrapper(*args, **kw):
			print('%s %s():' %(text, func.__name__))
			return func(*args, **kw)
		return wrapper
	return decorator
	
# 调用
@log('execute')
def now():
	print('2015-8-22')
	# now = log('execute')(now)
	
# 经过decorator装饰之后的函数，它们的__name__已经从原来的'now'变成了'wrapper'
# 因为返回的那个wrapper()函数名字就是'wrapper'，所以，需要把原始函数的__name__等属性复制到wrapper()函数
# 中，否则，有些依赖函数签名的代码执行就会出错。
# 不需要编写wrapper.__name__ = func.__name__这样的代码，Python内置的functools.wraps就是干这个事的
import functools

def log(func):
	@functools.wraps(func)
	def wrapper(*args, **kw):
		print('call %s():' % func.__name__)
		return func(*args, **kw)
	return wrapper
	
import functools 	# import functools是导入functools模块 
def log(text):
	def decorator(func):
		@functools.wraps(func)
		def wrapper(*args, **kw):
			print('%s %s():' % (text, func.__name__))
			return func(*args, **kw)
		return wrapper
	return decorator
	
# 练习
	# 请编写一个decorator，能在函数调用的前后打印出'begin call'和'end call'的日志
import functools
def logbegin(func):
	@functools.wraps(func)
	def wrapper(*args, **kw):
		print('begin call %s():' % func.__name__)
		return func(*args, **kw)
	return wrapper
	
@logbegin
def now(func):
	@functools.wraps(func)
	def wrapper(*args, **kw):
		print('我是主程序！')
		return func(*args, **kw)
	return wrapper
	
@now
def logend():
	print('end call')
	
logend()
print(logend.__name__)
	
	# 再思考一下能否写出一个@log的decorator，使它既支持：@log又支持：@log('execute')
import functools
def log(text = 'execute'):
	if isinstance(text, str):
		def decorator(func):
			@functools.wraps(func)
			def wrapper(*args, **kw):
				print('%s %s():' % (text, func.__name__))
				return func(*args, **kw)
			return wrapper
		return decorator
	else :
		@functools.wraps(text)
		def wrapper(*args, **kw):
			print('call %s():' % text.__name__)
			return text(*args, **kw)
		return wrapper
		
@log
def now():
	print('2015-8-22')
	
@log('execute')
def now():
	print('2015-8-22')