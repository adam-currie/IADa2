#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileWrapper {
public:

	FileWrapper(std::string filePath, int chunkSize, std::ios::openmode mode = std::ios::in | std::ios::out | std::ios::binary);
	

	void GetChunk(char* chunk, _int64 index);
	void WriteChunk(char* chunk, _int64 index, int maxToWrite);
	void WriteChunk(char* chunk, _int64 index);
	std::streampos GetFileSize();
	bool Exists();
	_int64 GetMaxChunk();
	unsigned _int32 GetCrc32();

private:

	int chunkSize;
	std::fstream file;

};