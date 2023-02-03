#include "SaveReader.h"

Event* getEvent(int e, Field * field, Player & player, GameStatus & gs) {
	Event *event = nullptr;
	if (e == 1) {
		event = new ExitEvent(player, gs);
	} else if (e == 2) {
		event = new TrapEvent(player, 5);
	} else if (e == 3) {
		event = new PassMapEvent(field);
	} else if (e == 4) {
		event = new KeyEvent(player);
	} else if (e == 5) {
		event = new AllKeysEvent(field, player);
	}
	return event;
}

Field* SaveReader::read(Field * field, Player & player, GameStatus & gs) {
	GameStatus oldGs = gs;
	int verticalPosition;
	int horizontalPosition;
	int initial_health;
	int initial_luck;
	bool hasKey;

	ifs >> verticalPosition >> horizontalPosition >> initial_health >> initial_luck >> hasKey;
	if (initial_health <= 0) {
		throw(UnrealSaveException("expected: initial_health > 0, got " + std::to_string(initial_health)));
	}
	if (initial_luck <= 0) {
		throw(UnrealSaveException("expected: initial_luck > 0, got " + std::to_string(initial_luck)));
	}

	int height, width;
	ifs >> height >> width;
	if (height < 2) {
		throw(UnrealSaveException("expected: height > 0, got " + std::to_string(height)));
	}
	if (width < 2) {
		throw(UnrealSaveException("expected: width > 0, got " + std::to_string(width)));
	}

	if (verticalPosition < 0 || verticalPosition >= height) {
		throw(UnrealSaveException("expected: |verticalPosition| < height, got " + std::to_string(verticalPosition)));
	}
	if (horizontalPosition < 0 || horizontalPosition >= width) {
		throw(UnrealSaveException("expected: |horizontalPosition| < height, got " + std::to_string(horizontalPosition)));
	}
// 	PROVERKI
	Field *newField = new Field(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int isPassable;
			ifs >> isPassable;
			if (ifs.eof()) {
				throw UnrealSaveException("Unexpected end of file");
			}
			newField->getCell(i,j).setPassable(isPassable);
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int e;
			ifs >> e;
			if (ifs.eof()) {
				throw UnrealSaveException("Unexpected end of file");
			}
			Event * event = getEvent(e, newField, player, gs);
			if (event != nullptr) {
				newField->getCell(i,j).setEvent(event);
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int e;
			ifs >> e;
			if (ifs.eof()) {
				throw UnrealSaveException("Unexpected end of file");
			}
			if (e) {
				Event * event = newField->getCell(i,j).getEvent();
				if (event != nullptr) {
					if(event == dynamic_cast<TrapEvent *>(event)) {
						dynamic_cast<TrapEvent *>(event)->setHealthChange(e);
					}
				}
			}
		}
	}


	player.setVerticalPosition(verticalPosition);
	player.setHorizontalPosition(horizontalPosition);
	player.setHealth(initial_health);
	player.setLuck(initial_luck);
	player.setHasKey(hasKey);

	return newField;
}
