#include <iostream>
#include "FieldWriter.h"

void FieldWriter::PrintField(Field &field) {
    std::cout << "Key: " << (player.isHasKey() ? "+" : "-") << std::endl;
    std::cout << "Health: " << player.getHealth() << std::endl;
    std::cout << fieldView->toString(field, player);
}



FieldWriter::FieldWriter(Player &player):player(player) {
    fieldView = new FieldView();
}
