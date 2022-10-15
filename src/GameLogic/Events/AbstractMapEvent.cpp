#include "AbstractMapEvent.h"

void AbstractMapEvent::act() {
    for(int i = 0; i < field->getHeight(); ++i) {
        for (int j = 0; j < field->getWidth(); ++j) {
            doForEachCell(field->getCell(i, j));
        }
    }
}

AbstractMapEvent::AbstractMapEvent(Field *field) : field(field) {}

AbstractMapEvent::~AbstractMapEvent() = default;
