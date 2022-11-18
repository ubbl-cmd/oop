#include "TrapEvent.h"

void TrapEvent::playerChange(Player &player) {
    std::string s("TrapEvent activated");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    player.setHealth(player.getHealth() - healthChange);
}

TrapEvent::TrapEvent(Player &player, int healthChange) : AbstractPlayerEvent(player), healthChange(healthChange) {}

TrapEvent::~TrapEvent() = default;
