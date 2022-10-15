#include <iostream>
#include "Controller.h"
#include "ExitEvent.h"
#include "KeyEvent.h"
#include "PassMapEvent.h"
#include "AllKeysEvent.h"
#include "TrapEvent.h"


GameStatus Controller::start() {
    field = generateField();

    field->getCell(field->getHeight()-1, field->getWidth()-1).setPassable(false);
    field->getCell(field->getHeight()-1, field->getWidth()-1).setEvent(new ExitEvent(player, gameStatus));
    field->getCell(1, 1).setEvent(new KeyEvent(player));
    field->getCell(0, 1).setEvent(new PassMapEvent(field));
    field->getCell(1, 0).setEvent(new AllKeysEvent(field, player));
    field->getCell(2, 2).setEvent(new TrapEvent(player, 5));

    while (gameStatus == InProgress) {
        fieldWriter.PrintField(*field);

        Move &move = commandReader.readMove(player);
        bool top = commandReader.readDirectionTop();
        bool left = commandReader.readDirectionLeft();
        field->makeMove(move, player, top, left, true);
        if (player.getHealth() <= 0) {
            freeEvents();
            return Lose;
        }
    }
    freeEvents();
    return gameStatus;
}

void Controller::freeEvents() {
    for (int i = 0; i < field->getHeight(); ++i) {
        for (int j = 0; j < field->getWidth(); ++j) {
            delete field->getCell(i,j).getEvent();
        }
    }
}

Field* Controller::generateField() {
    int height = commandReader.readFieldSize("высоту");
    int width = commandReader.readFieldSize("ширину");
    if (height <= 0 or width <= 0) {
        return new Field();
    }
    return new Field(height, width);
}


Controller::~Controller() {
    delete player.getMoves();
    delete field;
}
