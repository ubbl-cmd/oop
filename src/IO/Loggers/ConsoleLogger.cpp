#include <iostream>
#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(LogLevel logLevel):AbstractLogger(logLevel) {};

void ConsoleLogger::_log() {
    std::cout << *this << "\n";
}
