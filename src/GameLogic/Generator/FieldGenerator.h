#ifndef FIELDGENA
#define FIELDGENA
#include "Field.h"
#include "Player.h"
#include "Event.h"
#include "GameStatus.h"

template<typename ... Rules>
class FieldGenerator {
public:
	Field* generate(Player &player, GameStatus &gameStatus) {
		Field *field = new Field(5,5);
		(Rules().fill(field, player, gameStatus), ...);
		return field;
	}
};


#endif
