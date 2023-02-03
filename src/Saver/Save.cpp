#include "Save.h"

#include "ExitEvent.h"
#include "TrapEvent.h"
#include "PassMapEvent.h"
#include "KeyEvent.h"
#include "AllKeysEvent.h"

#include <string>

int getType(Event * e) {
	if (e == nullptr) return 0;
	if (e == dynamic_cast<ExitEvent *>(e)) return 1;
	if (e == dynamic_cast<TrapEvent *>(e)) return 2;
	if (e == dynamic_cast<PassMapEvent *>(e)) return 3;
	if (e == dynamic_cast<KeyEvent *>(e)) return 4;
	if (e == dynamic_cast<AllKeysEvent *>(e)) return 5;
	return 0;
}


std::string Save::getStateString() {
	std::string result = "";
	result += std::to_string(player.getVerticalPosition()) + " ";
	result += std::to_string(player.getHorizontalPosition()) + " ";
	result += std::to_string(player.getHealth()) + " ";
	result += std::to_string(player.getLuck()) + " ";
	result += std::to_string((int)player.isHasKey()) + "\n";

	result += std::to_string(field->getHeight()) + " ";
	result += std::to_string(field->getWidth()) + "\n";
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			result += std::to_string((int)field->getCell(i,j).isPassable()) + " ";
		}
		result += "\n";
	}

	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			result += std::to_string(
				getType(field->getCell(i,j).getEvent())
			) + " ";
		}
		result += "\n";
	}
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			if (getType(field->getCell(i,j).getEvent()) == 2) {
				result += std::to_string(dynamic_cast<TrapEvent *>(field->getCell(i,j).getEvent())->getHealthChange()) + " ";
			} else {
				result += std::to_string(0) + " ";
			}
		}
		result += "\n";
	}
	int x = result[0];
	for (int i = 1; i < result.length(); i++) {
		x ^= result[i];
	}
	std::cout << x << std::endl;
	return result + std::to_string(x);
}
