#ifndef FIRSTMAPEVENT_H
#define FIRSTMAPEVENT_H


#include "AbstractMapEvent.h"

class PassMapEvent: public AbstractMapEvent {
public:
    explicit PassMapEvent(Field *field);

    ~PassMapEvent() override;

    void doForEachCell(Cell &cell) override;
};


#endif //FIRSTMAPEVENT_H
