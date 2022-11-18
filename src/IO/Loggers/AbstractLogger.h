#ifndef OOP_ABSTRACTLOGGER_H
#define OOP_ABSTRACTLOGGER_H


#include <ostream>
#include "Logger.h"

class AbstractLogger: public Logger{
public:
    virtual ~AbstractLogger();
    void log(Message &m) override;
    friend std::ostream &operator<<(std::ostream &os, const AbstractLogger &logger);
    AbstractLogger(LogLevel logLevel):logLevel(logLevel) {};
protected:
    Message *message;
    virtual void _log() = 0;
    LogLevel logLevel;
};


#endif //OOP_ABSTRACTLOGGER_H
