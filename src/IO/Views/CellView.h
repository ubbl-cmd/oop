#ifndef CELLVIEW_H
#define CELLVIEW_H

#include "Field/Cell.h"
#include <string>

class CellView {
public:
    explicit CellView(char passableCellChar, char notPassableCellChar)
            :passableCellChar(passableCellChar),notPassableCellChar(notPassableCellChar) {};
    std::string toString(Cell& cell);
private:
    char passableCellChar;
    char notPassableCellChar;
};


#endif //CELLVIEW_H
