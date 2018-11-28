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

	int portNum = 1234;

	// 보낼 데이터를 초기화한다. 

	socketStruct txData, TermData;

	txData.nrData = 3;

	for(int i = 0; i<txData.nrData; i++)

	{

		txData.data[i] = i*10;

	}

	TermData.nrData = 0;



	WSADATA wsaData;

	SOCKET hServSock, hClntSock;

	SOCKADDR_IN servAddr, clntAddr;



	int szClntAddr;

	char message[]="Hello World!";

	

	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)

		ErrorHandling("WSAStartup() error!");



	hServSock=socket(PF_INET, SOCK_STREAM, 0);

	if(hServSock==INVALID_SOCKET)

		ErrorHandling("socket() error");



	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family=AF_INET;

	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);

	servAddr.sin_port = htons(portNum);



	if(bind(hServSock, (SOCKADDR*) &servAddr, sizeof(servAddr))==SOCKET_ERROR)

		ErrorHandling("bind() error");



	if(listen(hServSock, 5)==SOCKET_ERROR)

		ErrorHandling("listen() error");



	szClntAddr=sizeof(clntAddr);

	// 아래 함수에서 holding하고 있는다. 

	printf("[Server] Holding at accept \n");

	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);

	if(hClntSock==INVALID_SOCKET)

		ErrorHandling("accept() error");



	// 보내는 부분이다. 

	int maxCnt = 5;

	while(1)

	{

		send(hClntSock, (char*)&txData, sizeof(txData), 0);

		Sleep(100);

		if(maxCnt-- < 0)

		{

			break;

		}

	}

	send(hClntSock, (char*)&TermData, sizeof(TermData), 0);

	

	// 소켓 종료 

	printf("Closing Socket \n");

	closesocket(hClntSock);

	closesocket(hServSock);

	WSACleanup();

	return 0;



}



void ErrorHandling(char* message)

{

	fputs(message, stderr);

	fputc('\n', stderr);

	exit(1);

}
