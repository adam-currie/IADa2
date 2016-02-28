#include <iostream>
#include <string>
#include "FileSenderReceiver.h"

using namespace std;

int main() {

	while (true) {
		cout << "Enter 's' to send a file, or 'r' to receive a file or 'q' to quit:";
		string input;
		cin >> input;
		
		if (input == "q") {
			break;//exit application
		}

		if (input == "s") {
			FileSenderReceiver FileSender();
			

		}

		if (input == "r") {
			//todo: receive
		}

	}

	return 0;
}