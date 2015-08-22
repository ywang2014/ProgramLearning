# -*- coding: utf-8 -*-

# 偏函数（Partial function）
	# 通过设定参数的默认值，可以降低函数调用的难度
	int('12345') # 12345，默认按十进制转换
	int('12345', base = 8) # 八进制
	int('12345', base = 16) # 十六进制
	
# functools.partial就是帮助我们创建一个偏函数的，不需要我们自己定义int2()，可以直接使用下面的代码创建一个新的函数int2：
# 创建偏函数的意思：即修改参数默认值，方便大量的重复操作该函数
import functools
int2 = functools.partial(int, base = 2)
int2('1000000') # 64
# 把一个函数的某些参数给固定住（也就是设置默认值），返回一个新的函数，调用这个新函数会更简单。

# 创建偏函数时，实际上可以接收函数对象、*args和**kw这3个参数
	# **kw
int2('100') # 等价于：kw = { 'base': 2 }  int('10010', **kw)
	# *args
max2 = functools.partial(max, 10)
max2(2, 3, 4) # 等价于: args = (10, 5, 6, 7)  max(*args)

# 当函数的参数个数太多，需要简化时，使用functools.partial可以创建一个新的函数，这个新函数可以固定住原函数的部分参数，从而在调用时更简单。
