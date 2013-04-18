//文件:udp_c.c
//描述:udp客户端源程序
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char** argv)
{
    WSADATA wsaData;
    SOCKET  socketC;
    SOCKADDR_IN serverAddr;
    char sendbuf[BUF_SIZE] = "Hello UDP World!";
	
    WSAStartup(MAKEWORD(1,1), &wsaData);
	
    socketC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8112);
    serverAddr.sin_addr.s_addr =htonl(0xb4d52139); //inet_addr("127.0.0.1");
    
    sendto(socketC, sendbuf, sizeof(sendbuf), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	
    closesocket(socketC);
	
    WSACleanup();
}