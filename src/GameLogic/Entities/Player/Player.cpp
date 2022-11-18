#include "Player.h"



int Player::getLuck() const {
    return luck;
}

void Player::setLuck(int new_luck){
    std::string s("new player key is " + std::to_string(new_luck));
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
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

bool Player::isHasKey() const {
    return hasKey;
}

void Player::setHasKey(bool new_hasKey) {
    std::string s("new player has key is " + std::to_string(new_hasKey));
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    Player::hasKey = new_hasKey;
}

int Player::getHealth() const {

    return health;
}

void Player::setHealth(int new_health) {
    std::string s("new player health is " + std::to_string(new_health));
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    health = new_health;
}
