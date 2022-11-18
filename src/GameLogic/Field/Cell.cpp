#include <iostream>
#include "Cell.h"


bool Cell::isPassable() const {
    return passable;
}

void Cell::setPassable(bool new_passable) {
    std::string s("now Cell is " + std::to_string(new_passable));
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    passable = new_passable;
}

Event *Cell::getEvent() {
    return event;
}

void Cell::setEvent(Event *new_event) {
    std::string s("Cell's event changed");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    delete event;
    event = new_event;
    for (auto obs: observers) {
        event->addObserver(obs);
    }
}

void Cell::startEvent() {
    event->act();
}
