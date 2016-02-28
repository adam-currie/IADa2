#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileWrapper {
public:

	FileWrapper(std::string filePath, int chunkSize);

	void GetChunk(char* chunk, int index);

	void WriteChunk(char* chunk, int index);

private:

	int chunkSize;
	std::string filePath;

};