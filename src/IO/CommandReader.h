#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <iostream>
#include <string>
#include "Entities/Player/Player.h"

class CommandReader {
public:
	Move& readMove(Player &player);

	bool readDirectionTop();
	bool readDirectionLeft();

	int readFieldSize(const std::string& name);

	bool isLogNeeded(const std::string& name);

	LogLevel getLogLevel();

	CommandReader() = default;
private:
	void writeMove(Move &move, int num);
};


#endif //COMMANDREADER_H
