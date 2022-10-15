#include "ExitEvent.h"

void ExitEvent::playerChange(Player &player) {
    if (player.isHasKey()) {
        gameStatus = Win;
    }
}

ExitEvent::ExitEvent(Player &player, GameStatus &gameStatus) : AbstractPlayerEvent(player), gameStatus(gameStatus) {}

ExitEvent::~ExitEvent() = default;
