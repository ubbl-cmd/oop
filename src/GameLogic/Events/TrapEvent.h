#ifndef TRAPEVENT_H
#define TRAPEVENT_H

#include "Entities/Player/Player.h"
#include "AbstractPlayerEvent.h"


class TrapEvent: public AbstractPlayerEvent {
public:

    explicit TrapEvent(Player &player, int healthChange);

    ~TrapEvent() override;

    void playerChange(Player &player) override;

private:
    int healthChange;
};


#endif // TRAPEVENT_H