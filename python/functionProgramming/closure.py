# -*- coding: utf-8 -*-

# 函数作为返回值
# 可变参数求和
def lazy_sum(*args):
	def sum():
		result = 0
		for n in args:
			result += n
		return result
	return sum
	
# 调用lazy_sum()时，返回的并不是求和结果，而是求和函数：
f = lazy_sum(1, 3, 5, 7, 9)
# 调用 f 时，才真正计算求和结果：
f()

## 这种称为“闭包（Closure）”的程序结构
	# 注意到返回的函数在其定义内部引用了局部变量args，所以，当一个函数返回了一个函数后，
	# 其内部的局部变量还被新函数引用，所以，闭包用起来简单，实现起来可不容易。
	# 返回的函数并没有立刻执行，而是直到调用了f()才执行
	
	
# 每次循环，都创建了一个新的函数，然后，把创建的3个函数都返回
def count():
	fs = []
	for i in range(1, 4):
		def fn():
			return i * i
		fs.append(fn)
	return fs
	
f1, f2, f3 = count()
f1()
f2()
f3()
# 可能认为调用f1()，f2()和f3()结果应该是1，4，9, 实际全部都是9
# 原因就在于返回的函数引用了变量i，但它并非立刻执行。等到3个函数都返回时，它们所引用的变量i已经变成了3，因此最终结果为9

# 返回闭包时牢记的一点就是：返回函数不要引用任何循环变量，或者后续会发生变化的变量
# 引用循环变量的办法：方法是再创建一个函数，用该函数的参数绑定循环变量当前的值，无论该循环变量后续如何更改，已绑定到函数参数的值不变：
def count2():
	def fn(n):
		def g():
			return n * n
		return g
	ptr = []
	for i in range(1, 4):
		ptr.append(fn(i))
	return ptr
	# 正确
	
def count3():
	def fn(n):
		return n * n
	ptr = [] # ptr[] 语法不允许
	for i in range(1, 4):
		ptr.append(fn)
	return ptr
	# 错误
	

# 匿名函数
# 匿名函数 lambda x: x * x 等价于：
def f(x):
	return x * x

# 关键字lambda表示匿名函数，冒号前面的x表示函数参数
# 匿名函数有个限制，就是只能有一个表达式，不用写return，返回值就是该表达式的结果
# 用匿名函数有个好处，因为函数没有名字，不必担心函数名冲突。此外，匿名函数也是一个函数对象，也可以把匿名函数赋值给一个变量，再利用变量来调用该函数：
f = lambda x : x ** 3
f(2) # 8
# 可以把匿名函数作为返回值返回:
def build(x, y):
	return lambda: x * x + y * y
	
# 函数对象有一个__name__属性，可以拿到函数的名字：
build._name_ 	# 'build'