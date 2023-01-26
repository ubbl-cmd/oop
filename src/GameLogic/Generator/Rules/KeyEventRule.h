#include "KeyEvent.h"

#ifndef KEYEVENTRULE
#define KEYEVENTRULE

template<int a, int b>
class KeyEventRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		Event *E = new KeyEvent(player);

		field->getCell(a, b).setEvent(E);
	}
};

#endif
