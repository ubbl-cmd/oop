#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CommandReader.h"
#include "FieldWriter.h"
#include "GameStatus.h"


class Controller {
public:
    GameStatus start();

    explicit Controller() = default;

    virtual ~Controller();

private:
    Player player = Player(0, 0, 5, 100, new Move[3]{Move(1, 1), Move(0, 1), Move(1, 0)}, 3);
    Field *field = nullptr;
    void freeEvents();

    GameStatus gameStatus{InProgress};
    CommandReader commandReader = CommandReader();
    FieldWriter fieldWriter = FieldWriter(player);

    Field* generateField();
};


#endif //CONTROLLER_H
