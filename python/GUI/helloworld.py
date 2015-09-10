# -*- coding: utf-8 -*-

# 图形界面
	# 支持图形界面的第三方库：TK wxWidgets Qt GTK
	# python自带的库，支持Tk的Tkinter 
	
# Tkinter 
	# 我们编写的Python代码会调用内置的Tkinter，Tkinter封装了访问Tk的接口
	# Tk是一个图形库，支持多个操作系统，使用Tcl语言开发
	# Tk会调用操作系统提供的本地GUI接口，完成最终的GUI
	
# 编写一个GUI版本的“Hello, world!”
from Tkinter import *		# 导入Tkinter包的所有内容：(3.x使用小写: tkinter，2.7使用大写Tkinter)

class Application(Frame):	# 从Frame派生一个Application类，这是所有Widget的父容器
	def __init__(self, master = None):
		Frame.__init__(self, master)
		self.pack()
		self.createWidgets()
		
	def createWidgets(self):
		self.helloLabel = Label(self, text = 'Hello, world!')
		self.helloLabel.pack()
		self.quitButton = Button(self, text = 'Quit', command = self.quit)
		self.quitButton.pack()
		
# 在GUI中，每个Button、Label、输入框等，都是一个Widget。Frame则是可以容纳其他Widget的Widget
# 所有的Widget组合起来就是一棵树
# pack()方法把Widget加入到父容器中，并实现布局。pack()是最简单的布局，grid()可以实现更复杂的布局
# 在createWidgets()方法中，我们创建一个Label和一个Button，当Button被点击时，触发self.quit()使程序退出

# 实例化Application，并启动消息循环：
app = Application()
app.master.title('Hello World!')	# 设置窗口标题:
app.mainloop()	# 主消息循环

# GUI程序的主线程负责监听来自操作系统的消息，并依次处理每一条消息。因此，如果消息处理非常耗时，就需要在新线程中处理

# 点击“Quit”按钮或者窗口的“x”结束程序
# input('pause')


# 输入文本
# 再对这个GUI程序改进一下，加入一个文本框，让用户可以输入文本，然后点按钮后，弹出消息对话框
from Tkinter import *
# import Tkinter.messagebox as messagebox
import tkMessageBox as messagebox

class Application2(Frame):
	def __init__(self, master = None):
		Frame.__init__(self, master)
		self.pack()
		self.createWidgets()
		
	def createWidgets(self):
		self.nameInput = Entry(self)
		self.nameInput.pack()
		self.alertButton = Button(self, text = 'Hello', command = self.hello)
		self.alertButton.pack()
		
	def hello(self):
		name = self.nameInput.get() or 'world'
		messagebox.showinfo('Message', 'Hello, %s' % name)
		
app2 = Application2()
app2.master.title('Hello World')
app.mainloop()

# 当用户点击按钮时，触发hello()，通过self.nameInput.get()获得用户输入的文本后，使用tkMessageBox.showinfo()可以弹出消息对话框。

## Python内置的Tkinter可以满足基本的GUI程序的要求，如果是非常复杂的GUI程序，建议用操作系统原生支持的语言和库来编写

	