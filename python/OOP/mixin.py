# -*- coding: utf-8 -*-

# 多重继承
# 继承是面向对象编程的一个重要的方式，因为通过继承，子类就可以扩展父类的功能

# 设计动物的类层次
	animal ：dog(狗狗), bat(蝙蝠), parrot(鹦鹉), Ostrich(鸵鸟)
	
# 如果按照哺乳动物和鸟类归类, 设计出这样的类的层次：
# Animal -> Mammal	Animal -> Bird	Mammal -> Dog	Mammal -> Bat	Bird -> Parrot	Bird -> Ostrich
# Animal -> Mammal	Animal -> Bird	Mammal -> Dog	Mammal -> Bat	Bird -> Parrot	Bird -> Ostrich
	# 哺乳类：能跑的哺乳类，能飞的哺乳类； 鸟类：能跑的鸟类，能飞的鸟类。
class Animal(object):
	def fn(self):
		return self._name
		
class Mammal(Animal):
	def fn(self):
		return self._name
		
class Bird(self):
	def fn(self):
		return self._name
		
class Bat(Mammal):
	def Bat(self):
		return self._name
		
class Dog(Mammal):
	def fn(self):
		return self._name
		
class Parrot(Bird):
	def fn(self):
		return self._name
		
class Ostrich(Bird):
	def fn(self):
		return self._name
		
		
# 给动物再加上Runnable和Flyable的功能，只需要先定义好Runnable和Flyable的类：
class Runnable(object):
	def run(self):
		print('Running...')
		
class Flyable(object):
	def fly(self):
		print('Flying...')
		
# 对于需要Runnable功能的动物，就多继承一个Runnable，例如Dog：
class Dog(Mammal, Runnable):
	pass
	
class Bat(Mammal, Flyable):
	pass
	
## 通过多重继承，一个子类就可以同时获得多个父类的所有功能

# Mixln		让Ostrich除了继承自Bird外，再同时继承Runnable。这种设计通常称之为MixIn。
	# 为了更好地看出继承关系，我们把Runnable和Flyable改为RunnableMixIn和FlyableMixIn
class Dog(Mammal, RunnableMixIn, CarnivorousMixIn):
    pass
# class Dog(Mammal, RunnableMixIn, CarnivorousMixIn):
    pass

	# class Dog(Mammal, RunnableMixIn, CarnivorousMixIn):
    pass
# class Dog(Mammal, RunnableMixIn, CarnivorousMixIn):
    pass

# MixIn的目的就是给一个类增加多个功能，这样，在设计类的时候，我们优先考虑通过多重继承来组合多个MixIn的功能，而不是设计多层次的复杂的继承关系。

# Python自带了TCPServer和UDPServer这两类网络服务，而要同时服务多个用户就必须使用多进程或多线程模型，这两种模型由ForkingMixIn和ThreadingMixIn提供
	# 编写一个多进程模式的TCP服务
class MyTCPServer(TCPServer, ForkingMixIn):
	pass
	
	# 编写一个多线程模式的UDP服务
class MyUDPServer(UDPServer, ThreadingMixln):
	pass
	
	# 搞一个更先进的协程模型，可以编写一个CoroutineMixIn：
class MyTCPServer(TCPServer, CoroutineMixIn):
	pass
	
## 由于Python允许使用多重继承，因此，MixIn就是一种常见的设计, Java只允许单一进程
		
