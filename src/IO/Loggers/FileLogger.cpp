#include "FileLogger.h"


void FileLogger::_log() {
	fout << *this << std::endl;
}

FileLogger::FileLogger(LogLevel logLevel):AbstractLogger(logLevel) {
	this->logLevel = logLevel;
	fout.open("Game.log", std::ios::binary);
}




