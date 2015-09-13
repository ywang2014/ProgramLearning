# Event-driven programming

	# Events
		
		# Input
			# Button # 在程序中创建一个按钮，就得写一个处理程序 Handler
			# Text box
		# keyboard
			# key down
			# key up 
		# Mouse
			# Click
			# Drag
		# Timer # 周期性触发，动作使用计数器触发
		
# example of a simple event-driven programming

import simplegui	# 构建python 交互式程序

# event handler 事件处理程序
def tick():
	print ("tick")
	
# register handler 注册事件处理程序
timer = simplegui.create_timer(1000, tick)	# 每秒(毫秒)响应一次
# 第一个参数：毫秒，第二个参数：想要调用的函数(tick)

# start timer 启动计时器
timer.start()

# Event Queue 事件队列机制 

# 处理程序在运行时是独占的，有新事件，仅仅排入到内部事件队列
# 如果写一个很长处理程序或者有死循环，就会阻断其他事件的处理，因此程序就会奇慢无比


