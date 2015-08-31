# -*- coding: utf-8 -*-


# 操作文件和目录
	# 在命令行下面输入操作系统提供的各种命令,比如dir、cp等命令可实现
	# 操作系统提供的命令只是简单地调用了操作系统提供的接口函数
	# Python内置的os模块也可以直接调用操作系统提供的接口函数
	
import os
os.name		# 操作系统类型：posix(Lniux, Unix, Mac OS X), nt(Windows)
os.uname()	# 获取详细的系统信息
	# 注意uname()函数在Windows上不提供，也就是说，os模块的某些函数是跟操作系统相关的
	
	
# 环境变量
	# 在操作系统中定义的环境变量，全部保存在os.environ这个变量中，可以直接查看：
os.environ
# 要获取某个环境变量的值，可以调用os.environ.get('key')：
os.environ.get('PATH')
os.environ.get('x', 'default')


# 操作文件和目录
	# 操作文件和目录的函数一部分放在os模块中，一部分放在os.path模块中
os.path.abspath('.')	# 查看当前目录的绝对路径
os.path.join('/user/test', 'testdir')	# # 在某个目录下创建一个新目录，首先把新目录的完整路径表示出来:
os.mkdir('/user/test/testdir')	# 创建一个目录
os.rmdir('/user/test/testdir')	# 删除一个目录

# 把两个路径合成一个时，不要直接拼字符串，而要通过os.path.join()函数，这样可以正确处理不同操作系统的路径分隔符
	# 在Linux/Unix/Mac下，os.path.join()返回这样的字符串：part-1/part-2
	# Windows下会返回这样的字符串：part-1\part-2
	
# 要拆分路径时，也不要直接去拆字符串，而要通过os.path.split()函数
# 这样可以把一个路径拆分为两部分，后一部分总是最后级别的目录或文件名：
os.path.split('/user/test/testdir/file.txt')	# ('/user/test/testdir', 'file.txt')

# os.path.splitext()可以直接让你得到文件扩展名，很多时候非常方便：
os.path.splitext('/path/to/file.txt')	# ('/path/to/file', 'txt')

## 这些合并、拆分路径的函数并不要求目录和文件要真实存在，它们只对字符串进行操作。

# 文件操作使用下面的函数。假定当前目录下有一个test.txt文件：
os.rename('test.txt', 'test.py')	# 对文件重命名
os.remove('test.py')	# 删除文件

# shutil模块提供了copyfile()的函数，你还可以在shutil模块中找到很多实用函数

# 列出当前目录下的所有目录
[x for x in os.listdir('.') if os.path.isdir(x)]

# 要列出所有的.py文件
[x for x in os.listdir('.') if os.path.isfile(x) and os.path.splitext(x)[1] == '.py']


# 练习
	# 1.利用os模块编写一个能实现dir -l输出的程序
import os
def Dir_l():
	[x for x in os.listdir('.')]
	
	# 2.编写一个程序，能在当前目录以及当前目录的所有子目录下查找文件名包含指定字符串的文件，并打印出相对路径
import os
def Findfilename(s, path = '.'):
	for x in os.listdir(path):
		if os.path.isdir(x):
			# path = os.path.join('.', x)
			# Findfilename(s, path)
			Findfilename(s, x)
		if os.path.isfile(x):
			if (s in os.path.splitext(x)[0]):
				print(os.path.join(path, os.path.splitext(x)[0]))
				# return True #找到一个就成功了。
		
		
# test
Findfilename('py')
# 只能查找第一层？？？？？？？？？？？

############## 网上代码
import os
def findfile(s, p = '.'):
	for x in os.listdir(p):
		if os.path.isdir(x):
			findfile(s, x)	# ?? x is path?
		elif os.path.isfile(os.path.join(p, x)): # ??为什么需要合并路径
			if s in os.path.splitext(x)[0]:
				print(os.path.join(p, x))
		else:
			print('error!')
			

			
			
	