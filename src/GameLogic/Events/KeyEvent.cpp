#include <iostream>
#include "KeyEvent.h"

KeyEvent::KeyEvent(Player &player) : AbstractPlayerEvent(player) {}

void KeyEvent::playerChange(Player &player) {
    player.setHasKey(true);
}

KeyEvent::~KeyEvent() = default;
