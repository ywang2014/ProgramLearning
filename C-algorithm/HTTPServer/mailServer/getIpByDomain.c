/**
	根据域名获得ip地址
*/

#include <winsock2.h> 
#include <stdio.h> 
#include <stdlib.h>

#pragma comment(lib,"ws2_32.lib")

hostent *getHostent(char *domain){
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(1, 1), &wsadata) != 0)
	{
		printf("wsastartup() failed!!\n");
		return 0;
	}
	
	return gethostbyname(domain);
	// WSACleanup();
}

// C++
vector<string> getIps(char *domain){
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(1, 1), &wsadata) != 0)
	{
		printf("wsastartup() failed!!\n");
		return 0;
	}
	
	hostent *pHostent = gethostbyname(domain);
	if (pHostent == NULL)
	{
		printf("gethostbyname() error!!\n");
		return NULL;
	}
	
	vector<string> ips;
	struct sockaddr_in sa;
	for (int i = 0; phostent->h_addr_list[i]; i++)
	{
		memcpy(&sa.sin_addr.s_addr, phostent->h_addr_list[i], phostent->h_length);
		ips.push_back(inet_ntoa(sa.sin_addr));
	}
	
	WSACleanup();
	
	return ips;
}

void getProtoent(){
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(1, 1), &wsadata) != 0)
	{
		printf("wsastartup() failed!!\n");
		return 0;
	}
	
	protoent *pprotoent = getprotobyname("tcp");
	if (pprotoent == NULL)
	{
		printf("getprotobyname() failed!!\n");
		return 0;
	}
	printf("name:%\nproto:%d\n", pprotoent->p_name, pprotoent->p_proto);
	for (n = 0; pprotoent->p_aliases[n]; n++)
	{
		printf("aliases:%s\n", pprotoent->p_aliases[n]);
	}
	
	WSACleanup();
}

