#include <iostream>
#include "AbstractPlayerEvent.h"
//
//void AbstractPlayerEvent::act() {
//    std::cout << "HERE" << std::endl;
//    doForEachCell(player);
//}

AbstractPlayerEvent::AbstractPlayerEvent(Player &player) : player(player) {}

AbstractPlayerEvent::~AbstractPlayerEvent() {}
