#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "FileSenderReceiver.h"

using namespace std;
using namespace net;

bool parseAddress(unsigned char* addrByteArr, string str, char delim);
void fileProgressHandler(_int64 sent, _int64 total);

int main() {
	if (!InitializeSockets()) {
		printf("ERROR: failed to initialize sockets\n");
		return 1;
	}

	string input;
	while (input != "q") {
		cout << "Enter 's' to send a file, or 'r' to receive a file or 'q' to quit:\n";
		cin >> input;

		if (input == "s") {
			//get address
			unsigned char addr[4];
			while (true) {
				cout << "Enter destination address (xxx.xxx.xxx.xxx):\n";
				cin >> input;
				if (parseAddress(addr, input, '.')) {
					break;
				}
				else {
					cout << "invalid address\n";
				}
			}

			//get port
			unsigned short port;
			while (true) {
				cout << "Enter destination port\n";
				cin >> input;
				try {
					int num = stoi(input);
					if (num >= 0 && num < 65536) {
						port = num;
						break;
					}
					else {
						cout << "port outside allowed range (0-65535)\n";
					}
				}
				catch (invalid_argument) {
					cout << "port must be a number\n";
				}
			}

			Address address(addr[0], addr[1], addr[2], addr[3], port);

			//get file path and send
			while (true) {
				cout << "Enter the path of the file to send:\n";
				cin >> input;
				try {
					FileSenderReceiver sender;
					sender.ProgressCallback = ;
					sender.SendFile(input, address, port);
					break;
				}
				catch (CannotOpenFileException) {
					cout << "cannot open file:\"" + input + "\" for reading\n";
				}
				catch (FailedToOpenSocketException) {
					cout << "cannot establish connection on specified port\n";
					break;
				}
				catch (ConnectFailedException) {
					cout << "cannot connect to server at specified address\n";
					break;
				}
				catch (LostConnectionException) {
					cout << "connection to server was lost\n";
					break;
				}
			}

			cout << "\n";
		}

		if (input == "r") {
			//get address//todo: add this stuff to function
			unsigned char addr[4];
			while (true) {
				cout << "Enter sender address (xxx.xxx.xxx.xxx):\n";
				cin >> input;
				if (parseAddress(addr, input, '.')) {
					break;
				}
				else {
					cout << "invalid address\n";
				}
			}

			//get port
			unsigned short port;
			while (true) {
				cout << "Enter port\n";
				cin >> input;
				try {
					int num = stoi(input);
					if (num >= 0 && num < 65536) {
						port = num;
						break;
					}
					else {
						cout << "port outside allowed range (0-65535)\n";
					}
				}
				catch (invalid_argument) {
					cout << "port must be a number\n";
				}
			}
			Address address(addr[0], addr[1], addr[2], addr[3], port);

			//get file path and send
			while (true) {
				cout << "Enter save file path:\n";
				cin >> input;
				try {
					FileSenderReceiver receiver;
					receiver.RecvFile(port, input, address);
					break;
				}
				catch (CannotOpenFileException) {
					cout << "cannot open file:\"" + input + "\" for writing\n";
				}
				catch (FailedToOpenSocketException) {
					cout << "cannot establish connection on specified port\n";
					break;
				}
				catch (LostConnectionException) {
					cout << "lost connection to sender\n";
					break;
				}

				cout << "\n";

			}

		}
	
	}

	ShutdownSockets();
	return 0;
}

void fileProgressHandler(_int64 sent, _int64 total) {

}

bool parseAddress(unsigned char* addrByteArr, string str, char delim) {
	stringstream ss(str);
	for (int i = 0; i < 4; i++) {
		string byte;
		if (!getline(ss, byte, delim)) {
			return false;
		}
		try {
			int num = stoi(byte);
			if (num >= 0 && num < 256) {
				addrByteArr[i] = num;
			}else {
				return false;
			}
		}catch (invalid_argument) {
			return false;
		}
	}
	return true;
}