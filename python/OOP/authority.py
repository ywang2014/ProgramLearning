# -*- coding: utf-8 -*-

# 访问限制
# 在Python中，实例的变量名如果以__开头，就变成了一个私有变量（private），只有内部可以访问，外部不能访问
class Stu(object):

	def __init__(self, name, score):
		self.__name = name
		self.__score = score
	
	def print_score(self):
		print('%s: %s' % (self.__name, self.__score))
		
	def getName(self):
		return self.__name
		
# 通过访问限制的保护，代码更加健壮
# 在方法中，可以对参数做检查，避免传入无效的参数：
	 def setName(self, name):
                 if isinstance(name, str):
                         self.__name = name
		else:
                        raise Error('Not a String')
			
# 在Python中，变量名类似__xxx__的，也就是以双下划线开头，并且以双下划线结尾的，是特殊变量
	# 特殊变量是可以直接访问的，不是private变量
# 一个下划线开头的实例变量名，比如_name，这样的实例变量外部是可以访问的
	# 俗成的规定: 虽然我可以被访问，但是，请把我视为私有变量，不要随意访问
# 不能直接访问__name是因为Python解释器对外把__name变量改成了_Student__name
	# 仍然可以通过_Student__name来访问__name变量：sb._Student__name
