#pragma once
#include "Net.h"

#define TIME_OUT 10.0f
#define PROTOCOL_ID 39634785
#define CHUNK_SIZE 1400

class FileSenderReceiver{
public:
	FileSenderReceiver();

	typedef std::function<void(float)> FileProgressCallback;

	FileProgressCallback fileProgressCallback;

	void SendFile(std::string filePath, net::Address ip, unsigned short port);
	void RecvFile(unsigned short port, std::string savePath, net::Address sender);
private:
	net::ReliableConnection connection;
	float sendInterval;//todo: dynamicaly change
};

unsigned int overflowDiff(unsigned int a, unsigned int b, unsigned int max = UINT_MAX);

class CannotOpenFileException : public std::exception {};
class FailedToOpenSocketException : public std::exception {};
class ConnectFailedException : public std::exception {};
class LostConnectionException : public std::exception {};