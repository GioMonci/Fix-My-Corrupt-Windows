#include "../include/logs.h"

void Logs::LogSeparate() {
    std::cout<<"===================================================\n"<<std::endl;
}

void Logs::LogMessage(const char * Message) {
    std::cout<<Message<<std::endl;
}