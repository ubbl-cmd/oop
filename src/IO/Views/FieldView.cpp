#include "FieldView.h"


std::string FieldView::toString(Field &field, Player &player) {
    std::string field_string;
    for (int i = 0; i < field.getHeight(); ++i) {
        for (int j = 0; j < field.getWidth(); ++j) {
            field_string += " ";
            if(player.getVerticalPosition() == i and player.getHorizontalPosition() == j) {
                field_string += "P";
                continue;
            }
            field_string += "O";

        }
        field_string += "\n";
    }
    return field_string;
}
