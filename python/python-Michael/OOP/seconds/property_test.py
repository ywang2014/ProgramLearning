# -*- coding: utf-8 -*-

# 装饰器 @property
# 装饰器可以把一个类的方法伪装成其成员属性，然后实现直接赋值和取值

	# obj.getValue() 等价于 obj.value
	# obj.setValue(value) 等价于 obj.value = value
	
	# 好处，方法的实现，可以实现封装信息和类型检查等优点，解决了成员属性的缺点
	# 兼有成员属性优点：可以方便的赋值和读取
	
class Money(object):
	
	@property
	def amount(self):	# getter方法很简单，添加@property即可。
		return self._amount
		
	@amount.setter
	def amount(self, value):
		if not (isinstance(value, float) or isinstance(value, int)):
			raise ValueError('amount must be a float')
		if value < 0:
			raise ValueError('Amount must be positive')
		self._amount = value
		
mon = Money()
mon.amount = 500000
print(mon.amount)
		
# 获取当前时间
import time
print(time.localtime(time.time()))
print(time.strftime('%Y-%m-%d %H:%M:%S'))

input('Pause!')