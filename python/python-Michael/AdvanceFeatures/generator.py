#!/usr/bin/env python3
# -*- coding: utf-8 -*-


# 一边循环一边计算的机制，称为生成器：generator
	#generator保存的是算法
	#list保存所有的元素，浪费空间

# 第一种方法： [] 改成 ()
L = [x * x for x in range(10)]
g = (x * x for x in range(10))
for n in g:
	print(n) #打印generator元素 ，也可以next(g),笨拙

#斐波那契数列：列表生成式写不出来，可使用函数：
def fib(max):
	n, a, b = 0, 0, 1
	while n < max:
		print(b)
		a, b = b, a + b
		n = n + 1
	return 'done'

# 第二种方法：函数定义中包含yield关键字，那么这个函数就不再是一个普通函数，而是一个generator：
	#generator的函数，在每次调用next()的时候执行，遇到yield语句返回，再次执行时从上次返回的yield语句处继续执行。
	#函数遇到return返回，或函数块执行完返回
def odd():
	print('step 1')
	yield 1
	print('step 2')
	yield(3)
	print('step 3')
	yield(5)
#调用函数
o = odd()
next(o)
next(o)
next(o)
next(o) # StopIteration

def fib(max):
	n, a, b = 0, 0, 1
	while n < max:
		yield b #generator
		a, b = b, a + b
		n = n + 1
	return 'done'
	
for n in fib(6):
	print(n)
#用for循环调用generator时，发现拿不到generator的return语句的返回值
#必须捕获StopIteration错误，返回值包含在StopIteration的value中：
g = fib(8)
while True:
	try:
		x = next(g)
		print('g:', x)
	except StopIteration as e:
		print('Generator return value:', e.value)
		break
		
# 杨辉三角

def triangles():
	l = []
	while True:
		n = 1
		px = 1 
		for x in l[1:]:
			l[n] = px + x
			px = x
			n = n + 1
		l.append(1)
		yield l

#测试
n = 0
for i in triangles():
	print(i)
	n = n + 1
	if n == 10:
		break