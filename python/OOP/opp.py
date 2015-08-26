# -*- coding: utf-8 -*-

# 面向对象编程——Object Oriented Programming
	# 面向过程的程序设计把计算机程序视为一系列的命令集合，即一组函数的顺序执行
	# 面向对象的程序设计把计算机程序视为一组对象的集合，程序的执行就是一系列消息在各个对象之间传递
	
# 面向过程编程：
	# 表示学生的成绩，使用 dict
stu1 = {'name': 'Tom', 'score': 98}
stu2 = {'name': 'Alice', 'score': 100}
def print_info(std):
	print('%s: %s' % (stu['name'], std['score']))
	
# 面向对象编程：
	# student 的数据类型属于对象，Property and function
class student(object):
	def __init__(self, name, score):
		self.name = name
		self.score = score
		
	def print_info(self):
		print('%s: %s' % (self.name, self.score))
		
# 发送消息，即调用对象对应的关联函数，我们称之为对象的方法（Method）
Tom = student('Tom', 100)
Tom.print_info()

## 面向对象的设计思想是抽象出Class，根据Class创建Instance
## 数据封装、继承和多态是面向对象的三大特点
