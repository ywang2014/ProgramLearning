# -*- coding: utf-8 -*-

# virtualenv
	# 系统安装的Python3只有一个版本：3.4。所有第三方的包都会被pip安装到Python3的site-packages目录下
	# 如果我们要同时开发多个应用程序，那这些应用程序都会共用一个Python，就是安装在系统的Python 3
	# 如果应用A需要jinja 2.7，而应用B需要jinja 2.6，每个应用可能需要各自拥有一套“独立”的Python运行环境
	# virtualenv就是用来为一个应用创建一套“隔离”的Python运行环境
	
	#  pip3 install virtualenv
	
	
	#第一步，创建目录：

		mkdir myproject
		cd myproject/

	#第二步，创建一个独立的Python运行环境，命名为venv：

		virtualenv --no-site-packages venv
		# Using base prefix '/usr/local/.../Python.framework/Versions/3.4' New python executable in venv/bin/python3.4
		# Also creating executable in venv/bin/python Installing setuptools, pip, wheel...done.

# 命令virtualenv就可以创建一个独立的Python运行环境
# 加上了参数--no-site-packages，这样，已经安装到系统Python环境中的所有第三方包都不会复制过来
# 就得到了一个不带任何第三方包的“干净”的Python运行环境

# 新建的Python环境被放到当前目录下的venv目录。有了venv这个Python环境，可以用source进入该环境：
	source venv/bin/activate
	
	# 下面正常安装各种第三方包，并运行python命令：

		pip install jinja2	# 安装
		python myapp.py		# 运行

# 在venv环境下，用pip安装的包都被安装到venv这个环境下，系统Python环境不受任何影响。venv环境是专门针对myproject这个应用创建的。

# 退出当前的venv环境，使用deactivate命令：
deactivate	# 此时就回到了正常的环境，现在pip或python均是在系统Python环境下执行

# 完全可以针对每个应用创建独立的Python运行环境，这样就可以对每个应用的Python环境进行隔离

## virtualenv 原理
## 把系统Python复制一份到virtualenv的环境，用命令source venv/bin/activate进入一个virtualenv环境时，virtualenv会修改相关环境变量，让命令python和pip均指向当前的virtualenv环境
	# virtualenv为应用提供了隔离的Python运行环境，解决了不同应用间多版本的冲突问题
