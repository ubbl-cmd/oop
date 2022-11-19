#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
public:
	int getCellsVertical() const;
	void setCellsVertical(int new_cellsVertical);

	int getCellsHorizontal() const;
	void setCellsHorizontal(int new_cellsHorizontal);

	bool getTop();
	void setTop(bool newTop);
	bool getLeft();
	void setLeft(bool newLeft);

	std::string getBtn();
	void setBtn(std::string new_btn);

	Move(int cellsVertical=0, int cellsHorizontal=0, bool top=0, bool left=0, std::string btn="") :cellsVertical(cellsVertical), cellsHorizontal(cellsHorizontal), top(top), left(left), btn(btn) {};
private:
	int cellsVertical;
	int cellsHorizontal;
	bool top;
	bool left;
	std::string btn;
};


#endif //MOVE_H
