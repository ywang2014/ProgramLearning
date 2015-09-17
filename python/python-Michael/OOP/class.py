# -*- coding: utf-8 -*-

# 类(class)和实例(instance)
	# 必须牢记类是抽象的模板
	# 实例是根据类创建出来的一个个具体的“对象”
	
class MyClass(object):
	pass
	# (object)，表示该类是从哪个类继承下来的 : object类，这是所有类最终都会继承的类
	
object1 = MyClass() # 创建对象

# __init__特殊方法，可以强制给对象设置属性
# 注意到__init__方法的第一个参数永远是self，表示创建的实例本身: self就指向创建的实例本身(this)
# 有了__init__方法，在创建实例的时候，就不能传入空的参数了，必须传入与__init__方法匹配的参数，但self不需要传，Python解释器自己会把实例变量传进去：
# 和普通的函数相比，在类中定义的函数只有一点不同，就是第一个参数永远是实例变量self，并且，调用时，不用传递该参数


# 数据封装：用类方法
class Book(object):
	def __init__(self, name, price, rank):
		self.name = name
		self.price = price
		self.rank = rank
		
	def printInfo(self):
		print('%s %s %s' % (self.name, self.price, self.rank))
		
	def getRank(self):
		if self.rank >= 4.5:
			return 'Great'
		elif self.rank >= 3.5:
			return 'Good'
		else :
			return 'Not bad'
			
# call
Bible = Book('Bible', '$100', 5)	# 必须传入参数，self不用传递
Bible.printInfo()
Bible.getRank()

# 类是创建实例的模板，而实例则是一个一个具体的对象，各个实例拥有的数据都互相独立，互不影响；
#方法就是与实例绑定的函数，和普通函数不同，方法可以直接访问实例的数据；

# 和静态语言不同，Python允许对实例变量绑定任何数据
	# 因此，对于两个实例变量，虽然它们都是同一个类的不同实例，但拥有的变量名称都可能不同：