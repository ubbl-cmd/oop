#ifndef ABSTRACTOBSERVER_H
#define ABSTRACTOBSERVER_H

#include "Observer.h"

#include "vector"
#include "Loggers/Logger.h"

class AbstractObserver: public Observer {
public:
	LogLevel getLogLevel();
	// void setLogLevel(LogLevel newLogLeveL);

	void handleEvent(Message& message) override;

	void addLogger(Logger *logger);
	void removeLogger(Logger *logger);

	AbstractObserver();
	virtual ~AbstractObserver();
protected:
	//LogLevel logLevel{LogLevel::GameLogic};
	std::vector<Logger *> loggers;
};


#endif //ABSTRACTOBSERVER_H
