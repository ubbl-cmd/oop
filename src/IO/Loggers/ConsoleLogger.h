#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Message.h"
#include "AbstractLogger.h"

class ConsoleLogger: public AbstractLogger {
public:
	ConsoleLogger(LogLevel logLevel);
protected:
	void _log() override;
};


#endif //CONSOLELOGGER_H
