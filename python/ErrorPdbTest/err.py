# -*- coding: utf-8 -*-

# 错误处理：Python内置了一套异常处理机制，来帮助我们进行错误处理

# 调试: Python的pdb可以让我们以单步方式执行代码。

# 测试：编写测试也很重要，可以在程序修改后反复运行，确保程序输出符合我们编写的测试

# 错误处理：高级语言通常都内置了一套try...except...finally...的错误处理机制

	# 除零错误
try:
	print('try begin...')
	r = 1 / 0		#division by zero
	print('result:', r)
except ZeroDivisionError as e:
	print('except: ', e)
finally:
	print('finally...')
print('END')

# 当我们认为某些代码可能会出错时，就可以用try来运行这段代码，如果执行出错，则后续代码不会继续执行，而是直接
# 跳转至错误处理代码，即except语句块，执行完except后，如果有finally语句块，则执行finally语句块，至此，执行完毕。
## 和java一样

# int()函数可能会抛出ValueError
# 可以在except语句块后面加一个else，当没有错误发生时，会自动执行else语句：
try:
    print('try...')
    r = 10 / int('2')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
else:
    print('no error!')
finally:
    print('finally...')
print('END')

# Python所有的错误都是从BaseException类派生的，常见的错误类型和继承关系看这里：
# https://docs.python.org/3/library/exceptions.html#exception-hierarchy

# 使用try...except捕获错误还有一个巨大的好处，就是可以跨越多层调用
# 不需要在每个可能出错的地方去捕获错误，只要在合适的层次去捕获错误就可以了

# Python内置的logging模块可以非常容易地记录错误信息：

# err_logging.py
import logging
def foo(s):
    return 10 / int(s)

def bar(s):
    return foo(s) * 2

def main():
    try:
        bar('0')
    except Exception as e:
        logging.exception(e)

main()
print('END')

# 通过配置，logging还可以把错误记录到日志文件里，方便事后排查

# 抛出错误
	# 如果要抛出错误，首先根据需要，可以定义一个错误的class，选择好继承关系，然后，用raise语句抛出一个错误的实例：
# err_raise.py
class FooError(ValueError):
    pass

def foo(s):
    n = int(s)
    if n==0:
        raise FooError('invalid value: %s' % s)
    return 10 / n

foo('0')

# 只有在必要的时候才定义我们自己的错误类型。如果可以选择Python已有的内置的错误类型（比如ValueError，TypeError），尽量使用Python内置的错误类型。

# err_reraise.py

def foo(s):
    n = int(s)
    if n==0:
        raise ValueError('invalid value: %s' % s)
    return 10 / n

def bar():
    try:
        foo('0')
    except ValueError as e:
        print('ValueError!')
        raise	# 处理错误后，继续上抛？？？

bar()

# 捕获错误目的只是记录一下，便于后续追踪
	# 由于当前函数不知道应该怎么处理该错误，所以，最恰当的方式是继续往上抛，让顶层调用者去处理
	# raise语句如果不带参数，就会把当前错误原样抛出
	# 在except中raise一个Error，还可以把一种类型的错误转化成另一种类型：
	# 转换逻辑需要合理，否则造成混乱
	
## 应该在文档中写清楚可能会抛出哪些错误，以及错误产生的原因。