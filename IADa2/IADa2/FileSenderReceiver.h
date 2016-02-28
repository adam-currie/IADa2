#pragma once
#include "Net.h"

#define TIME_OUT 10.0f
#define PROTOCOL_ID 39634785

class FileSenderReceiver{
public:
	FileSenderReceiver();

	typedef std::function<void(float)> SendProgressCallback;
	typedef std::function<void(float)> RecvProgressCallback;

	//SendProgressCallback sendProgressCallback = NULL;
	//RecvProgressCallback recvProgressCallback = NULL;
	//todo add callbacks/listeners

	void SendFile(std::string filePath, net::Address ip, int port);
	void RecvFile(std::string filePath, int port);
private:
	net::ReliableConnection connection;
};

