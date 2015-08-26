# -*- conding: utf-8 -*-

# 继承和多态(inheritance and polymorphism)

class Animal(object):
	def __init__(self, name, age):
		self.__name = name
		self.__age = age
	def info(self):
		print('I am animal...')
		
class Dog(Animal):
	def info(self):
		print('I am dog...')
class Cat(Animal):
	def info(self):
		print('I am cat...')
		
# 继承最大的好处是子类获得了父类的全部功能
# 多态: 类和父类都存在相同的run()方法时，子类的run()覆盖了父类的run()
# 在继承关系中，如果一个实例的数据类型是某个子类，那它的数据类型也可以被看做是父类

def infoAnimal(animal):
	animal.run()
infoAnimal(Animal())	# I am a animal...
infoAniaml(Dog())		# I am dog...
infoAnimal(Cat())		# I am cat...
# 多态的好处：当我们需要处理多个子类类型的时候，只需要传入父类型就可以了，不需要写很多遍函数
# 当调用父类的方法时，自动会调用相应的子类方法。多态，多种状态
# 著名的“开闭”原则：
#		对扩展,开放：允许新增Animal子类
#		对修改封闭：不需要修改依赖Animal类型的infoAnimal()等函数

# 对于静态语言（例如Java）来说，如果需要传入Animal类型，则传入的对象必须是Animal类型或者它的子类，否则，将无法调用run()方法
# 对于Python这样的动态语言来说，则不一定需要传入Animal类型。我们只需要保证传入的对象有一个run()方法就可以了：

# 继承可以把父类的所有功能都直接拿过来，这样就不必重零做起，子类只需要新增自己特有的方法，也可以把父类不适合的方法覆盖重写
# 动态语言的鸭子类型特点决定了继承不像静态语言那样是必须的