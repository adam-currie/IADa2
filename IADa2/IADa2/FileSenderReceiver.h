#pragma once
#include <string>
#include "Net.h"

#define TIME_OUT 10.0f
#define PROTOCOL_ID 39634785

class FileSenderReceiver{
public:
	FileSenderReceiver();

	//todo add callbacks/listeners

	void SendFile(std::string filePath, net::Address ip, int port);
	void RecvFile(std::string filePath, int port);
private:
	net::ReliableConnection connection;
};

