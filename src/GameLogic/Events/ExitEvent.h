#ifndef EXITEVENT_H
#define EXITEVENT_H


#include "AbstractPlayerEvent.h"
#include "Controller.h"

class ExitEvent: public AbstractPlayerEvent {
public:
    ~ExitEvent() override;

    void playerChange(Player &player) override;

    ExitEvent(Player &player, GameStatus &gameStatus);

private:
    GameStatus &gameStatus;
};


#endif //EXITEVENT_H
