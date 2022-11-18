#include "PassMapEvent.h"

void PassMapEvent::doForEachCell(Cell &cell) {
    std::string s("PassMapEvent activated");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    cell.setPassable(true);
}

PassMapEvent::PassMapEvent(Field *field) : AbstractMapEvent(field) {}

PassMapEvent::~PassMapEvent() = default;
