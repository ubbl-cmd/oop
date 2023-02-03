#include "CommandReader.h"

int CommandReader::readLevel(int n) {
	int level = 0;
	while (!(0 < level && level <= n)) {
		std::cout << "Введите сложность от 1 до " << n << ": ";
		std::cin >> level;
	}
	return level;
}

void CommandReader::writeMove(Move &move) {
	std::cout << move.getBtn() << ". " << move.getCellsVertical() << "вертикальный сдвиг, " << move.getCellsHorizontal() << "горизонтальный сдвиг" << ", вверх" << move.getTop() << ", влево " << move.getLeft() << "\n";
}

Move& CommandReader::readMove(Player &player) {
	Move* moves = player.getMoves();
	for (int i = 0; i < player.getNumberOfMoves(); ++i) {
		writeMove(moves[i]);
	}
	while (1) {
		std::string moveBtn;
		std::cout << "Введите нужный ход" << "\n";
		std::cin >> moveBtn;
		for (int i = 0; i < player.getNumberOfMoves(); i++) {
			if (moves[i].getBtn() == moveBtn) {
				return moves[i];
			}
		}
		std::cout << "Нет такого хода" << "\n";
	}
	return moves[0];
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
