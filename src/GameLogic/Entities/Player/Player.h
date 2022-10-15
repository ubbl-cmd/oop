#ifndef PLAYER_H
#define PLAYER_H

#include "Field/Move.h"

class Player {
public:
    int getVerticalPosition() const {
        return verticalPosition;
    }
    void setVerticalPosition(int new_verticalPosition) {
        verticalPosition = new_verticalPosition;
    }

    int getHorizontalPosition() const {
        return horizontalPosition;
    }
    void setHorizontalPosition(int new_horizontalPosition) {
        horizontalPosition = new_horizontalPosition;
    }

    int getHealth() const {
        return health;
    }
    void setHealth(int new_health) {
        health = new_health;
    }

    int getLuck() const;
    void setLuck(int new_luck);

    Move *getMoves() const;
    void setMoves(Move *new_moves);

    int getNumberOfMoves() const;
    void setNumberOfMoves(int new_numberOfMoves);

    bool isHasKey() const;
    void setHasKey(bool new_hasKey);

    explicit Player(int verticalPosition, int horizontalPosition, int initial_health, int initial_luck, Move *moves, int number_of_moves, bool hasKey = false):
            verticalPosition(verticalPosition), horizontalPosition(horizontalPosition), health(initial_health), luck(initial_luck), moves(moves), numberOfMoves(number_of_moves), hasKey(hasKey) {}
private:
    int luck;

    int verticalPosition;
    int horizontalPosition;
    int health{};

    Move *moves;
    int numberOfMoves;
    bool hasKey;
};


#endif //PLAYER_H
