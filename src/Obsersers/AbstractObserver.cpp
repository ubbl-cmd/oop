#include "AbstractObserver.h"

#include <algorithm>
#include <iostream>

void AbstractObserver::handleEvent(Message& message) {
	for (auto & logger: loggers) {
		// if (message.getLogLevel() <= logLevel) {
			logger->log(message);
		// }
	}
}

void AbstractObserver::addLogger(Logger *logger) {
	loggers.push_back(logger);
}

void AbstractObserver::removeLogger(Logger *logger) {
	auto it = std::find(loggers.begin(), loggers.end(), logger);
	if (it != loggers.end()) {
		loggers.erase(it);
	}
}

// LogLevel AbstractObserver::getLogLevel() {
// 	return logLevel;
// }
// void AbstractObserver::setLogLevel(LogLevel newLogLeveL) {
// 	logLevel = newLogLeveL;
// }

AbstractObserver::AbstractObserver() = default;

AbstractObserver::~AbstractObserver() = default;
