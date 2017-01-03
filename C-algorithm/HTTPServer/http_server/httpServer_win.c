/**
	windows平台下的socket编程：
		1.与Linux的区别：头文件不同
			#include <sys/socket.h>
			#include <unistd.h>
			上述2个头文件没有，使用替换方案：
			#include<ws2tcpip.h>
			#include <io.h>

			#pragma comment(lib,"ws2_32.lib")
		2.与Linux编程，区别较小，函数命名完全相同
			
	date: 2017-01-03
*/
#include <stdio.h>
#include <ws2tcpip.h>
#include <errno.h>

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)


/**
// 地址信息结构体
struct sockaddr_in
{
	short sin_family;			// 协议簇，使用TCP/IP协议的应用程序必须为AF_INET，来告诉系统使用IP地址家族
	u_short sin_port;			// 指定服务的端口号。1024--49151范围内的数据被作为服务端口号，可以由用户自定义
	struct in_addr sin_addr;	// ip地址
	char sin_zero[8];			// 填充字段，以便使得该结构与SOCKADDR结构长度相同
};

// 存储ip地址的结构体：ip地址存储，有三种表达方式
struct in_addr{
	union {
		// 第一种用四个字节来表示IP地址的四个数字；
		struct{
			u_char s_b1, s_b2, s_b3, s_b4;
		}S_un_b;
		
		// 第二种用两个双字节来表示IP地址；
		struct {
			u_short s_w1, s_w2;
		}S_un_w;
		
		// 第三种用一个长整型来表示IP地址
		u_long S_addr;
	}S_un;
};

给in_addr赋值的一种最简单方法是使用inet_addr函数，它可以把一个代表IP地址的字符串赋值转换为in_addr类型，如
	addrto.sin_addr.s_addr=inet_addr("192.168.0.2");
其反函数是inet_ntoa，可以把一个in_addr类型转换为一个字符串。
*/

/**
sockaddr类型是用来表示socket地址的类型，同上面的sockaddr_in类型相比，sockaddr的适用范围更广，因为sockaddr_in只适用于TCP/IP地址。
struct sockaddr{
	u_short sa_family;
	char  sa_data[14];
};
sockaddr有16个字节，而sockaddr_in也有16个字节，所以sockaddr_in是可以强制类型转换为sockaddr。
*/

/**
Htonl和htons函数实现主机字节顺序到网络字节序的转换功能。
	H代表host，主机
	N代表net
	L代表long
	S代表short。
	不要使用htonl转换short
从网络字节序到主机字节序的转换函数：ntohl和ntohs
*/

/**
	send() 和 recv()
	数据的传递是协议完成的，而不是send或recv函数，协议实现把socket缓冲区中的数据，
	从TCP一端传送到连接的另一端。
	send(): 把buf中的数据copy到socket的发送缓冲区里
	recv(): 把socket的接收缓冲区里的数据copy到buf中
*/


#define PORT 666
#define QUEUE_MAX_COUNT 5
#define BUFF_SIZE 1024

#define SERVER_STRING "Server: hoohackhttpd/0.1.0\r\n"


