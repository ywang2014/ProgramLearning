/**
	邮箱服务
	socket编程实现邮件发送
	smtp协议
	
	可以正常的交互，recv()到正确的连接，但是无法实现邮件的发送
	password也没有给，应该没有登陆到自己的邮箱中。
*/

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment (lib,"ws2_32.lib")


void getMessage(char sendMsg[][2048], struct sockaddr_in *sa);

void help()
{
	printf("2017/03/11"
		"\nUsage: <ServerIP> <To> <From> <Subject> <Data> <times>"
		"\nExample: 202.104.32.230 test@163.com test@163.com hello xxxxxx\n");
}

void getMessage(char sendMsg[7][2048], struct sockaddr_in *sa){
	char server[40], to[40], from[40], subject[40], data[1024];
	
	// smtp.163.com  --  220.181.12.11    pop.163.com -- 220.181.12.101
	// smtp.163.com对应的ip地址是动态的
	printf("Please input the server name: ");
	if (scanf("%s", server) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the email name you want send email to: ");
	if (scanf("%s", to) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input your email name: ");
	if (scanf("%s", from) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the subject of your email: ");
	if (scanf("%s", subject) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the email datas: ");
	if (scanf("%s", data) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	
	// fill the struct
	strncpy((char *)sa, "", sizeof(sa));
	sa->sin_family = AF_INET;
	sa->sin_port = htons(25);
	sa->sin_addr.s_addr = inet_addr(server);	// 必须是ip地址

	// built send message
	strcpy(sendMsg[0], "HELO\n");
	sprintf(sendMsg[1], "MAIL FROM:<%s>\n", from);
	sprintf(sendMsg[2], "RCPT To:<%s>\n", to);
	strcpy(sendMsg[3], "DATA\n");
	sprintf(sendMsg[4], "Subject: %s\nFrom: %s\n\n%s\n.\n", subject, from, data);
	strcpy(sendMsg[5], "SEND\n");
	strcpy(sendMsg[6], "QUIT\n");
}


void getMessageBetter(char sendMsg[7][2048], struct sockaddr_in *sa){
	char server[40], to[40], from[40], subject[40], data[1024];
	
	// smtp.163.com		pop.163.com
	printf("Please input the server name: (smtp.163.com)");
	if (scanf("%s", server) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the email name you want send email to: ");
	if (scanf("%s", to) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input your email name: ");
	if (scanf("%s", from) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the subject of your email: ");
	if (scanf("%s", subject) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	printf("Please input the email datas: ");
	if (scanf("%s", data) != 1){
		printf("Error: invalid input");
		exit(-1);
	}

	
	// fill the struct
	strncpy((char *)sa, "", sizeof(sa));
	sa->sin_family = AF_INET;
	sa->sin_port = htons(25);
	/********************** different *******************************/
	hostent *host = gethostbyname(server);	// 通过域名，获取IP地址
	memcpy(&(sa->sin_addr.s_addr), host->h_addr_list[0], host->h_length);

	// built send message
	strcpy(sendMsg[0], "HELO\n");
	sprintf(sendMsg[1], "MAIL FROM:<%s>\n", from);
	sprintf(sendMsg[2], "RCPT To:<%s>\n", to);
	strcpy(sendMsg[3], "DATA\n");
	sprintf(sendMsg[4], "Subject: %s\nFrom: %s\n\n%s\n.\n", subject, from, data);
	strcpy(sendMsg[5], "SEND\n");
	strcpy(sendMsg[6], "QUIT\n");
}


int sendMail()
{
	WSADATA wsd;
	int net, ret, i, j;
	char szBuffer[2048];
	char szSend[7][2048];
	struct sockaddr_in sa;

	if (WSAStartup(MAKEWORD(1, 1), &wsd) != 0)
	{
		printf("\nFailed to load Winsock library!ErrorCode:%d.", GetLastError());
		ExitProcess(1);
	}

	net = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (net == INVALID_SOCKET)
	{
		printf("\nsocket() failed.ErrorCode:%d.", GetLastError());
		WSACleanup();
		ExitProcess(1);
	}

	getMessage(szSend, &sa);
	
	// 服务器总是链接失败：10061:拒绝链接  10060:链接超时
	// 原因：ip地址不正确
	ret = connect(net, (struct sockaddr *) &sa, sizeof(sa));
	if (ret != 0)
	{
		printf("\nconnect() failed.ErrorCode:%d.", GetLastError());
		closesocket(net);
		WSACleanup();
		ExitProcess(1);
	}

	
	for (j = 0; j < 7; j++)
	{
		ret = recv(net, szBuffer, 2048, 0);
		if ((ret == 0) || (ret == SOCKET_ERROR))
		{
			printf("\nrecv() failed.ErrorCode:%d.", WSAGetLastError());
			break;
		}

		ret = send(net, szSend[j], strlen(szSend[j]), 0);
		if ((ret == 0) || (ret == SOCKET_ERROR))
		{
			printf("\nsend() failed.ErrorCode:%d.", WSAGetLastError());
			break;
		}
	}

	closesocket(net);
	WSACleanup();
	return 0;
}

int main(int argc, char **argv)
{
	// help();
	
	sendMail();
	
	system("pause");
	return 0;
}