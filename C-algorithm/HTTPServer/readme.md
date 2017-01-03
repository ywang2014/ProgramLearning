# socket编程学习
socket编程，和操作系统关联较大，一般Linux(windows)平台下的编程实现，不能直接移植到windows(Linux)平台上运行。
因此，我们拿来主义使用别人的代码时，常常编译都不通过，这个时候，我们就应该看看我们编译和运行环境，是不是和别人的环境一模一样。如果不同，我们应该首先考虑不同环境的兼容性问题，而不是怀疑人家代码有问题；如果完全一样，很幸运，又遇见了遍地都是的fucking code！--- Do it yourself, please!

1.头文件的不同：
	
	windows平台上使用：#include <ws2tcpip.h>
	Linux平台上使用：#include <sys/socket.h>
	
2.windows平台使用winsocket API，需要加载静态库，Linux下不需要这么复杂的工作

	 #pragma comment(lib,"ws2_32.lib")
	
3.windows平台上需要初始化，Linux下不需要任何初始化工作

	WSAStartup(MAKEWORD(2, 2), &wsaData)
	
4.其他还有一些不同，但是VS2013版基本可以兼容windows和linux的区别

	1.比如关闭socket资源，都可以使用close()，但是windows下，没有头文件unistd.h
		1.自己写一个unistd.h头文件：
			#ifndef _UNISTD_H
			#define _UNISTD_H
			#include <io.h>
			#include <process.h>
			#endif
		2.直接使用头文件：#include <io.h>
		错误：windows平台下使用close()，会使得程序直接崩溃掉，也即程序只能运行一次，while没有作用！
	Linux下关闭socket，使用close()，windows下使用closesocket()
	
	2.一些类型别名的区别，typedef
	3.有些结构体的实现也不同
	4...
	
## Socket基础知识
(优秀博客)[http://blog.csdn.net/ithzhang/article/details/8448655]
	
## (HttpServer)[./http_server]
HTTP服务器，一个运行在主机上的程序。
程序启动了之后，会一直在等待客户端(任意客户端)的请求，接收到请求之后，处理请求，然后发送响应给客户端。
客户端和服务器之间使用HTTP协议进行通信，所有遵循HTTP协议的程序都可以作为客户端。

#### 编译--运行--测试
1.监听9001端口，可以使用netstat命令查看
	
	netstat -anp | grep '9001'
	
2.用浏览器直接访问http://localhost:9001，即客户端向服务器发送请求。

3.使用telnet去模拟HTTP请求

	telnet localhost 9001 
	
[来源](http://www.codeceo.com/article/make-simple-http-server.html)

## (ServerClient)[./server_client]
	服务器程序					客户端程序
	1.创建socket				1.创建socket
	2.地址赋值					2.地址赋值	
	3.bind()绑定			
	4.listen()监听			
	5.accept()等待请求			3.conncet()建立连接
	6.send()或recv()数据传输	4.send()或recv()数据传输
	7.close()					5.close()
