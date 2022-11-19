#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "GameStatus.h"
#include "CommandReader.h"
#include "FieldWriter.h"
#include "ExitEvent.h"
#include "KeyEvent.h"
#include "PassMapEvent.h"
#include "AllKeysEvent.h"
#include "TrapEvent.h"
#include "Obsersers/AbstractObserver.h"
#include "Loggers/ConsoleLogger.h"
#include "Loggers/FileLogger.h"
#include "IO/Config/ConfigReader.h"
#include "IO/Config/FileConfigReader.h"
#include <fstream>

class Controller {
public:
	GameStatus start();

	explicit Controller();

	virtual ~Controller();

private:
	Player player = Player(0, 0, 5, 100, nullptr, 0);
	Field *field = nullptr;

	GameStatus gameStatus{InProgress};
	std::string GameStatusString();
	CommandReader commandReader = CommandReader();
	FieldWriter fieldWriter = FieldWriter(player);

	Field* generateField(Observer *obs);
};


#endif //CONTROLLER_H
