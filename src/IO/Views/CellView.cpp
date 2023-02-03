#include "CellView.h"


std::string CellView::toString(Cell& cell) {
    std::string tmp = std::string(1,cell.isPassable() ? passableCellChar : notPassableCellChar);
    return tmp;
}
