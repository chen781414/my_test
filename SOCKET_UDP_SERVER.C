//文件:udp_s.c
//描述:udp服务器端源程序
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char** argv)
{
    WSADATA wsaData;
    SOCKET  socketC;
    SOCKADDR_IN serverAddr;
    char recvbuf[BUF_SIZE];
	int nRet = 0;
	
    WSAStartup(MAKEWORD(1,1), &wsaData);
	
    socketC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7394);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
    bind(socketC, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	printf("UDP Waiting receive Message  \n");
	
    nRet = recvfrom(socketC, recvbuf, sizeof(recvbuf), 0, 0, 0);
    
	
	if (nRet > 0)
        printf("Already Receive Message %s ", recvbuf);
	
    closesocket(socketC);
	
    WSACleanup();
}