int main(){
	// 定义server和client的文件描述符
	int server_fd = -1;
	int client_fd = -1;

	u_short port = PORT;
	struct sockaddr_in client_addr;
	struct sockaddr_in server_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	char send_buf[BUFF_SIZE];
	char recv_buf[BUFF_SIZE];

	int lens = 0;
	int is_end = 0;
	int buf_len = 0;

	/*
		调用WSAStartup函数,这个函数是连接应用程序与winsock.dll的第一个调用.
			第一个参数是WINSOCK 版本号
			第二个参数是指向WSADATA的指针
			返回一个INT型值,通过检查这个值来确定初始化是否成功
			
		MAKEWORD(2,2)表示使用WINSOCK2版本
		wsaData用来存储系统传回的关于WINSOCK的资料
	*/
	WSADATA wsaData;
	int nRet;
	if ((nRet = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0){
		perror("Error: WSAStartup failed");
		exit(-1);
	}


	/*
		创建一个socket
		af表示使用协议的地址家族。创建TCP或UDP的套接字是使用AF_INET。
		type表示套接字的类型。有SOCK_STREAM、SOCK_DGRAM和SOCK_RAM三种类型。分别表示流、数据包、原始套接字。
		protocol，指示使用的协议。对于SOCK_STREAM套接字类型，该字段可以为IPPROTO_TCP或0。对于SOCK_DGRAM套接字类型，该字段为IPPROTO_UDP或0。
	*/
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == INVALID_SOCKET){
		printf("Error at socket(): %ld\n", WSAGetLastError());
	   	perror("Error: creating socket is failed!");
		exit(-1);
	}
	
	// 设置TCP/IP协议族，端口号，ip
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	/*
		绑定套接字到固定端口地址上
		int bind(SOCKET s, const struct sockaddr* name, int namelen);  
		s为要绑定的套接字，name为要绑定的地址。namelen为sockaddr长度。
		函数调用成功将返回0，否则返回值为SOCKET_ERROR。如果程序不关心分配给它的地址，可使用INADDR_ANY或将端口号设为0。
		端口号为0时，Windows SOCKET将给应用程序分配一个值在1024-5000之间唯一的端口号。

		在创建套接字之后就需要调用bind函数将其绑定到一个已知的地址上。
	*/
	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		perror("Error: binding is failed!");
		exit(-1);
	}

	/* 
		启动socket监听请求，开始等待客户端发来的请求
		listen函数将套接字设定为监听模式	int listen(SOCKET s, int backlog);  
		s为要设置监听模式的套接字，backlog指定等待连接的最大队列长度。
		当函数成功时返回0，否则返回SOCKET_ERROR。
		如果超出最大等待连接数目的服务器请求，则该请求连接将会发生WSAEWOULDBLOCK错误。
		当服务器接受了一个请求，就将该请求从请求队列中删去。
	*/
	if (listen(server_fd, QUEUE_MAX_COUNT) < 0){
		perror("Error: listening is failed!");
		exit(-1);
	}

	printf("Http server running on port %d\n", port);

	while (1){
		/*
			调用accept函数，阻塞程序，直到接收到客户端的请求

			accept函数接受客户端的一个连接请求		SOCKET accept(SOCKET s, struct sockaddr* addr, int *addrlen);  
				s为监听套接字,	addr返回客户端地址,	addrlen返回addr的长度。
				函数执行成功时：
					1：主机接受了等待队列的第一个请求。
					2：addr结构返回客户端地址。
					3：返回一个新的套接字句柄。服务器可以使用该套接字与客户端进行通信。而监听套接字仍用于接受客户端连接。
		*/
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
		if (client_fd < 0){
			perror("Error: accepting is failed!");
			exit(-1);
		}
		printf("Accept a client\n");
		printf("Client socket fd: %d\n", client_fd);
		
		while(is_end == 0){
			/*
				客户端和服务器端应用程序都用recv函数从TCP连接的另一端接收数据
				int recv( _In_ SOCKET s, _Out_ char *buf, _In_ int len, _In_ int flags);
				recv先等待连接的另一端的socket的发送缓冲区中的数据被协议传送完毕:
					如果协议在传送s的发送缓冲中的数据时出现网络错误，那么recv函数返回SOCKET_ERROR。
					如果s的发送缓冲中没有数据，或者数据被协议成功发送完毕后，recv先检查接收端socket的接收缓冲区：
						如果s接收缓冲区中没有数据或者协议正在接收数据，那么recv就一直等待，直到协议把数据接收完毕。
						当协议把数据接收完毕，recv函数就把s的接收缓冲区中的数据copy到buf中
						(注意协议接收到的数据可能大于buf的长度，在这种情况下要调用几次recv函数才能把数据copy完。
						 recv函数仅仅是copy数据，真正的接收数据是协议来完成的)
				如果成功copy数据，recv返回实际copy的字节数
				如果在copy时出错，那么返回SOCKET_ERROR；
				如果recv函数在等待协议接收数据时网络中断了，那么它返回0。
				如果远端中止连接，recv一个数据也不读取，立即返回，那么它返回0。
			*/
			// 调用recv函数接收客户端发来的请求信息
			buf_len = recv(client_fd, recv_buf, BUFF_SIZE, 0);
			if(buf_len < 0){
				if(errno == EAGAIN){	//	当前缓冲区已无数据可读
					break;
				}
				else{
					exit(-1);
				}
			}
			else if(buf_len == 0){	// 对端的socket已正常关闭
				break;
			}
			else if(buf_len != sizeof(recv_buf)){
				is_end = 1;	// 读取结束
			}
			else{
				is_end = 0;	// 读取未结束
			}
			lens += buf_len;
		}
		printf("Receive %d characters.\n", lens);
		
		/*
			发送响应给客户端时，发送的报文要遵循HTTP协议，HTTP的响应报文格式如下：
				<status-line>		HTTP/1.1 200 OK
				<headers>			Content-Type: text/html;charset=utf-8
				<blank line>		Content-Length: 122
				[<response-body>]	...
		*/

		/*
			不论是客户端还是服务器端应用程序都用send函数来向TCP连接的另一端发送数据。
			客户端程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
			int send( SOCKET s, const char FAR *buf, int len, int flags );  
			s 指定发送端套接字描述符；
			buf 指明一个存放应用程序要发送数据的缓冲区；
			len 指明实际要发送的数据的字节数；
			flags 一般置0。0对应阻塞，1对应非阻塞
			
			send先比较待发送数据的长度len和套接字s的发送缓冲的长度：
				如果len大于s的发送缓冲区的长度，该函数返回SOCKET_ERROR；
				如果len小于或者等于s的发送缓冲区的长度，那么send先检查协议是否正在发送s的发送缓冲中的数据，
					如果是，就等待协议把数据发送完，
					如果协议还没有开始发送 s的发送缓冲中的数据，或者s的发送缓冲中没有数据，那么send就比较s的发送缓冲区的剩余空间和len，
						如果len大于剩余空间大小，send就一直等待协议把s的发送缓冲中的数据发送完，
						如果len小于剩余空间大小，send就仅仅把buf中的数据copy到剩余空间里。
			(注意并不是send把s的发送缓冲中的数据传到连接的另一端的，而是协议传的，send仅仅是把buf中的数据copy到s的发送缓冲区的剩余空间里)
			如果send函数copy数据成功，就返回实际copy的字节数，
			如果send在copy数据时出现错误，那么send就返回SOCKET_ERROR；
			如果send在等待协议传送数据时网络断开的话，那么send函数也返回SOCKET_ERROR
		*/
		// 发送响应给客户端
		sprintf(send_buf, "HTTP/1.0 200 OK\r\n");
		send(client_fd, send_buf, strlen(send_buf), 0);
		strcpy(send_buf, SERVER_STRING);
		send(client_fd, send_buf, strlen(send_buf), 0);
		sprintf(send_buf, "Content-Type: text/html\r\n");
		send(client_fd, send_buf, strlen(send_buf), 0);
		strcpy(send_buf, "\r\n");
		send(client_fd, send_buf, strlen(send_buf), 0);
		sprintf(send_buf, "Hello World\r\n");
		send(client_fd, send_buf, strlen(send_buf), 0);

		// 关闭客户端套接字
		closesocket(client_fd);
	}
	closesocket(server_fd);

	return 0;
}