#ifndef OBSERVER_H
#define OBSERVER_H

#include "Message.h"
#include "Loggers/Logger.h"

class Observer {
public:
    virtual void addLogger(Logger *logger) = 0;
    virtual void removeLogger(Logger *logger) = 0;
    virtual void handleEvent(Message &message) = 0;
};

#endif //OBSERVER_H
