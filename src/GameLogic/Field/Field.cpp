#include <iostream>
#include "Field.h"

int Field::getHeight() const {
	return height;
}

int Field::getWidth() const {
	return width;
}

void Field::makeMove(Move &move, Player &entity, bool isEventTrigger) {
	int new_vertical_position = (entity.getVerticalPosition() - move.getCellsVertical() * move.getTop() + move.getCellsVertical() * !move.getTop() + height) % height;
	int new_horizontal_position = (entity.getHorizontalPosition() - move.getCellsHorizontal() * move.getLeft() + move.getCellsHorizontal() * !move.getLeft() + width) % width;

	if (isMoveValid(move, entity)) {
		if (isEventTrigger and cells[new_vertical_position][new_horizontal_position].getEvent() != nullptr) {
			cells[new_vertical_position][new_horizontal_position].startEvent();
		}
		entity.setVerticalPosition(new_vertical_position);
		entity.setHorizontalPosition(new_horizontal_position);
	} else {
		std::string s("Player trying to move to unpassable cell");
		Message m(s, LogLevel::Critical);
		this->notifyObserver(m);
	}
}

bool Field::isMoveValid(Move &move, Player &entity) {
	int new_vertical_position = (entity.getVerticalPosition() + move.getCellsVertical() * (-1 * move.getTop()) + height) % height;
	int new_horizontal_position = (entity.getHorizontalPosition() + move.getCellsHorizontal() * (-1 * move.getLeft()) + width) % width;
	return cells[new_vertical_position][new_horizontal_position].isPassable();
}

Field::Field(int height, int width) :width(width),height(height) {
	if(height <= 0 || width <= 0) {
		std::string s("Wrong field params ");
		Message m(s, LogLevel::Critical);
		this->notifyObserver(m);
		height = 5;
		height = 8;
	}
	cells = new Cell*[height];
	for (int i = 0; i < height; ++i) {
		cells[i] = new Cell[width];
	}
}

Cell **Field::getField() {
	return cells;
}

Cell &Field::getCell(int i, int j) {
	return cells[i][j];
}







