#include "FileWrapper.h"

using namespace std;

FileWrapper::FileWrapper(std::string filePath, int chunkSize)
{
}

void FileWrapper::GetChunk(char* chunk, int index)
{
	ifstream ifs;
	ifs.open(filePath, std::ifstream::in);

	ifs.seekg(index*chunkSize, ifs.beg);

	ifs.read(chunk, chunkSize);

	ifs.close();
}

void FileWrapper::WriteChunk(char * chunk, int index)
{
}
