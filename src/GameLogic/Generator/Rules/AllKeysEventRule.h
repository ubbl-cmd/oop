#include "AllKeysEvent.h"

#ifndef ALLKEYSEVENTRULE
#define ALLKEYSEVENTRULE


template<int a, int b>
class AllKeysEventRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		Event *E = new AllKeysEvent(field, player);

		field->getCell(a, b).setEvent(E);
	}
};


#endif

