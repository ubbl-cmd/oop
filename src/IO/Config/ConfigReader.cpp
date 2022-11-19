#include "ConfigReader.h"


#include <iostream>
Move* ConfigReader::getMovesFromConfig() {
	numberOfMoves = readInt();
	Move * moves= new Move[numberOfMoves];
	for (int i = 0; i < numberOfMoves; i++) {
		std::string command = readString();
		if (command != "Move") continue;
		int x = readInt();
		int y = readInt();
		bool top = readBool();
		bool left = readBool();
		std::string btn = readString();
		moves[i] = Move(x,y,top,left, btn);
	}
	return moves;
}
