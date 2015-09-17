# 迭代
d = {'a':1, 'b':2, 'c':3}
for key in d:
	print(key)
	# dict 默认迭代的是key，迭代value：for value in d.values()，同时迭代key和value：for k, v in d.items()
	
#字符串迭代
for ch in 'ABC':
	print(ch)
	
#判断一个对象是否是可迭代对象，通过collections模块的Iterable类型判断：
from collections import Iterable
isinstance('abc', Iterable)	#str是否可迭代 True
isinstance([1,2,3], Iterable) #list是否可迭代 True
isinstance(123, Iterable) #整数是否可迭代 False

#Python内置的enumerate函数可以把一个list变成索引-元素对，这样就可以在for循环中同时迭代索引和元素本身：
for i, value in enumerate(['A','B','C']):
	print(i, value)
	
#同时引用了两个变量，在Python里是很常见的
for x, y in [(1,1), (2,4), (3,9)]:
	print(x, y)