# -*- coding: utf-8 -*-

# 协程
	# 协程，又称微线程，纤程。英文名Coroutine
	# 子程序，或者称为函数，在所有语言中都是层级调用，比如A调用B，B在执行过程中又调用了C，C执行完毕返回，B执行完毕返回，最后是A执行完毕
		# 所以子程序调用是通过栈实现的，一个线程就是执行一个子程序
		# 子程序调用总是一个入口，一次返回，调用顺序是明确的。而协程的调用和子程序不同
	# 协程看上去也是子程序，但执行过程中，在子程序内部可中断，然后转而执行别的子程序，在适当的时候再返回来接着执行
		# 在一个子程序中中断，去执行其他子程序，不是函数调用，有点类似CPU的中断。比如子程序A、B：

def funa():
	print('1')
	print('2')
	print('3')
	
def funb():
	print('x')
	print('y')
	print('z')
	
# 假设由协程执行，在执行A的过程中，可以随时中断，去执行B，B也可能在执行过程中中断再去执行A，结果可能是：
# 1\n 2\n x\n y\n 3\n z	(交叉的！)

# 但是在A中是没有调用B的，所以协程的调用比函数调用理解起来要难一些
# 看起来A、B的执行有点像多线程，但协程的特点在于是一个线程执行
	#协程的优点：
		# 协程极高的执行效率
			# 子程序切换不是线程切换，而是由程序自身控制，因此，没有线程切换的开销，和多线程比，线程数量越多，协程的性能优势就越明显。
		# 不需要多线程的锁机制
			# 只有一个线程，也不存在同时写变量冲突，在协程中控制共享资源不加锁，只需要判断状态就好了，所以执行效率比多线程高很多。
		# 利用多核CPU：多进程+协程，既充分利用多核，又充分发挥协程的高效率，可获得极高的性能。
		
# Python对协程的支持是通过generator实现的
	# 在generator中，我们不但可以通过for循环来迭代，还可以不断调用next()函数获取由yield语句返回的下一个值
	# 但是Python的yield不但可以返回一个值，它还可以接收调用者发出的参数。
	
# 传统的生产者-消费者模型是一个线程写消息，一个线程取消息，通过锁机制控制队列和等待，但一不小心就可能死锁
# 如果改用协程，生产者生产消息后，直接通过yield跳转到消费者开始执行，待消费者执行完毕后，切换回生产者继续生产，效率极高：
def consumer():
	r = ''
	while True:
		n = yield r
		if not n:
			return None
		print('[CONSUMER] Consuming %s...' % n)
		r = '200 OK'

def produce(c):
	c.send(None)
	n = 0
	while n < 5:
		n = n`+ 1
		print('[PRODUCER] Producing %s...' % n)
		r = c.send(n)
		print('[PRODUCER] Consumer return: %s' % r)
	c.close()
	
c = consumer()
produce(c)
			
# 注意到consumer函数是一个generator，把一个consumer传入produce后：
	# 首先调用c.send(None)启动生成器；
	# 然后，一旦生产了东西，通过c.send(n)切换到consumer执行
	# consumer通过yield拿到消息，处理，又通过yield把结果传回；
	# produce拿到consumer处理的结果，继续生产下一条消息；
	# produce决定不生产了，通过c.close()关闭consumer，整个过程结束

# 整个流程无锁，由一个线程执行，produce和consumer协作完成任务，所以称为“协程”，而非线程的抢占式多任务
## 子程序就是协程的一种特例.


#####################################################
# send的意义是： 让generator也就是consumer继续执行，并使generator当前yield的结果变成send括号内的值也就是1
# 然后r=c.send(1)的意思是把生成器下次yield的结果赋值给r
# yield的结果就从原来的空值变成1了，所以这时consumer就不会执行if not n后面的return，转而执行打印[CONSUMER] Consuming 1...语句并将 '200 OK'赋值给r了。
	#并返回(返回函数最后一行语句的值！不是如此理解的，因为yield r, 所以r作为返回值。)

# generator.send(value):
	# 使generator继续执行并将括号内值传入generator。使得generator本次yield的结果变为括号内的值；
	# generator.send(value)本身返回generator下次yield的值，若genertor下次不再yield结果则抛出StopIteration；
	# 若本方法是用来启动generator，则value必须为None
	
	
# Python的yield不但可以返回一个值，它还可以接收调用者发出的参数
	# yield r返回r到produce，然后在produce函数中r=c.send(n)，将n值作为(yield r)的返回值赋给了consumer的n，即接受了调用者produce发出的参数

首先调用c.send(None)会启动generator是没错的，但是在这第一次调用generator的时候，consumer只执行到“n = yield r”就返回到produce了，请注意：“n = yield r”实际上是分两步运行的：第一步，运行表达式“yield r”，第二步，把第一步的表达式的结果赋值给n，但由于第一步是yield，所以在第一步就返回到调用者了，第二步没有执行，被挂起了，这个挂起点后面要用到。

表达式“yield r”对调用者produce的效果是返回了“r”，这样produce中的“c.send(None)”获取的返回值是空串，这个返回值在produce中被丢弃了（没有使用）。

我们注意到在这个过程当中，“n = yield r”都没有执行完，因而consumer中的“if not n: return”语句也并没有被执行。

接下来，produce中执行到了“r = c.send(1)”。这个语句的效果是让consumer从上次的挂起点（也就是“n = yield r”执行的第二步）继续执行：通过send函数把“yield r”这个表达式的结果置为传入的参数1，然后继续执行第一段中所述的第二步，这时，“n = yield r”的执行结果就是n=1。

后面就在一直重复了，直到n=5。

在这个例子中，consumer的“if not n: return”语句一直都没有被调用过，如果我们把“if not n: return”语句改为“if not n: print('return called');return”再执行，可以看到’return called‘并没有被打印出来。

# n=yield r 这里也可以把r去掉,没有什么实质作用, 只是给调用方一个返回值而已.

###################################
def consumer():
    # 一旦外部调用send(None)方法，就会执行此函数，遇到第一个yield就会停止
    r = 'Waiting for food...'

    while True:
        # 第一次遇到yield的时候，r被初始化为"waiting for food..."，此时r被传出。
        # 但是导致第一次yield执行的send传入值(None)并没有机会接收到。此处的n等着下一次被send方法传入
        n = yield r
        if n:
            print('[CONSUMER] Consuming %s...' % n)
            r = 'Consumed'
        else:
            print 'None' #此案例中，这句永远不会被执行到，因为外部的send(None）是启动时传入的，此函数内部并没有任何机会接收它

def produce(c):

    # 启动协程。此处Python规定只能传入None，原因是协程刚刚启动，而传入值只能在某次yield被调用之后才可以使用
    r = c.send(None)

    #此处应收到传出的"waiting for food..."
    print('[PRODUCER] Consumer return: %s' % r)

    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCER] Producing %s...' % n)
        r = c.send(n)
        print('[PRODUCER] Consumer return: %s' % r)
    c.close()

c = consumer()
produce(c)