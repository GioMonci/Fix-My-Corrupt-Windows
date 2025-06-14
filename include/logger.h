/*
AUTH: GM
DATE: 6/9/25
DESC: header file for logger class
*/

#pragma once
#include <string>

class logger {

public:
	// enum def log levels
	enum class level { info, warning, error };


	// core log funct
	static void log(level lev, const char* message);

	// wrappers
	// calls log, and provides log level & msg
	static void info(const char* msg);
	static void warning(const char* msg);
	static void error(const char* msg);

	// convert emun to string
	static const char* levelName(logger::level lev);

	// get current time formatted as YYYY-MM-DD HH:MM:SS
	static std::string getTime();

	// simple prog bar
	// duration: in miliseconds, width: chars of bar
	static void progressBar(int duration, int width);

};