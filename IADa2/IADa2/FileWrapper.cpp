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

//todo: delete the following
//http://www.hackersdelight.org/hdcodetxt/crc.c.txt
unsigned _int32 FileWrapper::GetCrc32(){
	file.clear();
	file.seekg(0);

	char byte = 0;
	_int32 crc, mask;

	crc = 0xFFFFFFFF;
	while (!file.bad()) {
		file.read(&byte, 1);//get byte

		crc = crc ^ (unsigned int)byte;
		for (int j = 7; j >= 0; j--) {    // Do eight times.
			mask = -(crc & 1);
			crc = (crc >> 1) ^ (0xEDB88320 & mask);
		}
	}
	return ~crc;
}
