# -*- coding: utf-8 -*-

# 调试
	# 1.简单粗暴：print()把可能有问题的变量打印出来
def fn(s):
	n = int(s)
	print('>>> n = %d' % n)
	return 10 / n
	
def main():
	fn('0')
	
main()
# 用print()最大的坏处是将来还得删掉它，想想程序里到处都是print()，运行结果也会包含很多垃圾信息

	# 2.断言(assert)
	# 用断言(assert)替代print()辅助查看的地方
def fn(s):
	n = int(s)
	assert n != 0, 'n is zero!'
	return 10 / n
	
def main():
	fn('0')
	
# assert的意思是，表达式n != 0应该是True，否则，根据程序运行的逻辑，后面的代码肯定会出错
# 如果断言失败，assert语句本身抛出异常AssertionError

# 启动Python解释器时可以用-O参数来关闭assert：把所有的assert语句当成pass来看
$ python3 -O err.py  # 调用方法

	# 3.logging
	# 把print()替换为logging，logging不会抛出错误，而且可以输出到文件
import logging
logging.basicConfig(level = logging.INFO)	# 配置后，才有具体错误信息
s = '0'
n = int(s)
logging.info('n = %d' % n)
print(10 / n)

# logging.info()就可以输出一段文本
# logging 记录信息的级别: debug，info，warning，error等
# 指定level=INFO时，logging.debug就不起作用了。同理，指定level=WARNING后，debug和info就不起作用
# logging的另一个好处是通过简单的配置，一条语句可以同时输出到不同的地方，比如console和文件

	# 4.pdb ：Python的调试器pdb，让程序以单步方式运行，可以随时查看运行状态
# debug.py
s = '0'
n = int(s)
print(10 / n)

$python3 -m pdb pdbmanule.py	# 启动调试

# 以参数-m pdb启动后，pdb定位到下一步要执行的代码-> s = '0'
# 命令l : 查看代码
# 命令n : 单步执行代码
# 命令 p + 变量名 : 来查看变量
# 命令q : 结束调试，退出程序
# 命令c ：继续执行

	# 5.pdb.set_trace()
	# 不需要单步执行，只需要import pdb，然后，在可能出错的地方放一个pdb.set_trace()，就可以设置一个断点：
# debug.py
import pdb

s = '0'
n = int(s)
pdb.set_trace()	# 运行到此处，会自动暂停
print(10 / n)
# 运行代码，程序会自动在pdb.set_trace()暂停并进入pdb调试环境，可以用命令p查看变量，或者用命令c继续运行：

	# 6.IDE
	# 图形界面比较容易设置断点、单步执行等操作  PyCharm
	
## 虽然用IDE调试起来比较方便，logging才是终极武器