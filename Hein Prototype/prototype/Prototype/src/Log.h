#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

class Log
{
public:
	static void message(const std::string& logMessage);
	static void error(const std::string& logMessage);
};

#endif