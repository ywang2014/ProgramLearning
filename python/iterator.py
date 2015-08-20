#迭代器
#for 循环可直接作用的数据类型：Iterable, isinstance()
#	list、tuple、dict、set、str、generator(function)
from collection import Iterable
isinstance([], Iterable) # T
isinstance({}, Iterable) # T
isinstance('abc', Iterable) # T
isinstance((x for x in range(10)), Iterable) # T
isinstance(100, Iterable) # F

# Iterator 迭代器
isinstance((x for x in range(10)), Iterator) # T
isinstance([], Iterator) # F
isinstance({}, Iterator) # F
isinstance('abc', Iterator) # F

# 可使用iter()函数将list/dict/str等Iterable变成Iterator:
isinstance(iter([]), Iterator) # T

#凡是可作用于for循环的对象都是Iterable类型；
#凡是可作用于next()函数的对象都是Iterator类型，它们表示一个惰性计算的序列；数据流，可以是无限的，不存储

# Python的for循环本质上就是通过不断调用next()函数实现的

it = iter([1, 2, 3, 4, 5]) # 首先获得Iterator对象
# 循环 
while True:
	try:
		#获得下一个值
		x = next(it)
	except StopIteration:
		# 遇到StopIteration就退出循环
		break