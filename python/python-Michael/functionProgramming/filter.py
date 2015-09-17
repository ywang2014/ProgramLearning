# -*- coding: utf-8 -*-

# Python内建的filter()函数用于过滤序列

#filter()接收一个函数和一个序列。和map()不同的时，filter()把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素
	#在一个list中，删掉偶数，只保留奇数
def is_odd(n):
	return n % 2 == 1
	
list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10]))

	#把一个序列中的空字符串删掉:
def not_empty(s):
	return s and s.strip()
	
list(filter(not_empty, ['A', '', 'B', None, ' ']))

# filter()这个高阶函数，关键在于正确实现一个“筛选”函数
#注意到filter()函数返回的是一个Iterator，也就是一个惰性序列，所以要强迫filter()完成计算结果，需要用list()函数获得所有结果并返回list。

#埃氏筛法（埃拉托色尼选筛法）
	# 先构造一个从3开始的奇数序列：
	def _odd_iter():
		n = 1
		while True:
			n = n + 2
			yield n 
		#注意这是一个生成器，并且是一个无限序列
		
	# 筛选函数：
	def _not_divisible(n):
		return lambda x : x % n > 0
		# lambda定义一个表达式，其他和def一样：f(x) = (x % n > 0)
		
	#定义一个生成器，不断返回下一个素数：
	def prime():
		yield 2 #第一个素数: 2
		it = _odd_iter() #初始序列
		while True:
			n = next(it) #返回序列的第一个数: 3，5,7,11
			yield n
			it = filter(_not_divisible(n), it) #构造新序列
			#利用filter()不断产生筛选后的新的序列
			
	#primes()也是一个无限序列，所以调用时需要设置一个退出循环的条件：
	for n in primes():
		if n < 1000:
			print(n)
		else:
			break
			
			
#练习 ：回数是指从左向右读和从右向左读都是一样的数，例如12321，909。请利用filter()滤掉非回数：

def is_palindrome(m):
	def numbers():
		n = 9
		while True:
			n = n + 1 
			yield n
			
	def judge(n):
		old_n = n
		new_n = 0
		while True:
			if old_n < 1 :
				break
			new_n = new_n * 10 + old_n % 10
			old_n = old_n // 10
		return new_n == n
	
	it = numbers()
	while True:
		it = filter(judge, it)
		n = next(it)
		if n < m :
			break
		yield n
		
output = filter(judge, range(1,1000))
print(list(output))

#################################################
# 同学代码
def is_palindrome(n): 
	L=[] 
	while n: 
		L.append(n%10) 
		n=int(n/10) 
	i=0 
	j=len(L)-1 
	while i<j: 
		if L[i]==L[j]: 
			i+=1 
			j-=1 
		else: 
			return False 
		return True