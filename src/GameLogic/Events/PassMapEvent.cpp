#include "PassMapEvent.h"

void PassMapEvent::doForEachCell(Cell &cell) {
    cell.setPassable(true);
}

PassMapEvent::PassMapEvent(Field *field) : AbstractMapEvent(field) {}

PassMapEvent::~PassMapEvent() = default;
