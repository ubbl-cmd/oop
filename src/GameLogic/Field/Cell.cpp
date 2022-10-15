#include <iostream>
#include "Cell.h"


bool Cell::isPassable() const {
    return passable;
}

void Cell::setPassable(bool new_passable) {
    passable = new_passable;
}

Event *Cell::getEvent() {
    return event;
}

void Cell::setEvent(Event *new_event) {
    delete event;
    event = new_event;
}

void Cell::startEvent() {
    event->act();
}
