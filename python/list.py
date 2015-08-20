#列表生成式 List Comprehensions
list(range(1, 11)) # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

#生成特殊列表
L = []
for x in range(1, 11):
	L.append(x * x) #公式可以换，主要是利用到循环
	# [x * x for x in range(1, 11)] 简洁
	
# 加 if判断
[x * x for x in range(1, 11) if x % 2 == 0]

#两层循环，生成全排列
[m + n for m in 'ABC' for n in 'XYZ']

#列出当前目录下的所有文件和目录名
import os # 导入os模块
[d for d in os.listdir('.')] # os.listdir可以列出文件和目录

# 两个变量生成list：
d = {'x' : 'A', 'y' : 'B', 'z' : 'C'}
[k + '=' + v for k, v in d.items()]

#把list中的所有字符串变成小写：
L = ['Hello', 'World', 'IBM', 'Apple']
[s.lower() for s in L]

# 非字符串类型没有lower()方法
#内建的isinstance函数可以判断一个变量是不是字符串：
isinstance(123, str) # False

# -*- coding: utf-8 -*-

L1 = ['Hello', 'World', 18, 'Apple', None]
L2 = [s.lower() for s in L1 if isinstance(s, str)]
print(L2)
	

	
