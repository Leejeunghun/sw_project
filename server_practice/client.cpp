#include "stdafx.h"

#include <stdio.h>

#include <stdlib.h>

#include <winsock2.h>

void ErrorHandling(char* message);



struct socketStruct {

   int nrData;

   double data[100];

};



int _tmain(int argc, _TCHAR* argv[])

{

	WSADATA wsaData;

	SOCKET hSocket;

	SOCKADDR_IN servAddr;



	// char*를 받은 후에 원하는 형태로 type cast를 한다. 

	char message[500];

	socketStruct* RxData;

	int strLen;

	

	if(WSAStartup(MAKEWORD(2, 2), &wsaData) !=0)

		ErrorHandling("WSAStartup() errer!");



	hSocket=socket(PF_INET, SOCK_STREAM, 0);

	if(hSocket==INVALID_SOCKET)

		ErrorHandling("hSocketet() error!");



	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family=AF_INET;

	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	servAddr.sin_port=htons(1234);



	if(connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)

		ErrorHandling("connect() error!");



	while(1)

	{

		Sleep(10);

		strLen = recv(hSocket, message, sizeof(message)-1, 0);

		if(strLen == 0)

		{

			continue;

		}

		// 받은 것을 형 변환으로 원하는 값으로 바꾼다. 

		message[strLen] = '\0';

		RxData = (socketStruct*)message;

		if(strLen == -1)

			ErrorHandling("read() error!");

		

		int nrData = RxData->nrData;

		// 받은 데이터의 nrData = 0이면 종료한다. 

		if(nrData == 0)

			break;

		for(int i = 0; i < nrData; i++)

			printf("Message from server:[%d] %.1f \n", i, RxData->data[i]);

	}

	// 소켓 종료 

	printf("Closing Socket \n");

	closesocket(hSocket);

	WSACleanup();

	return 0;



}



void ErrorHandling(char* message)

{

	fputs(message, stderr);

	fputc('\n', stderr);

	exit(1);

}
