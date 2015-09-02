'''
# -*- coding: utf-8 -*-

import random, time, queue
from multiprocessing.managers import BaseManager

## create queue
# queue for posting task
task_queue = queue.Queue()
# queue for receiving result
result_queue = queue.Queue()

# QueueManager inherit from BaseManager
class QueueManager(BaseManager):
	pass

# register the queues to network, argument callable refer to object queue
#QueueManager.register('get_task_queue', callable = lambda: task_queue)
#QueueManager.register('get_result_queue', callable = lambda: result_queue)
QueueManager.register('get_task_queue', callable = task_queue)
QueueManager.register('get_result_queue', callable = result_queue)

# bound the port 5000, set the auth code 'abc'
manager = QueueManager(address = ('', 5000), authkey = b'abc')

# start queue
manager.start()

# get the object queue of network access
task = manager.get_task_queue()
result = manager.get_result_queue()

# put into tasks
for i in range(10):
	n = random.randint(0, 10000)
	print('put task %d...' %n)
	task.put(n)
	
# get result from result queue
print('try get results...')
for i in range(10):
	r = result.get(timeout = 10)
	print('result: %s' % r)

# close
manager.shutdown()
print('master exit.')
'''

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random, time, queue
from multiprocessing import freeze_support
from multiprocessing.managers import BaseManager

# 发送任务的队列:
task_queue = queue.Queue()
# 接收结果的队列:
result_queue = queue.Queue()

# 从BaseManager继承的QueueManager:
class QueueManager(BaseManager):
    pass

def return_task_queue():
    global task_queue
    return task_queue

def return_result_queue():
    global result_queue
    return result_queue

def test():
    # 把两个Queue都注册到网络上, callable参数关联了Queue对象:
    # QueueManager.register('get_task_queue', callable=lambda: task_queue)
    # QueueManager.register('get_result_queue', callable=lambda: result_queue)
    QueueManager.register('get_task_queue', callable=return_task_queue)
    QueueManager.register('get_result_queue', callable=return_result_queue)

    # 绑定端口5000, 设置验证码'abc':
    manager = QueueManager(address=('127.0.0.1', 5000), authkey=b'abc')
    # 启动Queue:
    manager.start()
    # 获得通过网络访问的Queue对象:
    task = manager.get_task_queue()
    result = manager.get_result_queue()
    # 放几个任务进去:
    for i in range(10):
        n = random.randint(0, 10000)
        print('Put task %d...' % n)
        task.put(n)
    # 从result队列读取结果:
    print('Try get results...')
    for i in range(10):
        r = result.get(timeout=10)
        print('Result: %s' % r)
    # 关闭:
    manager.shutdown()
    print('master exit.')

if __name__ == '__main__':
    freeze_support()
    test()
