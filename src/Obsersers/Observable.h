#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"
#include "Message.h"

class Observable {
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObserver(Message& message) = 0;
};

#endif //OBSERVABLE_H
