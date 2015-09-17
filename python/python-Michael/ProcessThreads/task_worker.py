# -*- coding: utf-8 -*-

import time, sys, queue
from multiprocessing.managers import BaseManager

class QueueManager(BaseManager):
	pass
	
# you only need to offer a name for register, because QueueManager is only to get queue from the network
QueueManager.register('get_task_queue')
QueueManager.register('get_result_queue')

# link to the server
server_addr = '127.0.0.1'
print('Connect to server %s...' % server_addr)

# port and auth code 
m = QueueManager(address = (server_addr, 5000), authkey = b'abc')

# link from the network
m.connect()

# get object queue
task = m.get_task_queue()
result = m.get_task_queue()

# get task from task queue, and write the result into result queue
for i in range(10):
	try:
		n = task.get(timeout = 1)
		print('run task %d * %d...' % (n, n))
		r = '%d * %d = %d' % (n, n, n*n)
		time.sleep(1)
		result.put(r)
	except Queue.Empty:
		print('task queue is empty.')
	
# end of work
print('worker exit.')


# cmd /k C:\Python30\python.exe "$(FULL_CURRENT_PATH)" & PAUSE & EXIT
# $(FULL_CURRENT_PATH) 的含义是当前文件的完整路径: "C:\Users\Administrator.USER-20150308ZA\ProgramLearning\python\ProcessThreads\task_worker.py"
# cmd /k 的含义是执行后面的命令，并且执行完毕后保留窗口。& 是连接多条命令。PAUSE 表示运行结束后暂停，等待一个任意按键。EXIT 表示关闭命令行窗口。如果使用 cmd /c 就可以省掉 EXIT 了
