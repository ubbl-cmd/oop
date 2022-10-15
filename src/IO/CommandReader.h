#ifndef COMMANDREADER_H
#define COMMANDREADER_H


#include <string>
#include "Entities/Player/Player.h"

class CommandReader {
public:
    Move& readMove(Player &player);

    bool readDirectionTop();
    bool readDirectionLeft();

    int readFieldSize(std::string name);

    CommandReader() = default;
private:
    void writeMove(Move &move, int num);
};


#endif //COMMANDREADER_H
