#include "AbstractLogger.h"

void AbstractLogger::log(Message &m) {
	if (m.getLogLevel() <= logLevel) {
		this->message = &m;
		_log();
	}
}

std::ostream &operator<<(std::ostream &os, const AbstractLogger &logger) {
	os << logger.message->to_string();
	return os;
}

AbstractLogger::~AbstractLogger() = default;
