# -*- coding: utf-8 -*-

# 多线程(Posix Thread)
	# 多任务可以由多进程完成，也可以由一个进程内的多线程完成
	# Python的标准库提供了两个模块：_thread和threading，_thread是低级模块，threading是高级模块，对_thread进行了封装
	
	# 启动一个线程就是把一个函数传入并创建Thread实例，然后调用start()开始执行：
	
import times, threading 
# 新线程执行的代码
def loop():
	print('thread %s is running...' % threading.current_thread().name)
	n = 0
	while n < 5:
		n = n + 1
		print('thread %s >>> %s' % (threading.current_thread().name, n))
		time.sleep(1)
	print('thread %s ended.' % threading.current_thread().name)
	
print('thread %s is running...' % threading.current_thread().name)
# 子线程的名字在创建时指定，我们用LoopThread命名子线程
t = threading.Thread(target = loop, name = 'LoopThread')
t.start()
t.join()
print('thread %s ended.' % threading.current_thread().name)
####################
thread MainThread is running...
thread LoopThread is running...
thread LoopThread >>> 1
thread LoopThread >>> 2
thread LoopThread >>> 3
thread LoopThread >>> 4
thread LoopThread >>> 5
thread LoopThread ended.
thread MainThread ended.

# 由于任何进程默认就会启动一个线程，我们把该线程称为主线程，主线程又可以启动新的线程
# Python的threading模块有个current_thread()函数，它永远返回当前线程的实例
# 主线程实例的名字叫MainThread，子线程的名字在创建时指定，我们用LoopThread命名子线程。


# Lock 
	# 多进程中，同一个变量，各自有一份拷贝存在于每个进程中，互不影响
	# 多线程中，所有变量都由所有线程共享，任何一个变量都可以被任何一个线程修改
	# 线程之间共享数据最大的危险在于多个线程同时改一个变量，把内容给改乱了
	
# 看看多个线程同时操作一个变量怎么把内容给改乱了：
import time, threading

# 假定这是银行存款
balance = 0		# 定义了一个共享变量balance，初始值为0

def change_it(n):
	# 先存款后取，结果为0
	global balance
	balabce = balance + n
	balance = balance - n
	
def run_thread(n):
	for i in range(10000):
		change_it(n)
		
t1 = threading.Thread(target = run_thread, args = (5, ))
t2 = threading.Thread(target = run_thread, args = (8, ))
t1.start()
t2.start()
# 启动两个线程，先存后取
t1.join()
t2.join()
print(balance)

# 由于线程的调度是由操作系统决定的，当t1、t2交替执行时，只要循环次数足够多，balance的结果就不一定是0了
# 原因:  高级语言的一条语句在CPU执行时是若干条语句
# 因为修改balance需要多条语句，而执行这几条语句时，线程可能中断，从而导致多个线程把同一个对象的内容改乱了
# 必须确保一个线程在修改balance的时候，别的线程一定不能改

# 确保balance计算正确，就要给change_it()上一把锁，当某个线程开始执行change_it()时
# 该线程因为获得了锁，因此其他线程不能同时执行change_it()，只能等待，直到锁被释放后，获得该锁以后才能改
# 由于锁只有一个，无论多少线程，同一时刻最多只有一个线程持有该锁，不会造成修改的冲突

balance = 0
lock = threading.Lock()

def run_thread(n):
	for i in range(10000):
		lock.acquire()		# 先获取锁：
		try:
			change_it(n)
		finally:
			lock.release()	# 释放所
# 当多个线程同时执行lock.acquire()时，只有一个线程能成功地获取锁，然后继续执行代码，其他线程就继续等待直到获得锁为止。
# 获得锁的线程用完后一定要释放锁，否则那些苦苦等待锁的线程将永远等待下去，成为死线程。所以我们用try...finally来确保锁一定会被释放
# 锁的好处就是确保了某段关键代码只能由一个线程从头到尾完整地执行，坏处当然也很多，首先是阻止了多线程并发执行
# 由于可以存在多个锁，不同的线程持有不同的锁，并试图获取对方持有的锁时，可能会造成死锁，导致多个线程全部挂起


# 多核CPU
	# 要想把N核CPU的核心全部跑满，就必须启动N个死循环线程
import threading, multiprocessing

def loop():
	x = 0
	while True:
		x = x ^ 1 
		
for i in range(multiprocessing.cpu_count()):
	t = threading.Thread(target = loop)
	t.start()
	
# 启动与CPU核心数量相同的N个线程，在4核CPU上可以监控到CPU占用率仅有102%
# 用C、C++或Java来改写相同的死循环，直接可以把全部核心跑满，4核就跑到400%，8核就跑到800%
# 因为Python的线程虽然是真正的线程，但解释器执行代码时，有一个GIL锁：
	# Global Interpreter Lock，任何Python线程执行前，必须先获得GIL锁
	# 每执行100条字节码，解释器就自动释放GIL锁，让别的线程有机会执行
	# 这个GIL全局锁实际上把所有线程的执行代码都给上了锁
	# 多线程在Python中只能交替执行，即使100个线程跑在100核CPU上，也只能用到1个核。
	# 如果一定要通过多线程利用多核，那只能通过C扩展来实现
	# python 可以通过多进程实现多核任务。多个Python进程有各自独立的GIL锁，互不影响
	