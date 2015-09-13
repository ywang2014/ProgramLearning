# -*- coding: utf-8 -*-

# Local vs global

	# 定义在函数外的变量属于全局变量
	# 定义在函数里面的变量属于局部变量
	
	# 局部变量只能在函数里面使用，函数调用完就不存在了。函数里面定义修改的都是局部变量，都会在函数调用完消失
	
	def fahren_to_kelvin(fashren):
		celsius = 5.0 / 9 * (fahren - 32)
		zero_celsius_in_kelvin = 273.15
		return celsius + zero_in_kelvin
		
	print(fahren_to_kelvin(32))
	
	num = 4
	def fun():
		global num	# 想要修改全局变量时，才声明为全局的。
		num = 5
		
	print(num)	# 4
	fun()
	print(num) # 5
	
	# 使用全局变量实现事件驱动程序
	# 程序依靠全局变量进行通信和传输数据：公共变量