#include "SaveReader.h"
#include "My_Exeption.h"
Event* getEvent(int e, Field * field, Player & player, GameStatus & gs) {
	if (e == 0) return nullptr;
	if (e == 1) return new ExitEvent(player, gs);
	if (e == 2) return new TrapEvent(player, 5);
	if (e == 3) return new PassMapEvent(field);
	if (e == 4) return new KeyEvent(player);
	if (e == 5) return new AllKeysEvent(field, player);
	return nullptr;
}

void SaveReader::read(Field * field, Player & player, GameStatus & gs) {
	GameStatus oldGs = gs;
	gs = GameStatus::InProgress;
	int verticalPosition;
	int horizontalPosition;
	int initial_health;
	int initial_luck;
	bool hasKey;
	if(!ifs.is_open()) throw (My_Exeption(1));

	ifs >> verticalPosition >> horizontalPosition >> initial_health >> initial_luck >> hasKey;
// 	PROVERKI
	Player newPlayer(verticalPosition, horizontalPosition, initial_health, initial_luck, player.getMoves(), player.getNumberOfMoves(), hasKey);

	int height, width;
	ifs >> height >> width;
// 	PROVERKI
	Field *newField = new Field(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int isPassable = 0;
			ifs >> isPassable;
			newField->getCell(i,j).setPassable(isPassable);
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int e;
			ifs >> e;
			newField->getCell(i,j).setEvent(getEvent(e, newField, newPlayer, gs));
		}
	}
// 	PROVERKI

	player.setVerticalPosition(verticalPosition);
	player.setHorizontalPosition(horizontalPosition);
	player.setHealth(initial_health);
	player.setLuck(initial_luck);
	player.setHasKey(hasKey);

	field->setWidth(newField->getWidth());
	field->setHeight(newField->getHeight());
	field = newField;
}
