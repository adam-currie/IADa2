#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Net.h"

using namespace std;
using namespace net;

int main() {

	while (true) {
		cout << "Enter 's' to send a file, or 'r' to receive a file or 'q' to quit:";
		string input;
		cin >> input;
		
		if (input == "q") {
			break;//exit application
		}

		if (input == "s") {
			//todo: send
		}

		if (input == "r") {
			//todo: receive
		}

	}

	return 0;
}