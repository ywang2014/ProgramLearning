# -*- coding: utf-8 -*-
# 排序算法

sorted([36, 5, -12, 9, -21])

# sorted()函数也是一个高阶函数，它还可以接收一个key函数来实现自定义的排序
	sorted([36, 5, -12, 9, -21], key = abs)
	
	#对字符串排序，是按照ASCII的大小比较的: 可忽略大小写
	sorted(['bob', 'about', 'Zoo', 'Credit'], key = str.lower)
	
	sorted(['bob', 'about', 'Zoo', 'Credit'], key = str.lower, reverse = True)
	
#sorted()也是一个高阶函数。用sorted()排序的关键在于实现一个映射函数。

# 练习：
	#假设我们用一组tuple表示学生名字和成绩：
	#L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
	#请用sorted()对上述列表分别按名字排序：
	
	L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
	def by_name(t):
		return t[0]
		
	sorted(L, key = by_name)
		
	sorted(L, key = lambda item: item[0])
	
	#按成绩从高到低排序：
	sorted(L, key = lambda item: item[1], reverse = True)