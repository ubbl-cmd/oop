#ifndef FIELDGENA
#define FIELDGENA
#include "Field.h"
#include "Player.h"
#include "Event.h"
#include "GameStatus.h"

template<typename ... Rules>
class FieldGenerator {
public:
	Field* generate(int h, int w, Player &player, GameStatus &gameStatus) {
		Field *field = new Field(h,w);
		(Rules().fill(field, player, gameStatus), ...);
		return field;
	}
};


#endif
