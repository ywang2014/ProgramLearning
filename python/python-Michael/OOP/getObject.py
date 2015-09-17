# -*- coding utf-8 -*-

# 获取对象信息
	# 使用type()
	
type(123)
type('str')
type(abs)	# 函数
type(a)		# 类

# type() 返回对应的Class类型
type('str') == str	# True

# 判断一个对象是否是函数, 使用types模块中定义的常量
import types
def fn():
	pass
	
type(fn) = types.FunctionType	# True
type(abs) = types.BuiltinFunctionType # True
type(lambda x : x) == types.LambdaType # True
type((x for x in range(10))) == types.GeneratorType # True

	# 使用instance() 
	# isinstance()就可以告诉我们，一个对象是否是某种类型
	
isinstance(a, b)
# isinstance()判断的是一个对象是否是该类型本身，或者位于该类型的父继承链上
# 判断一个变量是否是某些类型中的一种，比如下面的代码就可以判断是否是list或者tuple：
isinstance([1, 2, 3], (list, tuple))
isinstance((1, 2, 3), (list, tuple))

	# 使用dir()
	# 如果要获得一个对象的所有属性和方法，可以使用dir()函数，它返回一个包含字符串的list

dir('ABC')

# 类似__xxx__的属性和方法在Python中都是有特殊用途的
# len('ABC') 等价于 'ABC'.__len__() (在len()函数内部，它自动去调用该对象的__len__()方法)
	# 我们自己写的类，如果也想用len(myObj)的话，就自己写一个__len__()方法：
class Name(object):
	def __len__(self):
		return 3
Tom = Name()
len(Tom)

# lower()返回小写的字符串：
'ABC'.lower()	# 'abc'

# 直接操作一个对象的状态：
getattr(ogj, 'x')	# 获取某对象的某属性
setattr(obj, 'x', 1) # 设置一个属性‘x’, 值为1
hasattr(obj, 'x')	# 判断对象是否有‘x’属性

