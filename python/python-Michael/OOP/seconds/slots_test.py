# -*- coding: utf-8 -*-

# 第二遍学习 "使用__slots__"

# python是动态语言，所以可以给类、实例绑定任何属性和方法
# 使用__slots__可以限制给类添加属性

# 某同学设计的作业，有助于学习和理解，非常感谢

import functools
from types import MethodType

'''
设计一个基类，有三个派生类：复习累的方法覆盖和多态
使用__slots__限制类的成员属性，使用 type.MethodType()方法添加类函数
'''

class Animal(object):
	
	# 限制属性个数	
	# 注：必须有的属性才能使用MethodType()方法，在添加方法时添加该属性，如：'food', 在set_food中会添加此属性，所以此处必须有，否则报错，没有该属性
	__slots__ = ('name', 'sex', 'age', 'food', 'set_age')
	
	def __init__(self, name, sex):
		self.name = name
		self.sex = sex
	
	# 基类成员函数
	def greet(self, name):
		print('Hello ' + name + '!')
		print('I am the abstract of all animals!')
		
class Dog(Animal):
	
	# 覆盖greet方法
	def greet(self, name):
		print('Hello ' + name + '!')
		print('I am the abstract of all dogs!')
		
class Cat(Animal):
	
	# 覆盖greet方法
	def greet(self, name):
		print('Hello ' + name + '!')
		print('I am the abstract of all cats!')
		
class Rat(Animal):
	
	# 覆盖greet方法
	def greet(self, name):
		print('Hello ' + name + '!')
		print('I am the abstract of all rats!')
		
# 准备动态添加的函数
def set_age(self, age):
	self.age = age
	
def set_food(self, food):
	self.food = food
	
def hello(self, obj):
	obj.greet(obj.name)

# 类的实例化
animal_case = Animal('mammal', 'male')

# 动态添加实例属性
animal_case.age = 100
print(animal_case.age)
# 动态给实例绑定方法
#animal_case.set_food = MethodType(set_food, animal_case)	# 给实例绑定方法，对其他实例是不起作用的，此时类slots必须有这个属性，否则不能添加
animal_case.set_age = MethodType(set_age, animal_case)
animal_case.set_age(99)
print(animal_case.age)

# 给类增加方法
print('Before add function:')
print(dir(Animal))
Animal.set_food = MethodType(set_food, Animal)
print('After add function:')
print(dir(Animal))
Animal.hello = MethodType(hello, Animal)

dog_case = Dog('Chihuahua', 'male')
cat_case = Cat('pussy', 'female')
rat_case = Rat('mouselet', 'male')

# 多态应用演示
animal_case.hello(animal_case)
animal_case.hello(dog_case)
animal_case.hello(cat_case)
animal_case.hello(rat_case)

input('Pause!')

def test():
	import functools
	from types import MethodType

	'''
	设计一个基类，有三个派生类：复习累的方法覆盖和多态
	使用__slots__限制类的成员属性，使用 type.MethodType()方法添加类函数
	'''

	class Animal(object):
	
		# 限制属性个数	
		# 注：必须有的属性才能使用MethodType()方法，在添加方法时添加该属性，如：'food', 在set_food中会添加此属性，所以此处必须有，否则报错，没有该属性
		__slots__ = ('name', 'sex', 'age', 'food', 'set_age')
	
		def __init__(self, name, sex):
			self.name = name
			self.sex = sex
	
		# 基类成员函数
		def greet(self, name):
			print('Hello ' + name + '!')
			print('I am the abstract of all animals!')
		
	class Dog(Animal):
	
		# 覆盖greet方法
		def greet(self, name):
			print('Hello ' + name + '!')
			print('I am the abstract of all dogs!')
		
	class Cat(Animal):
	
		# 覆盖greet方法
		def greet(self, name):
			print('Hello ' + name + '!')
			print('I am the abstract of all cats!')
		
	class Rat(Animal):
	
		# 覆盖greet方法
		def greet(self, name):
			print('Hello ' + name + '!')
			print('I am the abstract of all rats!')
			
	def set_age(self, age):
		self.age = age
		
	def set_food(self, food):
		self.food = food
	
	def hello(self, obj):
		obj.greet(obj.name)

	# 类的实例化
	animal_case = Animal('mammal', 'male')

	# 动态添加实例属性
	animal_case.age = 100
	print(animal_case.age)
	# 动态给实例绑定方法
	#animal_case.set_food = MethodType(set_food, animal_case)	# 给实例绑定方法，对其他实例是不起作用的，此时类slots必须有这个属性，否则不能添加
	animal_case.set_age = MethodType(set_age, animal_case)
	animal_case.set_age(99)
	print(animal_case.age)

	# 给类增加方法
	print('Before add function:')
	print(dir(Animal))
	Animal.set_food = MethodType(set_food, Animal)
	print('After add function:')
	print(dir(Animal))
	Animal.hello = MethodType(hello, Animal)

	dog_case = Dog('Chihuahua', 'male')
	cat_case = Cat('pussy', 'female')
	rat_case = Rat('mouselet', 'male')

	# 多态应用演示
	animal_case.hello(animal_case)
	animal_case.hello(dog_case)
	animal_case.hello(cat_case)
	animal_case.hello(rat_case)

	input('Pause!')