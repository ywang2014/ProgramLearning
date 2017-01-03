/**
	Linux平台下的socket编程：
		比windows平台的头文件简单
			
	date: 2017-01-03
*/
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define PORT 666
#define QUEUE_MAX_COUNT 5
#define BUFF_SIZE 1024

#define SERVER_STRING "Server: hoohackhttpd/0.1.0\r\n"


int main(){
	// 定义server和client的socket描述符
	int server_fd = -1;
	int client_fd = -1;

	u_short port = PORT;
	struct sockaddr_in client_addr;
	struct sockaddr_in server_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	char buf[BUFF_SIZE];
	char recv_buf[BUFF_SIZE];

	int lens = 0;
	int is_end = 0;
	int buf_len = 0;

	// 创建socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == INVALID_SOCKET){
		printf("Error at socket(): %ld\n", geterror());
	   	perror("Error: socket can not be created");
		exit(-1);
	}
	
	// 设置TCP/IP协议族，端口号，ip
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

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
		
		while(is_end == 0){
			buf_len = recv(client_fd, recv_buf, BUFF_SIZE, 0);
			if(buf_len < 0){
				if(errno == EAGAIN){	// 当前缓冲区已无数据可读
					break;
				}
				else{	// 发生错误
					return -1;
				}
			}
			else if(buflen == 0){	// 对端的socket已正常关闭.
				break;
			}
			
			if(buflen != sizeof(buf)){
				is_end = 1;	// 读取结束
			}
			else{
				is_end = 0;	// 读取未结束
			}
			lens += buf_len;
		}
		printf("Receive %d characters.\n", lens);

		// 发送响应给客户端
		sprintf(buf, "HTTP/1.0 200 OK\r\n");
		send(client_fd, buf, strlen(buf), 0);
		strcpy(buf, SERVER_STRING);
		send(client_fd, buf, strlen(buf), 0);
		sprintf(buf, "Content-Type: text/html\r\n");
		send(client_fd, buf, strlen(buf), 0);
		strcpy(buf, "\r\n");
		send(client_fd, buf, strlen(buf), 0);
		sprintf(buf, "Hello World\r\n");
		send(client_fd, buf, strlen(buf), 0);

		// 关闭客户端套接字
		close(client_fd);
	}

	close(server_fd);

	return 0;
}