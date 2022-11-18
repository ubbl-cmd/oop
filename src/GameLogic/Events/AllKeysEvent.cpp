#include "AllKeysEvent.h"
#include "Obsersers/AbstractObserver.h"

void AllKeysEvent::doForEachCell(Cell &cell) {
    std::string s("AllKeysEvent activated");
    Message m(s, LogLevel::GameLogic);
    this->notifyObserver(m);
    if (cell.getEvent() == nullptr)
        cell.setEvent(new KeyEvent(player));
        for (auto & obs:this->observers) {
            cell.addObserver(obs);
        }

}

AllKeysEvent::AllKeysEvent(Field *field, Player &player) : AbstractMapEvent(field), player(player) {}

AllKeysEvent::~AllKeysEvent() = default;
