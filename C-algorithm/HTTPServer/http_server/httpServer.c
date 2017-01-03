/**
兼容windows和Linux平台的socket编程：

date: 2017-01-03
*/
#include <stdio.h>
#ifdef WIN32
#include <ws2tcpip.h>
#include <io.h>
#include <errno.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
#else
#include <sys/socket.h>
#include <unistd.h>
#endif

#define PORT 666
#define QUEUE_MAX_COUNT 5
#define BUFF_SIZE 1024

void setServerAddr(struct sockaddr_in* server_addr){
	// 清零--初始化
	memset(server_addr, 0, sizeof(struct sockaddr_in));
	(*server_addr).sin_family = AF_INET;
	(*server_addr).sin_port = htons(PORT);
	(*server_addr).sin_addr.s_addr = htonl(INADDR_ANY);
}

void sentMessageToClient(char *buf, int client_fd){
	sprintf(buf, "HTTP/1.0 200 OK\r\n");
	send(client_fd, buf, strlen(buf), 0);
	sprintf(buf, "Server: hoohackhttpd/0.1.0\r\n");
	send(client_fd, buf, strlen(buf), 0);
	sprintf(buf, "Content-Type: text/html\r\n");
	send(client_fd, buf, strlen(buf), 0);
	sprintf(buf, "\r\n");
	send(client_fd, buf, strlen(buf), 0);
	sprintf(buf, "<h1>Hello World</h1>\r\n");
	send(client_fd, buf, strlen(buf), 0);
}


int main(){
	// 定义server和client的socket描述符
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

#ifdef WIN32
	// 在InitInstance()中初始化网络
	WSADATA wsaData;
	int nRet;
	if ((nRet = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0){
		perror("WSAStartup failed");
		exit(0);
	}
#endif 

	// 创建socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == INVALID_SOCKET){
#ifdef WIN32
		printf("Error at socket(): %ld\n", WSAGetLastError());
#else
		printf("Error at socket(): %ld\n", geterror());
#endif 
		perror("Error: socket can not be created");
		exit(-1);
	}

	// 设置TCP/IP协议族，端口号，ip
	setServerAddr(&server_addr);

	// 绑定socket到固定端口的地址上
	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		perror("Error: socket can not bind the fixed address");
		exit(-1);
	}

	// 监听客户端请求
	if (listen(server_fd, QUEUE_MAX_COUNT) < 0){
		perror("Error: listening is failed");
		exit(-1);
	}

	printf("Http server running on port %d\n", port);

	while (1){
		// 阻塞进程，等待客户端请求
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
		if (client_fd < 0){
			perror("Error: accepting is failed");
			exit(-1);
		}
		printf("Accept a client\n");
		printf("Client socket fd: %d\n", client_fd);

		while (is_end == 0){
			buf_len = recv(client_fd, recv_buf, BUFF_SIZE, 0);
			if (buf_len < 0){
				if (errno == EAGAIN){	// 当前缓冲区已无数据可读
					break;
				}
				else{	// 发生错误
					return -1;
				}
			}
			else if (buf_len == 0){	// 对端的socket已正常关闭.
				break;
			}

			if (buf_len != sizeof(recv_buf)){
				is_end = 1;	// 读取结束
			}
			else{
				is_end = 0;	// 读取未结束
			}
			lens += buf_len;
		}
		printf("Receive %d characters.\n", lens);

		// 发送响应给客户端
		sentMessageToClient(send_buf, client_fd);

		// 关闭客户端套接字
#ifdef WIN32
		closesocket(client_fd);
#else
		close(client_fd);
#endif 

	}

#ifdef WIN32
	closesocket(server_fd);
#else
	close(server_fd);
#endif 

	return 0;
}