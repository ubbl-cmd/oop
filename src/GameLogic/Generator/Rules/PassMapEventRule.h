#include "PassMapEvent.h"

#ifndef PASSMAPEVENTRULE
#define PASSMAPEVENTRULE

template<int a, int b>
class PassMapEventRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		Event *E = new PassMapEvent(field);

		field->getCell(a, b).setEvent(E);
	}
};

#endif
