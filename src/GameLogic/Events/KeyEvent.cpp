#include <iostream>
#include "KeyEvent.h"

KeyEvent::KeyEvent(Player &player) : AbstractPlayerEvent(player) {}

void KeyEvent::playerChange(Player &player) {
    std::string s("KeyEvent activated");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    player.setHasKey(true);
}

KeyEvent::~KeyEvent() = default;
