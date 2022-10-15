#include "TrapEvent.h"

void TrapEvent::playerChange(Player &player) {
    player.setHealth(player.getHealth() - healthChange);
}

TrapEvent::TrapEvent(Player &player, int healthChange) : AbstractPlayerEvent(player), healthChange(healthChange) {}

TrapEvent::~TrapEvent() = default;
