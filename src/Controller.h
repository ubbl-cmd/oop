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
#include <fstream>

class Controller {
public:
    GameStatus start();

    explicit Controller();

    virtual ~Controller();

private:
    Player player = Player(0, 0, 5, 100, new Move[3]{Move(1, 1), Move(0, 1), Move(1, 0)}, 3);
    Field *field = nullptr;
    void freeEvents();

    GameStatus gameStatus{InProgress};
    std::string GameStatusString();
    CommandReader commandReader = CommandReader();
    FieldWriter fieldWriter = FieldWriter(player);

    Field* generateField(Observer *obs);
};


#endif //CONTROLLER_H
