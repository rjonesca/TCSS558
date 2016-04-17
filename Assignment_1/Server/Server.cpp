/*
 * Server.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: roshunjones
 */

#include "Server.h"
#include <sys/socket.h>
#include <iostream>

using namespace std;

Server::Server() {
}

Server::~Server() {
}

// Entry point for application
// argc : number of arguments passed to application
// argv : array of arguments passed to application
int main(int argc, char *argv[]) {
	//Usage: Server port
	//port: The port number to listen on

	if(argc <= 1) {
		cout << "Usage: Server port";
	}
}

