/*
 * Client.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: roshunjones
 */

#include "Client.h"
#include <sys/socket.h>
#include <iostream>

using namespace std;

Client::Client() {
}

Client::~Client() {
}

// Entry point for application
// argc : number of arguments passed to application
// argv : array of arguments passed to application
int main(int argc, char *argv[]) {
	//Usage: Client address port
	//address: The address to connect to. ex. 127.0.0.1
	//port: The port number to connect to

	if(argc <= 1) {
		cout << "Usage: Client address port";
	}
}
