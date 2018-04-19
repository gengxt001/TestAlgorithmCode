// socketServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

#include <WinSock2.h>
#include <Windows.h>


#pragma comment(lib,"ws2_32.lib")   
  
#define  PORT 6000  
DWORD WINAPI clientProc(LPARAM lparam)  
{     
    SOCKET sockClient = (SOCKET)lparam;  
    char buf[1024];  
    while (TRUE)  
    {  
        memset(buf, 0, sizeof(buf));  
        // ���տͻ��˵�һ������   
        int ret = recv(sockClient, buf, sizeof(buf), 0);  
        //����Ƿ����ʧ��  
        if (SOCKET_ERROR == ret)   
        {  
            printf("socket recv failed\n");  
            closesocket(sockClient);  
            return -1;  
        }  
        // 0 ����ͻ��������Ͽ�����  
        if (ret == 0)   
        {  
            printf("client close connection\n");  
            closesocket(sockClient);  
            return -1;  
        }         
		printf("Data From Client:%s\n", buf);

        // ��������  
        ret = send(sockClient, buf, strlen(buf), 0);  
        //����Ƿ���ʧ��  
        if (SOCKET_ERROR == ret)  
        {  
            printf("socket send failed\n");  
            closesocket(sockClient);  
            return -1;  
        }  
    }  
    closesocket(sockClient);  
    return 0;  
}  
bool InitNetEnv()  
{  
    // �������绷���ĳ�ʼ������  	
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return false;
	}
	 
    return true;  
}  
int _tmain(int argc, _TCHAR* argv[])
{
	if (!InitNetEnv())  
    {  
        return -1;  
    }  
	//��ʼ����ɣ� ����һ��TCP��socket
	SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//����Ƿ�ʧ��
	if(sServer == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return -1;
	}
 
    printf("Create socket OK\n");  
    //���а󶨲���  
    SOCKADDR_IN addrServ;  
    addrServ.sin_family = AF_INET; // Э���ΪIPV4��  
    addrServ.sin_port = htons(PORT); // �˿�  ��Ϊ������С��ģʽ�������Ǵ��ģʽ������htons�ѱ����ֽ���תΪ�����ֽ���  
    addrServ.sin_addr.S_un.S_addr = INADDR_ANY; // ip��ַ��INADDR_ANY��ʾ�󶨵�������������IP  
    //��ɰ󶨲���  
    int ret = bind(sServer, (sockaddr *)&addrServ, sizeof(sockaddr));  
    //�����Ƿ�ɹ�  
    if (SOCKET_ERROR == ret)  
    {  
        printf("socket bind failed\n");  
        WSACleanup(); // �ͷ����绷��  
        closesocket(sServer); // �ر���������  
        return -1;  
    }  
    printf("socket bind OK\n");  
    // �󶨳ɹ������м���  
    ret = listen(sServer, 10);    
    //����Ƿ�����ɹ�  
    if (SOCKET_ERROR == ret)  
    {  
        printf("socket listen failed\n");  
        WSACleanup();  
        closesocket(sServer);  
        return -1;  
    }  
    printf("socket listen OK\n");  
    // �����ɹ�  
    sockaddr_in addrClient; // ���ڱ���ͻ��˵�����ڵ����Ϣ  
    int addrClientLen = sizeof(sockaddr_in);  
    while (TRUE)  
    {  
        //�½�һ��socket�����ڿͻ���  
        SOCKET *sClient = new SOCKET;   
        //�ȴ��ͻ��˵�����  
        *sClient= accept(sServer, (sockaddr*)&addrClient, &addrClientLen);  
        if (INVALID_SOCKET == *sClient)  
        {  
            printf("socket accept failed\n");  
            WSACleanup();  
            closesocket(sServer);  
            delete sClient;  
            return -1;  
        }  
        //�����߳�Ϊ�ͻ����������շ�  
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)clientProc, (LPVOID)*sClient, 0, 0);  
    }  
    closesocket(sServer);  
    WSACleanup();  
    return 0;  
}

