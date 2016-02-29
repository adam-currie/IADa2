#include "FileWrapper.h"

using namespace std;

FileWrapper::FileWrapper(std::string filePath, int chunkSize, ios_base::openmode mode){
	file = fstream(filePath, mode);//todo: exceptions
	this->chunkSize = chunkSize;
}

void FileWrapper::GetChunk(char* chunk, _int64 index)
{
	file.seekg(index*chunkSize, file.beg);
	file.read(chunk, chunkSize);
	file.flush();
}

void FileWrapper::WriteChunk(char * chunk, _int64 index)
{
	file.seekp(index*chunkSize);
	file.write(chunk, chunkSize);
	file.flush();
}

streampos FileWrapper::GetFileSize(){
	file.seekg(0, ios_base::end);
	return file.tellg();
}

bool FileWrapper::Exists(){
	return file.good();
}

_int64 FileWrapper::GetMaxChunk(){
	return ((_int64)GetFileSize() - 1)/chunkSize;//todo: check
}
