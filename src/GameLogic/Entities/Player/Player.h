#ifndef PLAYER_H
#define PLAYER_H

#include "Field/Move.h"

class Player:public Entity {
public:
    int getHealth() const;
    void setHealth(int new_health);

    int getLuck() const;
    void setLuck(int new_luck);

    Move *getMoves() const;
    void setMoves(Move *new_moves);

    int getNumberOfMoves() const;
    void setNumberOfMoves(int new_numberOfMoves);

    explicit Player(int verticalPosition, int horizontalPosition, int initial_health, int initial_luck, Move *moves, int number_of_moves):
            Entity(verticalPosition, horizontalPosition), health(initial_health), luck(initial_luck), moves(moves), numberOfMoves(number_of_moves) {}
private:
    int health;
    int luck;

    Move *moves;
    int numberOfMoves;
};


#endif //PLAYER_H
