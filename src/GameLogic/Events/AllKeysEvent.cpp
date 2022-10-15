#include "AllKeysEvent.h"

void AllKeysEvent::doForEachCell(Cell &cell) {
    if (cell.getEvent() == nullptr)
        cell.setEvent(new KeyEvent(player));

}

AllKeysEvent::AllKeysEvent(Field *field, Player &player) : AbstractMapEvent(field), player(player) {}

AllKeysEvent::~AllKeysEvent() = default;
