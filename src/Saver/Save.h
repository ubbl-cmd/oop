#ifndef SAVE
#define SAVE

#include "Player.h"
#include "Field.h"


class Save {
public:
	Save(Player &player, Field *field): player(player), field(field) {};

	std::string getStateString();
private:
	Player &player;
	Field *field;
};

#endif
