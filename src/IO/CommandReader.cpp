#include <iostream>
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

int CommandReader::readFieldSize(std::string name) {
    int size;
    std::cout << "Введите " << name << "\n";
    std::cin >> size;
    return size;
}
