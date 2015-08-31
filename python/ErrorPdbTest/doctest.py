# -*- coding: utf-8 -*-

# 文档测试 doctest
	# Python内置的“文档测试”（doctest）模块可以直接提取注释中的代码并执行测试
	
# 用doctest来测试上次编写的Dict类：
# mydict2.py
class Dict(dict):
	'''
	Simple dict but also support access as x.y style.
	
	>>> d1 = Dict()
	>>> d1['x'] = 100
	>>> d1.x
	100
	>>> d1.y = 200
	>>> d1['y']
	200
	>>> d2 = Dict(a = 1, b = 2, c = '3')
	>>> d2.c
	'3'
	>>> d2['empty']
	Traceback (most result call last):
	
		...
	AttributeError: 'Dict' object has no attribute 'empty'
	'''
	def __init__(self, **kw):
		super(Dict, self).__init__(**kw)
		
	def __getattr__(self, key):
		try:
			return self[key]
		except KeyError:
			raise AttributeError(r"'Dict' object has no attribute '%s'" % key)
			
	def __setattr__(self, key, value):
		self[key] = value
		
if __name__ == '__main__':
	import doctest
	doctest.testmod()
# 注意到最后3行代码。当模块正常导入时，doctest不会被执行。只有在命令行直接运行时，才执行doctest
	
$ python3 mydict2.py	# 运行
# 什么输出也没有。这说明我们编写的doctest运行都是正确的
	# 只有测试异常的时候，可以用...表示中间一大段烦人的输出。


## 练习
	#函数fact(n)编写doctest并执行：
def fact(n):
	'''
	Simple math function : factorail
	>>> f = fact(0)
	>>> f
	ValueError 0 < 1
	>>> fact(1)
	1
	>>> fact(5)
	120
	'''
	if n < 1:
		raise ValueError()
	if n == 1:
		return 1 
	return n * fact(n - 1)
	
if __name__ == '__main__':
	import doctest
	doctest.testmod()
	
	