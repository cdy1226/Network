#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>



int main(void) {

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Error in starting up Winsock\n");
		return -1;

	}


	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		printf("Error in socket(), Error code : %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	SOCKADDR_IN myAddress;
	ZeroMemory(&myAddress, sizeof(myAddress));
	myAddress.sin_family = AF_INET;
	myAddress.sin_port = htons(50000);
	inet_pton(AF_INET, "165.229.125.79", &(myAddress.sin_addr.s_addr));
	if (bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress)) == SOCKET_ERROR)
	{
		printf("Error in bind(), Error code : %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup;
		return -1;
	}

	WSACleanup();



	return 0;

}