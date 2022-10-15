#ifndef MOVE_H
#define MOVE_H


class Move {
public:
    int getCellsVertical() const;
    void setCellsVertical(int new_cellsVertical);

    int getCellsHorizontal() const;
    void setCellsHorizontal(int new_cellsHorizontal);

    Move(int cellsVertical, int cellsHorizontal):cellsVertical(cellsVertical),cellsHorizontal(cellsHorizontal) {};
private:
    int cellsVertical;
    int cellsHorizontal;
};


#endif //MOVE_H
