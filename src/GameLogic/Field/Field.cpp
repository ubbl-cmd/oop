#include <iostream>
#include "Field.h"

int Field::getHeight() const {
    return height;
}

int Field::getWidth() const {
    return width;
}

void Field::makeMove(Move &move, Player &entity, bool top, bool left, bool isEventTrigger) {
    int new_vertical_position = (entity.getVerticalPosition() - move.getCellsVertical() * top + move.getCellsVertical() * !top + height) % height;
    int new_horizontal_position = (entity.getHorizontalPosition() - move.getCellsHorizontal() * left + move.getCellsHorizontal() * !left + width) % width;

    if (isMoveValid(move, entity, top, left)) {
        if (isEventTrigger and cells[new_vertical_position][new_horizontal_position].getEvent() != nullptr) {
            cells[new_vertical_position][new_horizontal_position].startEvent();
        }
        entity.setVerticalPosition(new_vertical_position);
        entity.setHorizontalPosition(new_horizontal_position);

    }
}

bool Field::isMoveValid(Move &move, Player &entity, bool top, bool left) {
    int new_vertical_position = (entity.getVerticalPosition() + move.getCellsVertical() * (-1 * top) + height) % height;
    int new_horizontal_position = (entity.getHorizontalPosition() + move.getCellsHorizontal() * (-1 * left) + width) % width;
    return cells[new_vertical_position][new_horizontal_position].isPassable();
}

//Field::Field(Field &other) {
//    height = other.height;
//    width = other.width;
//    cells = new Cell*[height];
//    for (int i = 0; i < height; ++i) {
//        cells[i] = new Cell[width];
//        for (int j = 0; j < width; ++j) {
//            cells[i][j].setPassable(other.cells[i][j].isPassable());
//            cells[i][j].setEvent(other.cells[i][j].getEvent());
//        }
//    }
//}
//
//Field& Field::operator=(const Field &other) {
//    height = other.height;
//    width = other.width;
//    cells = new Cell*[height];
//    for (int i = 0; i < height; ++i) {
//        cells[i] = new Cell[width];
//        for (int j = 0; j < width; ++j) {
//            cells[i][j].setPassable(other.cells[i][j].isPassable());
//            cells[i][j].setEvent(other.cells[i][j].getEvent());
//        }
//    }
//    return *this;
//}
//
//Field::Field(Field &&source) {
//    for (int i = 0; i < height; ++i) {
//        delete[] cells[i];
//    }
//    delete cells;
//
//    height = source.height;
//    width = source.width;
//    cells = source.cells;
//}
//
//Field &Field::operator=(const Field &&other) {
//    if(this != &other) {
//        *this = other;
//        for (int i = 0; i < height; ++i) {
//            delete[] cells[i];
//        }
//        delete cells;
//    }
//    return *this;
//}







