#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include "Move.h"
#include "Entities/Player/Player.h"

class Field: public AbstractObservable {
public:
	int getHeight() const;

	int getWidth() const;

	Cell& getCell(int i, int j);

	Cell** getField();

	void makeMove(Move &move, Player &entity, bool isEventTrigger);

	explicit Field(int height = 5, int width = 8);
	~Field() {
		for (int i = 0; i < height; ++i) {
			delete[] cells[i];
		}
		delete cells;
	}
	virtual void addObserver(Observer* observer) override {
		AbstractObservable::addObserver(observer);
		for(int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				for (auto obs: observers) {
					cells[i][j].addObserver(obs);
				}
			}
		}
	}

private:
	int height;
	int width;
	Cell **cells;

	bool isMoveValid(Move &move, Player &entity);
};


#endif //FIELD_H
