#include "FileSenderReceiver.h"
using namespace std;
using namespace net;


FileSenderReceiver::FileSenderReceiver() : 
	connection(PROTOCOL_ID, TIME_OUT){
}

void FileSenderReceiver::SendFile(std::string filePath, net::Address ip, int port){

}

void FileSenderReceiver::RecvFile(std::string filePath, int port){

}
