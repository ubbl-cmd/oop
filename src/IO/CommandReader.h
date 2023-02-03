#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <iostream>
#include <string>
#include "Entities/Player/Player.h"

class CommandReader {
public:
	Move& readMove(Player &player);

	int readLevel(int n);

	int readFieldSize(const std::string& name);

	bool isLogNeeded(const std::string& name);

	int readSaveOrLoadCommand(std::string command);

	std::string readFileName();

	LogLevel getLogLevel();

	CommandReader() = default;
private:
	void writeMove(Move &move);
	bool readDirectionTop();
	bool readDirectionLeft();
};


#endif //COMMANDREADER_H
