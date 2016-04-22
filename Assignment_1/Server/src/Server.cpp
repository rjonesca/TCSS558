// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Server.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	long successful;
	WSADATA winSockData;
	WORD dllVersion;

	dllVersion = MAKEWORD(2, 1);

	// start winsock dll
	successful = WSAStartup(dllVersion, &winSockData);

	// create socket structure
	SOCKADDR_IN address;
	int addressSize = sizeof(address);

	// create sockets
	SOCKET sockListen; // listens for incoming connections
	SOCKET sockConnection;

	// socket arguments
	// AF_INET = internet domian
	// SOCK_STREAM = connection oriented tcp (not SOCK_GRAM)
	sockConnection = socket(AF_INET, SOCK_STREAM, NULL);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	//address.sin_addr.s_addr = InetPton("127.0.0.1");
	address.sin_family = AF_INET;
	address.sin_port = htons(444); // port

	sockListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sockListen, (SOCKADDR*)&address, sizeof(address));
	listen(sockListen, SOMAXCONN); // listen

								   // poll connection found
	for (;;)
	{
		cout << "Waiting for incoming connection...";

		if (sockConnection = accept(sockListen, (SOCKADDR*)&address, &addressSize))
		{
			cout << "\n\tA connection was found" << endl;
			successful = send(sockConnection, "Welcome! You have connected to Skynet!", 46, NULL);
			break;
		}
	}

	string message;
	//string completeMessage;
	//char inMessage[100];

	while (true)
	{
		cout << "Awaiting Response\n";
		successful = recv(sockConnection, (char*)&message, sizeof(message), NULL);
		//message = inMessage;

		if (successful)
			cout << "Client: " << message << " \n";

		cout << "Server: ";
		getline(cin, message);
		cout << "\n";


		//const char *outMessage = message.c_str();
		send(sockConnection, (char*)&message, sizeof(message), NULL);
	}
	return 0;
}



Server::Server()
{
}


Server::~Server()
{
}
