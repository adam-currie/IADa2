#include "FileWrapper.h"

using namespace std;

FileWrapper::FileWrapper(std::string filePath, int chunkSize, ios_base::openmode mode){
	file = fstream(filePath, mode);//todo: exceptions
	this->chunkSize = chunkSize;
}

void FileWrapper::GetChunk(char* chunk, _int64 index){
	file.clear();
	file.seekg(index*chunkSize, file.beg);
	file.read(chunk, chunkSize);
	file.flush();
}

void FileWrapper::WriteChunk(char * chunk, _int64 index){	
	WriteChunk(chunk, index, chunkSize);
}

void FileWrapper::WriteChunk(char * chunk, _int64 index, int maxToWrite){
	int writesize = chunkSize;
	if (maxToWrite < chunkSize) {
		writesize = maxToWrite;
	}

	file.clear();
	file.seekp(index*chunkSize);
	file.write(chunk, writesize);
	file.flush();
}

streampos FileWrapper::GetFileSize(){
	file.clear();
	file.seekg(0, ios_base::end);
	return file.tellg();
}

bool FileWrapper::Exists(){
	return file.good();
}

_int64 FileWrapper::GetMaxChunk(){
	return ((_int64)GetFileSize() - 1)/chunkSize;//todo: check
}
