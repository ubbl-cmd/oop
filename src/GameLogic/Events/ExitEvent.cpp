#include "ExitEvent.h"

void ExitEvent::playerChange(Player &player) {
    std::string s("ExitEvent activated");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    if (player.isHasKey()) {
        gameStatus = Win;
    }
}

ExitEvent::ExitEvent(Player &player, GameStatus &gameStatus) : AbstractPlayerEvent(player), gameStatus(gameStatus) {}

ExitEvent::~ExitEvent() = default;
