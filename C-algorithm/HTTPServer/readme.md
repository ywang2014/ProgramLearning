# 简易的HTTP服务器
#### HTTP 服务器
HTTP服务器，就是一个运行在主机上的程序。程序启动了之后，会一直在等待其他所有客户端的请求，接收到请求之后，处理请求，然后发送响应给客户端。客户端和服务器之间使用HTTP协议进行通信，所有遵循HTTP协议的程序都可以作为客户端。

#### 编译--运行--测试
1.监听9001端口，可以使用netstat命令查看

2.用浏览器直接访问http://localhost:9001

3.使用telnet去模拟HTTP请求

	telnet localhost 9001 
	
[来源](http://www.codeceo.com/article/make-simple-http-server.html)