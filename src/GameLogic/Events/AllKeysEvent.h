#ifndef ALLKEYSEVENT_H
#define ALLKEYSEVENT_H

#include "KeyEvent.h"
#include "AbstractMapEvent.h"

class AllKeysEvent: public AbstractMapEvent {
public:
    AllKeysEvent(Field *field, Player &player);

    ~AllKeysEvent() override;

    void doForEachCell(Cell &cell) override;
private:
    Player &player;
};


#endif //ALLKEYSEVENT_H
