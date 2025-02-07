#include "../include/logs.h"

void Logs::LogSeparate() {
    std::cout<<"===================================================\n"<<std::endl;
}

void Logs::LogMessage(const char * Message) {
    std::cout<<Message<<std::endl;
}

void Logs::ProgressBar(int duration) {
    const int barWidth = 50;  // Width of the progress bar
    std::cout << "[";

    for (int i = 0; i <= barWidth; ++i) {
        std::cout << "=";  // Progress character
        std::cout.flush(); // Force print update

        std::this_thread::sleep_for(std::chrono::milliseconds(duration / barWidth)); // Control speed
    }

    std::cout << "] Done!\n";
}
