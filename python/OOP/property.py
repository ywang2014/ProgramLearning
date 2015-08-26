# -*- coding: utf-8 -*-

# 使用@property

# 使用封装，可以进行参数检测
class Person(object):
	def get_age(self):
		return self._age
		
	def set_age(self, value):
		if not isinstance(value, int):		# 控制参数为整形
			raise ValueError('age must be an integer')
		if value < 0 or value > 150:		# 控制参数范围合理
			raise ValueError('age must be 0 ~ 150')
		self._age = value
		
# 缺点：上面的调用方法又略显复杂，没有直接用属性这么直接简单
# Python内置的@property装饰器就是负责把一个方法变成属性调用的：
class Person(object):
	@property
	def age(self):
		return self._age 
		
	@age.setter
	def age(self, value):
		if not isinstance(value, int):
			raise ValueError('age must be an integer')
		if value < 0 or value > 150:
			raise ValueError('age must be 0 ~ 150')
		self._age = value
		
# @property的实现比较复杂，我们先考察如何使用
	# 把一个getter方法变成属性，只需要加上@property就可以了
	# @property本身又创建了另一个装饰器@age.setter，负责把一个setter方法变成属性赋值
Tom = Person()
Tom.age = 18	# ok，实际转化为Tom.set_age(18)
Tom.age			# ok，实际转化为Tom.get_age()

# @property，我们在对实例属性操作的时候，就知道该属性很可能不是直接暴露的，而是通过getter和setter方法来实现的

# 还可以定义只读属性，只定义getter方法，不定义setter方法就是一个只读属性：
class Student(object):
	@property
	def birth(self):
		return self._birth
		
	@birth.setter
	def birth(self, value):
		self._birth = value
		
	@property
	def age(self):
		return 2015 - self._birth
		
# 上面的birth是可读写属性，而age就是一个只读属性，因为age可以根据birth和当前时间计算出来

## @property广泛应用在类的定义中，可以让调用者写出简短的代码，同时保证对参数进行必要的检查，这样，程序运行时就减少了出错的可能性

# 练习 
	# 请利用@property给一个Screen对象加上width和height属性，以及一个只读属性resolution：
class Screen(object):
	@property
	def width(self):
		return self._width
	
	@width.setter
	def width(self, value):
		self._width = value
		
	@property 
	def height(self):
		return self._height
		
	@height.setter
	def height(self, value):
		self._height = value
			
	@property
	def resolution(self):   # 函数名 就是 属性名
		return self._width * self._height 
		
## @property 实际是：将getter 和 setter 函数名变成了“属性名” 

# test:
s = Screen()
s.width = 1024
s.height = 768
print(s.resolution)
assert s.resolution == 786432, '1024 * 768 = %d ?' % s.resolution 
