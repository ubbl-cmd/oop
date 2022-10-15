#include "Controller.h"


//    FieldWriter fp(&player);
//
//    fp.PrintField(field);
//    std::cout << "player pos: "<< player.getVerticalPosition() << " " << player.getHorizontalPosition() << "\n";
//
//    for (int i = 0; i < 3; i++ ) {
//        field.makeMove(player_moves[i], player, true, true, false);
//
//        fp.PrintField(field);
//        std::cout << "player pos: " << player.getVerticalPosition() << " " << player.getHorizontalPosition() << "\n";
//    }
//}

void Controller::start() {
    field = generateField();
    fieldWriter.PrintField(*field);
    while (true) {
        Move &move = commandReader.readMove(player);
        bool top = commandReader.readDirectionTop();
        bool left = commandReader.readDirectionLeft();
        field->makeMove(move, player, top, left, false);

        fieldWriter.PrintField(*field);
    }
}

Field* Controller::generateField() {
    int height = commandReader.readFieldSize("высоту");
    int width = commandReader.readFieldSize("ширину");
    if (height <= 0 or width <= 0) {
        return new Field();
    }
    return new Field(height, width);
}
