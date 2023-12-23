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
	SOCKADDR_IN myAddress;
	ZeroMemory(&myAddress, sizeof(myAddress));
	myAddress.sin_family = AF_INET;
	myAddress.sin_port = 50000;
	inet_pton(AF_INET, "222.238.240.103", &(myAddress.sin_addr.s_addr));
	bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress));

	WSACleanup();



	return 0;

}