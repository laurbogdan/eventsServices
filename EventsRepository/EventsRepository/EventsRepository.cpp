#define _WINSOCK_DEPRECATED_NO_WARNINGS
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "events.pb.h"
#include <fstream>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "9090"

//LISTENONPORT – Listens on a specified port for incoming connections 
//or data
int ListenOnPort()
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	while (true) {
		char CommandBuffer[BUFSIZ];		
		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		// Receive until the peer shuts down the connection
		do {
			iResult = recv(ClientSocket, CommandBuffer, sizeof(CommandBuffer), 0);
			if (iResult > 0) {
				Event event;
				event.ParseFromString(CommandBuffer);
				std::fstream fi("events.txt", std::ios::binary | std::ios::in);
				Events storedEvents;
				storedEvents.ParseFromIstream(&fi);
				Event* newEvent = storedEvents.add_events();
				newEvent->set_eventdescription(event.eventdescription());
				newEvent->set_userid(event.userid());
				newEvent->set_timestamp(event.timestamp());
				fi.close();

				std::fstream fo("events.txt", std::ios::binary | std::ios::out);
				storedEvents.SerializeToOstream(&fo);
				fo.close();
				
				std::cout << "Description:";
				std::cout << event.eventdescription();
				// Echo the buffer back to the sender
			//	iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			//	if (iSendResult == SOCKET_ERROR) {
				//	printf("send failed with error: %d\n", WSAGetLastError());
				//	closesocket(ClientSocket);
				//	WSACleanup();
				//	return 1;
				//}
			//	printf("Bytes sent: %d\n", iSendResult);
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else {
				closesocket(ClientSocket);
				//WSACleanup();
			}
		} while (iResult > 0);
	//	iResult = shutdown(ClientSocket, SD_SEND);
		//if (iResult == SOCKET_ERROR) {
		//	printf("shutdown failed with error: %d\n", WSAGetLastError());
		//	closesocket(ClientSocket);
		//	WSACleanup();
		//}
	}

	// shutdown the connection since we're done

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}

void printStoredEvents() {
	std::fstream fi("events.txt", std::ios::binary | std::ios::in);
	Events storedEvents;
	storedEvents.ParseFromIstream(&fi);
	for (int i = 0; i < storedEvents.events_size(); i++) {
		const Event& event = storedEvents.events(i);
		std::cout << "Event " + std::to_string(i + 1) << std::endl;
		std::cout << "Description: " <<event.eventdescription() << std::endl;
		std::cout << "User id: " << event.userid() << std::endl;
		std::cout << "Timestamp: " << event.timestamp() << std::endl;
		std::cout << "\n";
	}
}

int main(int argc, char** argv)
{
	if (argv[0] == "print") {
		printStoredEvents();
	}
	if (argv[0] == "start_server") {
		ListenOnPort();
	}
}
