#include "TrapEvent.h"

#ifndef TRAPEVENTRULE
#define TRAPEVENTRULE


template<int a, int b, int c>
class TrapEventRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		Event *E = new TrapEvent(player, player.getHealth() % c);
		if (!field->getCell(a, b).getEvent())
			field->getCell(a, b).setEvent(E);
	}
};


#endif


