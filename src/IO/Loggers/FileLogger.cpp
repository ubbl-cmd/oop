#include "FileLogger.h"


void FileLogger::_log() {
	fout << *this << "\n";
}

FileLogger::FileLogger(LogLevel logLevel):AbstractLogger(logLevel) {
	this->logLevel = logLevel;
	fout.open("Game.log", std::ios::binary);
}




