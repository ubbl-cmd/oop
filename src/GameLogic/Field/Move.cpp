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

bool Move::getTop() {
	return top;
}
void Move::setTop(bool newTop) {
	top = newTop;
}
bool Move::getLeft() {
	return left;
}
void Move::setLeft(bool newLeft) {
	left = newLeft;
}

std::string Move::getBtn() {
	return btn;
}
void Move::setBtn(std::string new_btn) {
	btn = new_btn;
}
