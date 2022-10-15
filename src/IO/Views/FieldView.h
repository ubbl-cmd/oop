#ifndef FIELDVIEW_H
#define FIELDVIEW_H


#include <string>
#include "Field/Field.h"
#include "CellView.h"
#include "Entities/Player/Player.h"

class FieldView {
public:
    explicit FieldView() {
            cellView = new CellView('1','0');
    };
    ~FieldView() {
        delete cellView;
    }
    std::string toString(Field &field, Player &player);
private:
    CellView *cellView;
};


#endif //FIELDVIEW_H
