/*
AUTH: GM
DATE: 6/9/25
DESC: source file for logger class
*/

#include "../include/logger.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <ctime>

// get current time formatted as YYYY-MM-DD HH:MM:SS
std::string logger::getTime() {
	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm tm;
	localtime_s(&tm, &time);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
	return oss.str();
}

// convert log level to string
const char* logger::levelName(logger::level lev) {
	switch (lev) {
		case logger::level::info:    return "INFO";
		case logger::level::warning: return "warning";
		case logger::level::error:   return "ERROR";
	}
	return "UNKNOWN";
}

// log time, level, message to console for user debug purposes
void logger::log(level lev, const char* message) {
	// Format: [TIME][LEVEL] MESSAGE
	std::cout << "[" << logger::getTime() << "]"
		<< "[" << logger::levelName(lev) << "] "
		<< message << std::endl;
}

// to be used in soruce code
// Ex: info("lorem ipsum")
// This is calls log and gives it the level & msg
void logger::info(const char* msg){logger::log(level::info, msg);}
void logger::warning(const char* msg){logger::log(level::warning, msg);}
void logger::error(const char* msg){logger::log(level::error, msg);}

void logger::progressBar(int duration, int width){
	int stepDelay = duration / width;
	if (stepDelay < 1) stepDelay = 1;  // Ensure at least a 1ms delay

	std::cout << "[";
	for (int i = 0; i < width; ++i) {
		std::cout << "=" << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(stepDelay));
	}
	std::cout << "] Done!" << std::endl;
}

