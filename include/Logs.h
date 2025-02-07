#pragma once
#include "common.h"

class Logs {

    public:
    void LogSeparate();
    void LogMessage(const char * Message);
    void ProgressBar(int duration);
};

