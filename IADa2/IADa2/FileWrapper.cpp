#include "FileWrapper.h"

using namespace std;

FileWrapper::FileWrapper(std::string filePath, int chunkSize)
{
}

void FileWrapper::GetChunk(char* chunk, int index)
{
	ifstream ifs;
	ifs.open(filePath, ifstream::in);

	ifs.seekg(index*chunkSize, ifs.beg);

	ifs.read(chunk, chunkSize);

	ifs.close();
}

void FileWrapper::WriteChunk(char * chunk, int index)
{
	ofstream outfile;
	outfile.open(filePath, ofstream::out | ofstream::app);

	outfile.seekp(index*chunkSize);
	outfile.write(chunk, chunkSize);

	outfile.close();
}
