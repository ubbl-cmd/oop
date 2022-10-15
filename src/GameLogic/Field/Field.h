#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include "Move.h"
#include "GameStatus.h"
#include "Entities/Player/Player.h"

class Field {
public:
    int getHeight() const;

    int getWidth() const;

    Cell& getCell(int i, int j) {
        return cells[i][j];
    }

    Cell** getField() {
        return cells;
    }

    void makeMove(Move &move, Player &entity, bool top, bool left, bool isEventTrigger);

    explicit Field(int height = 5, int width = 8):width(width),height(height) {
        cells = new Cell*[height];
        for (int i = 0; i < height; ++i) {
            cells[i] = new Cell[width];
        }
    };
    ~Field() {
        for (int i = 0; i < height; ++i) {
            delete[] cells[i];
        }
        delete cells;
    }

//    Field(Field &other);
//    Field& operator=(const Field &other);
//
//    Field(Field &&source);
//    Field& operator=(const Field &&other);


private:
    int height;
    int width;
    Cell **cells;

    bool isMoveValid(Move &move, Player &entity, bool top, bool left);
};


#endif //FIELD_H
