#include "Log.h"

void Log::message(const std::string& logMessage)
{
	std::cout << "\x1B[32m" << "LOG [" << logMessage << "]" << "\033[0m" << std::endl;
}

void Log::error(const std::string& logMessage)
{
	std::cout << "\x1B[91m" << "ERROR [" << logMessage << "]" << "\033[0m" << std::endl;
}