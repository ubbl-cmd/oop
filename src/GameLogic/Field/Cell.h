#ifndef CELL_H
#define CELL_H

#include "Events/Event.h"

class Cell {
public:
    explicit Cell(bool passable = true, Event * event = nullptr):passable(passable),event(event) {};

    bool isPassable() const;
    void setPassable(bool new_passable);

    Event* getEvent();
    void setEvent(Event * new_event);


    void startEvent();
private:
    bool passable;
    Event * event;
};


#endif //CELL_H
