# -*- coding: utf-8 -*-

# 模块(module)
	# 一个.py文件就称之为一个模块（Module）
	
	# 按目录来组织模块的方法，称为包（Package），通过包来组织模块，避免冲突
	# 模块名：catalog.filename
	# 请注意，每一个包目录下面都会有一个__init__.py的文件，这个文件是必须存在的，否则，Python就把这个目录当成普
	# 通目录，而不是一个包。__init__.py可以是空文件，也可以有Python代码，因为__init__.py本身就是一个模块，
	# 而它的模块名就是目录名
	
	# 可以有多级目录，组成多级层次的包结构: 
		# 模块名: abc.xyz.a1
		
# Python本身就内置了很多非常有用的模块
	# 以内建的sys模块为例，编写一个hello的模块：
	
#!/usr/bin/env python3		# 让这个hello.py文件直接在Unix/Linux/Mac上运行
# -*- coding: utf-8 -*-		# 表示.py文件本身使用标准UTF-8编码

'a test module'				# 一个字符串，表示模块的文档注释，任何模块代码的第一个字符串都被视为模块的文档注释

__author__ = 'Mr Wang'		# 使用__author__变量把作者写进去，这样当你公开源代码后别人就可以瞻仰你的大名
# 以上就是Python模块的标准文件模板，当然也可以全部删掉不写，但是，按标准办事肯定没错

import sys		# 导入sys模块：
# 导入sys模块后，我们就有了变量sys指向该模块，利用sys这个变量，就可以访问sys模块的所有功能
# sys模块有一个argv变量，用list存储了命令行的所有参数。argv至少有一个元素，因为第一个参数永远是该.py文件的名称
# 例如：运行python3 hello.py获得的sys.argv就是['hello.py']
#		运行python3 hello.py Michael获得的sys.argv就是['hello.py', 'Michael]

def test():
	args = sys.argv
	if len(args) == 1:
		print('Hello world!')
	elif len(args) == 2:
		print('Hello %s!' % args[1])
	else:
		print('Too many arguments!')
		
if __name__ == '__main__':
	test()
	
# 在命令行运行hello模块文件时，Python解释器把一个特殊变量__name__置为__main__，而如果在其他地方导入该hello模块时，if判断将失败
# 这种if测试可以让一个模块通过命令行运行时执行一些额外的代码，最常见的就是运行测试


## 作用域
	# 在Python中，是通过_前缀来实现的函数和变量的访问权限
	# 正常的函数和变量名是公开的（public），可以被直接引用，比如：abc，x123，PI等
	# 类似__xxx__这样的变量是特殊变量，可以被直接引用，但是有特殊用途，比如上面的__author__，
	# __name__就是特殊变量，hello模块定义的文档注释也可以用特殊变量__doc__访问
	# 类似_xxx和__xxx这样的函数或变量就是非公开的（private），不应该（不是不能）被直接引用，比如_abc，__abc等
	# Python并没有一种方法可以完全限制访问private函数或变量，但是，从编程习惯上不应该引用private函数或变量
	
	# private 实现： 代码封装和抽象的方法
		# 外部不需要引用的函数全部定义成private，只有外部需要引用的函数才定义为public
		
		
# 安装第三方模块
	# 在Python中，安装第三方模块，是通过包管理工具pip完成的
	
	# Python Imaging Library，这是Python下非常强大的处理图像的工具库，不支持python3，支持2.7
	# 库一般在python官方网站 ：pypi.python.org
	# Pillow支持python3 	安装命令：pip install Pillow
	
# 有了Pillow，处理图片易如反掌。随便找个图片生成缩略图：
from PIL import Image
im = Image.open('test.png')
print(im.format, im.size, im.mode)
im.thumbnail((200, 100))
im.save('thumb.jpg', 'JPEG')

# MySQL的驱动：mysql-connector-python
# 用于科学计算的NumPy库：numpy
# 用于生成文本的模板工具Jinja2

# 模块搜索路径
	# 加载一个模块时，Python会在指定的路径下搜索对应的.py文件，如果找不到，就会报错：
	# 默认情况下，Python解释器会搜索当前目录、所有已安装的内置模块和第三方模块，搜索路径存放在sys模块的path变量中：
	import sys
	sys.path
	# 如果我们要添加自己的搜索目录，有两种方法：
		# 一 是直接修改sys.path，添加要搜索的目录：
		import sys
		sys.path.append('/User/python/my_py')
		# 这种方法是在运行时修改，运行结束后失效。
		
		# 二 是设置环境变量PYTHONPATH，该环境变量的内容会被自动添加到模块搜索路径中。设置方式与设置Path环境变量类似。
		# 注意：只需要添加你自己的搜索路径，Python自己本身的搜索路径不受影响。