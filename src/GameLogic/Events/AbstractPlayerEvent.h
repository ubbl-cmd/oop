#ifndef ABSTRACTPLAYEREVENT_H
#define ABSTRACTPLAYEREVENT_H


#include "Entities/Player/Player.h"
#include "Event.h"
#include <iostream>

class AbstractPlayerEvent: public Event {
public:
    explicit AbstractPlayerEvent(Player &player);
    virtual ~AbstractPlayerEvent();

    void act() override {
        playerChange(player);
    };
    virtual void playerChange(Player& player) = 0;
private:
    Player& player;
};


#endif //ABSTRACTPLAYEREVENT_H
