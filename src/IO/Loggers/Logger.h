#ifndef LOGGER_H
#define LOGGER_H

#include "Message.h"

class Logger {
public:
	virtual void log(Message& m) = 0;
};


#endif //LOGGER_H
