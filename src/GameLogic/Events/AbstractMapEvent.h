#ifndef ABSTRACTMAPEVENT_H
#define ABSTRACTMAPEVENT_H


#include "Event.h"
#include "Field/Field.h"

class AbstractMapEvent: public Event {
public:
	explicit AbstractMapEvent(Field *field);

	virtual ~AbstractMapEvent();

	void act() override;
	virtual void doForEachCell(Cell &cell) = 0;
private:
	Field * field;
};


#endif //ABSTRACTMAPEVENT_H
