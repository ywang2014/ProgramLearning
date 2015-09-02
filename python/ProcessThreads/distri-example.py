# -*- coding:utf-8 -*-

# @version: 1.0
# @author: ZhangZhipeng
# @date: 2015-08-03

"""
自己稍微写了一下，linux/win7运行通过。个人建议分成四个部分

Server: 服务端, 数据中转
Server-Producer: 生产者,发送任务给Server
Server-Consumer: 消费者,处理Server收到Client的结果
Client: 客户端, 消费者处理任务

(没有想到好的类名，暂且这么表示吧)

下面是示例，Server和Master命名意义冲突，自行定义。
"""

import sys
import Queue
import random

from multiprocessing.managers import BaseManager
from multiprocessing import freeze_support


SERVER_IP = '127.0.0.1'
SERVER_PROT = 9010


class ServerManager(BaseManager):
    pass


class Server(object):

    """服务端
    由于: 1.manager.start()后，client连接不上；
         2. serve_forver()之前无法获取[结果队列]，函数是循环函数(好像是阻塞进程)，无法继续函数后代码
    因此: 有一个类Master，用于获取[结果]。

    建议：本类只作为服务端中转。 另建生产者，用于解耦。(put_data()生产数据)
    """

    def __init__(self, task_queue=None, result_queue=None):
        if not task_queue:
            task_queue = Queue.Queue()
        if not result_queue:
            result_queue = Queue.Queue()
        self.__task_queue = task_queue
        self.__result_queue = result_queue

        # 因为本类有充当了生产者，因此，不建议使用lambda
        ServerManager.register("get_task_queue", callable=self._task_queue)
        #ServerManager.register("get_result_queue", callable=self._result_queue)

        #ServerManager.register("get_task_queue", callable=lambda:task_queue)
        ServerManager.register(
            "get_result_queue", callable=lambda: result_queue)

        self._server_manager = ServerManager(
            address=(SERVER_IP, SERVER_PROT), authkey=b'z')

    def start(self):
        print ("Server: Start.")
        server_manager = self._server_manager.get_server()
        # start() 在linux 上也有问题.
        # self._server_manager.start()
        self._put_data()
        server_manager.serve_forever()
        print ("Server: End.")

    def _put_data(self):
        for i in ["张志鹏", "罗静静"]:
            print ("Server: Put:%s" % i)
            self._task_queue().put(i)

    def _task_queue(self):
        return self.__task_queue

    # def _result_queue(self):
    #    return self.__result_queue


class Master(object):

    """服务端：创建Master类的原因见Server
    此处仅作用于获取客户端发送至服务端的[结果]，还可以当作生产者或者另建类.
    """

    def __init__(self):
        ServerManager.register("get_result_queue")
        self._server_manager = ServerManager(
            address=(SERVER_IP, SERVER_PROT), authkey=b'z')

    def start(self):
        print("Server Master: Start.") 
        self._server_manager.connect()
        self._get_result()

    @property
    def task_queue(self):
        return self._server_manager.get_task_queue()

    @property
    def result_queue(self):
        return self._server_manager.get_result_queue()

    def _get_result(self):
        print("Server Master: Try Get Result...")
        while not self.result_queue.empty():
            name = self.result_queue.get(timeout=10)
            print("Server Master: Get: %s" % name) 


class Client(object):

    """客户端:处理任务"""

    def __init__(self):
        ServerManager.register("get_task_queue")
        ServerManager.register("get_result_queue")
        self._server_manager = ServerManager(
            address=(SERVER_IP, SERVER_PROT), authkey=b'z')

    def start(self):
        print("Client: Start.")
        self._server_manager.connect()
        task_queue = self.task_queue
        result_queue = self.result_queue
        while not task_queue.empty():
            name = task_queue.get(timeout=1)
            print("Client: Get: %s" % name) 
            user = {"name": name, "age": random.randint(20, 26)}
            print("Client: Set: %s" % user) 
            result_queue.put(user)

    @property
    def task_queue(self):
        return self._server_manager.get_task_queue()

    @property
    def result_queue(self):
        return self._server_manager.get_result_queue()


if __name__ == "__main__":
    freeze_support()
    argv = sys.argv
    argv.append("-")

    def has_in_argv(keys):
        if type(keys) in [unicode or str]:
            return True if keys in argv else False
        for key in keys:
            if key in argv:
                return True
            return False

    if has_in_argv(["-t", "--client", "client"]):
        Client().start()
    elif has_in_argv(["-m", "--matser", "master"]):
        Master().start()
    else:
        Server().start()