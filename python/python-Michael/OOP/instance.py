# -*- coding: utf-8 -*-

# 实例属性和类属性

	# 由于Python是动态语言，根据类创建的实例可以任意绑定属性。
class Student(object):
	def __init__(self, name):
		self.name = name	# 通过self绑定属性
		
s = Student('Bob')
s.score = 90	# 通过实例绑定属性

# 可以直接在class中定义属性，这种属性是类属性，归Student类所有：
class Student(object):
	name = 'Tom'
	
s = Student()	# 创建实例
print(s.name)	# 打印name属性，因为实例没有name属性，所以会继续查找class的属性
print(Student.name) # 打印类属性
s.name = 'Jonson'	# 给实例绑定name属性
print(s.name)	# 实例属性优先级比类属性高，因此，它会屏蔽掉类的name属性
print(Student.name) # 类属性仍然可以访问，没有变化
del s.name		# 删除实例name属性
print(s.name)	# 实例name属性不存在，则显示类的name属性

## 在编写程序的时候，千万不要把实例属性和类属性使用相同的名字，因为相同名称的实例属性将屏蔽掉类属性，但是当你删除实例属性后，再使用相同的名称，访问到的将是类属性
