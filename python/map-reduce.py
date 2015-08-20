# Python内建了map()和reduce()函数

#map()函数接收两个参数，一个是函数，一个是Iterable，map将传入的函数依次作用到序列的每个元素，并把结果作为新的Iterator返回。
def f(x):
	return x * x
	
r = map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9])
list(r)
#map()传入的第一个参数是f，即函数对象本身。由于结果r是一个Iterator，Iterator是惰性序列，因此通过list()函数让它把整个序列都计算出来并返回一个list。

#不需要map()函数，写一个循环，也可以实现：
L = []
for n in [1, 2, 3, 4, 5, 6, 7, 8, 9]:
	L.append(f(n))
print(L)

list(map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9]))

#再看reduce的用法。reduce把一个函数作用在一个序列[x1, x2, x3, ...]上，这个函数必须接收两个参数，reduce把结果继续和序列的下一个元素做累积计算，其效果就是：
# reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
from functools import reduce 
def add(x, y):
	return x + y
	
reduce(add, [1, 3, 5, 7, 9]) # sum()

# 把字符串转化为整数的函数
from functools import reduce 
def str2int(s):
	def fn(x, y):
		return x * 10 + y
	def char2num(s):
		return {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}[s]
	return reduce(fn, map(char2num, s))

# -*- coding: utf-8 -*-
#利用map()函数，把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字
def normalize(name):
	name = name[0].upper() + name[1:].lower()
	return name
	
list(map(normalize, ['adam', 'LISA', 'barT']))

#Python提供的sum()函数可以接受一个list并求和，请编写一个prod()函数，可以接受一个list并利用reduce()求积：
# -*- coding: utf-8 -*-

from functools import reduce

def prod(L):
	def fn(x, y):
		return x * y
	return reduce(fn, L)
	
print('3 * 5 * 7 * 9 = ', prod([3, 5, 7, 9]))

#利用map和reduce编写一个str2float函数，把字符串'123.456'转换成浮点数123.456：
# -*- coding: utf-8 -*-

from functools import reduce

def str2float(s):
	def fn(x, y):
		return x * 10 + y
	def char2int(ch):
		return {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}[ch]
	L = s.split('.')
	#decimal = len(L[1]) 无'.'split()函数报错
	#if decimal < 1:
	#	decimal = 1
	intnum = reduce(fn, map(char2int, L[0]))
	decimalnum = reduce(fn, map(char2int, L[1])) / pow(10, len(L[1])) # len(L[1])只是长度，pow(10, len(L[1]))
	return intnum + decimalnum
	

