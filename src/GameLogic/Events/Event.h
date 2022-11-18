#ifndef EVENT_H
#define EVENT_H

#include "Obsersers/AbstractObservable.h"

class Event: public AbstractObservable {
public:
	virtual void act() = 0;
};


#endif //EVENT_H
