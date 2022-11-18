#include "CommandReader.h"

void CommandReader::writeMove(Move &move, int num) {
	std::cout << num << ". " << move.getCellsVertical() << "вертикальный сдвиг, " << move.getCellsHorizontal() << "горизонтальный сдвиг" << "\n";
}

Move& CommandReader::readMove(Player &player) {
	Move* moves = player.getMoves();
	for (int i = 0; i < player.getNumberOfMoves(); ++i) {
		writeMove(moves[i], i);
	}
	int move_number;
	std::cout << "Введите нужный ход" << "\n";
	std::cin >> move_number;
	return moves[move_number];
}

bool CommandReader::readDirectionTop() {
	bool top;
	std::cout << "Идём вверх?" << "\n";
	std::cin >> top;
	return top;
}

bool CommandReader::readDirectionLeft() {
	bool left;
	std::cout << "Идём влево?" << "\n";
	std::cin >> left;
	return left;
}

int CommandReader::readFieldSize(const std::string& name) {
	int size;
	std::cout << "Введите " << name << "\n";
	std::cin >> size;
	return size;
}

bool CommandReader::isLogNeeded(const std::string& name) {
	int flag;
	std::cout << "Do you need to log [" << name << "]?(1y/0n) ";
	std::cin >> flag;
	if (flag) {
		return true;
	}
	return false;
}

LogLevel CommandReader::getLogLevel() {
	int res;
	std::cout << "Enter log level\n0.NotLoggable\n1.Critical\n2.GameState\n3.GameLogic\n";
	std::cin >> res;
	switch (res) {
		case 0:
			return LogLevel::NotLoggable;
			break;
		case 1:
			return LogLevel::Critical;
			break;
		case 2:
			 return LogLevel::GameState;
			break;
		case 3:
			return LogLevel::GameLogic;
			break;
	}
	return LogLevel::NotLoggable;
}
