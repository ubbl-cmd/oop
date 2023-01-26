#include "ExitEvent.h"


#ifndef EXITEVENTRULE
#define EXITEVENTRULE

template<int a>
class ExitEventRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		Event *E = new ExitEvent(player, gameStatus);
		if (a > 1) {
			field->getCell(0, 0).setEvent(E);
		}
		field->getCell(field->getHeight()-1, field->getWidth()-1).setEvent(E);
		field->getCell(field->getHeight()-1, field->getWidth()-1).setPassable(0);
	}
};

#endif
