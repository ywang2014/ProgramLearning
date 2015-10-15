# -*- coding: utf-8 -*-

# 偏函数
# 偏函数的这些应用看似简单，用途却很大，可以很好的执行DRY原则，节省编程成本

# 通过functools模块被用户调用
# 偏函数是将所要承载的函数作为partial()函数的第一个参数，原函数的各个参数依次作为partial()函数后续的参数
	# 除非使用关键字参数
	
# 偏函数就是可以直接设置函数默认参数，使得函数调用更加简单，或者说可以非常非常简单地用原函数创建新函数

from functools import partial

def mod(m, n):	# 使用n对m求模
	if m == 0:
		return None
	return n % m 
	
# 创建新函数
mod_by_2 = partial(mod, 2)	# 求任意数模2的余数
mod_by_3 = partial(mod, 3)	# 求任意数模3的余数

print(mod_by_2(11))	# 1,奇数
print(mod(2, 11))

print(mod_by_3(11))	# 2,除3余2
print(mod(3, 11))

#######################
# 进制转换
bin2dec = partial(int, base = 2)
print(int('10001'))		# 10001
print(bin2dec('10001'))	# 17

hex2dec = partial(int, base = 16)
print(int('67'))		# 67
print(hex2dec('67'))	# 103

input('pause!')