# -*- coding: utf-8 -*-

# 使用__slots__
# 正常情况下，当我们定义了一个class，创建了一个class的实例后，我们可以给该实例绑定任何属性和方法，这就是动态语言的灵活性。先定义class：
class Computer(object):
	pass
	
IBM = Computer()
IBM.name = 'x30386'	# 动态实例绑定一个属性
print(IBM.name)

def set_price(self, price):		# 定义一个函数作为实例方法
	self.price = price
	
from types import MethodType
IBM.set_price = MethodType(set_price, IBM)	# 给实例绑定一个方法
IBM.set_price(1)	# 调用实例方法
IBM.price	# 测试结果
# 给一个实例绑定的方法，对另一个实例是不起作用的：
# 为了给所有实例都绑定方法，可以给class绑定方法：
def set_price(self, price):
	self.price = price
	
Computer.set_price = MethodType(set_price, Computer)
# 动态绑定允许我们在程序运行的过程中动态给class加上功能，这在静态语言中很难实现。

# Python允许在定义class的时候，定义一个特殊的__slots__变量，来限制该class实例能添加的属性：
class Computer(object):
	__slots__ = ('name', 'memory')	# 用tuple定义允许绑定的属性名称
	
Lenovo = Computer()
Lenovo.name = 'Y470' # 绑定属性'name'
Lenovo.memory = '2G'
Lenovo.price = 3999 # 报错，不能绑定

# Note: __slots__定义的属性仅对当前类实例起作用，对继承的子类是不起作用的：