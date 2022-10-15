#include "Player.h"

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int new_health) {
    Player::health = new_health;
}

int Player::getLuck() const {
    return luck;
}

void Player::setLuck(int new_luck) {
    Player::luck = new_luck;
}

Move* Player::getMoves() const {
    return moves;
}

void Player::setMoves(Move *new_moves) {
    Player::moves = new_moves;
}

int Player::getNumberOfMoves() const {
    return numberOfMoves;
}

void Player::setNumberOfMoves(int new_numberOfMoves) {
    numberOfMoves = new_numberOfMoves;
}
