//
// Created by egunuraka on 9/24/22.
//

#include "Move.h"

int Move::getCellsVertical() const {
    return cellsVertical;
}

void Move::setCellsVertical(int new_cellsVertical) {
    cellsVertical = new_cellsVertical;
}

int Move::getCellsHorizontal() const {
    return cellsHorizontal;
}

void Move::setCellsHorizontal(int new_cellsHorizontal) {
    cellsHorizontal = new_cellsHorizontal;
}
