## Mini-Project1

项目说明：

	完成一个游戏，类似于中国的剪刀石头布，这个游戏有5个选择项：石头、大怪物、布、蜥蜴、剪刀
	
	游戏规则：每一个可以赢前面两个(五个构成环：循环结构)！
	
	coding: 实现三个函数
	
		number2name(number):	将数字转换为对应的游戏选项的名字
		
			实现方法：if-elif-else
			
			最后使用else处理异常数字情况，方便程序开发和调试！
		
		name2number(name):		将名字转换为对应的数字编号
		
			实现方法：if-elif-else
			
			最后使用else处理异常名字情况，方便程序开发和调试！
			
		rspls(name):	游戏主函数
			
			自动帮助电脑生成随机数字，作为电脑的选择 random.randrange(0,5)
			
			游戏规则的逻辑实现 if-elif-else
			
			打印一些提示信息，比如：选手的选择，电脑的选择，游戏结局 etc print
			
			rspls() 函数中会调用 name2number()将选手的选择转换成数字，方便用于比较大小
			
					调用number2name()将电脑的选择转换为字符串，方便打印电脑选择项的信息
	
		