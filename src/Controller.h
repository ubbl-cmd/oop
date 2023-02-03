#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Save.h"
#include "SaveWriter.h"
#include "SaveReader.h"

#include "GameStatus.h"
#include "CommandReader.h"
#include "FieldWriter.h"
#include "AbstractObserver.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "ConfigReader.h"
#include "FileConfigReader.h"
#include "FieldGenerator.h"
#include <fstream>

#include "ExitEventRule.h"
#include "KeyEventRule.h"
#include "AllKeysEventRule.h"
#include "PassMapEventRule.h"
#include "TrapEventRule.h"
#include "DiagonalWallRule.h"

#include "FileException.h"
#include "UnrealSaveException.h"

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
	void SaveGame(std::string fileName);
	void LoadGame(std::string fileName);
};


#endif //CONTROLLER_H
