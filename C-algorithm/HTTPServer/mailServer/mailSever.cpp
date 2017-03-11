/**
C++实现邮件发送

163邮箱，用户名不带@163.com
auth login 不需要@xxx.com，163邮箱如果加了，则错误
mail from:<> 邮箱地址必须写全，否则不能发送邮件
*/
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <string>

#pragma comment (lib,"ws2_32.lib")

using namespace std;

void Send(SOCKET& s, string data);
void Recv(SOCKET& s, char* buf, int len);
string Base64Encode(const string& src);
bool SendEmail(const string& smtpServer, const string& username, const string& pw, const string& to, const string& data);

void Send(SOCKET &s, string data){
	int ret = send(s, data.c_str(), data.length(), 0);
	if (ret == 0 || ret == SOCKET_ERROR){
		cerr << "Error: Send message." << endl;
	}
}

void Recv(SOCKET &s, char *buf, int len){
	memset(buf, 0, len);
	int ret = recv(s, buf, len, 0);
	if (ret == 0 || ret == SOCKET_ERROR){
		cerr << "Error: Receive message." << endl;
	}
	cout << "Receive: " << buf << endl;
}

string Base64Encode(const string &src){
	int len = src.length();
	string dst(len / 3 * 4 + 4, 0);

	int i = 0;
	int j = 0;
	int max_i = len - 3;
	while (i <= max_i){
		dst[j] = (src[i] & 0xFC) >> 2;
		dst[j + 1] = ((src[i] & 0x30) << 4) + ((src[i + 1] & 0xF0) >> 4);
		dst[j + 2] = ((src[i + 1] & 0x0F) << 2) + ((src[i + 2] & 0xC0) >> 6);
		dst[j + 3] = src[i + 2] & 0x3F;
		i += 3;
		j += 4;
	}
	if (len % 3 == 1){
		dst[j] = (src[i] & 0xFC) >> 2;
		dst[j + 1] = (src[i] & 0x03) << 4;
		dst[j + 2] = 64;
		dst[j + 3] = 64;
	}
	else if (len % 3 == 2){
		dst[j] = (src[i] & 0xFC) >> 2;
		dst[j + 1] = ((src[i] & 0x03) << 4) + ((src[i + 1] & 0xF0) >> 4);
		dst[j + 2] = (src[i + 1] & 0x0F) << 2;
		dst[j + 3] = 64;
	}
	j += 4;

	static unsigned char *base64 = (unsigned char *)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	for (int i = 0; i < j; i++){
		// map 6 bit value to base64 ASCII character
		dst[i] = base64[(int)dst[i]];
	}
	return dst;
}

void buildMessage(char msg[][1024], const char *server, const char *user, const char *pw, const char *to, const char *subject, const char *data){
	sprintf(msg[0], "HELO %s\r\n", server);
	strcpy(msg[1], "auth login\r\n");
	sprintf(msg[2], "%s\r\n", Base64Encode(user));
	sprintf(msg[3], "%s\r\n", Base64Encode(pw));
	sprintf(msg[4], "mail from:<%s>\r\n", user);
	sprintf(msg[5], "rcpt to:<%s>\r\n", to);
	sprintf(msg[6], "data\r\n");
	sprintf(msg[7], "to:%s\r\nsubject:%s\r\n\r\n%s\r\n.\r\n", to, subject, data);
	sprintf(msg[8], "quit\r\n");
}

bool SendEmail(const string &server, const string &user, const string &pw, const string &to, const string &subject, const string &data){
	WSADATA wsd;
	if (WSAStartup(MAKEWORD(1, 1), &wsd) != 0)
	{
		printf("\nFailed to load Winsock library!ErrorCode:%d.", GetLastError());
		ExitProcess(1);
	}

	hostent *ph = gethostbyname(server.c_str());
	if (ph == NULL){
		cerr << "Error: " << server << " is wrong!" << endl;
		return false;
	}

	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(25);
	memcpy(&sa.sin_addr.s_addr, ph->h_addr_list[0], ph->h_length);

	SOCKET s = socket(PF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET){
		cerr << "Error: socket created failing." << endl;
		return false;
	}
	int ret = connect(s, (sockaddr *)&sa, sizeof(sa));
	if (ret != 0){
		cerr << "Error: connect failed." << endl;
		return false;
	}

	char buffer[1024];
	char msg[9][1024];
	buildMessage(msg, server.c_str(), user.c_str(), pw.c_str(), to.c_str(), subject.c_str(), data.c_str());
	for (int i = 0; i < 9; i++){
		Recv(s, buffer, sizeof(buffer));
		Send(s, msg[i]);
		if (i == 2 && string(buffer).substr(0, 3) != "334"){
			cerr << "Error: username is error." << endl;
			return false;
		}
		else if (i == 3 && string(buffer).substr(0, 3) != "235"){
			cerr << "Error: password is error." << endl;
			return false;
		}
	}

	closesocket(s);
	WSACleanup();

	return true;
}

void test(){
	if (SendEmail("smtp.sina.com", "xxx@sina.com", "xxx", "xxx@sina.com", "Hello", "Hahahaha...")){
		cout << "Success: ok." << endl;
	}
	else {
		cout << "Failed: no." << endl;
	}
}

int main(){
	test();

	return 0;
}
