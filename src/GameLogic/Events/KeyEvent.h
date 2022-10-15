#ifndef KEYEVENT_H
#define KEYEVENT_H


#include "AbstractPlayerEvent.h"

class KeyEvent: public AbstractPlayerEvent {
public:
    explicit KeyEvent(Player &player);

    ~KeyEvent() override;

    void playerChange(Player &player) override;
};


#endif //KEYEVENT_H
