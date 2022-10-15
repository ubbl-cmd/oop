#include <iostream>
#include "Controller.h"

int main() {
    Controller controller;
    GameStatus gameStatus = controller.start();
    if (gameStatus == Win) {
        std::cout << "you win\n";
    }
    if (gameStatus == Lose) {
        std::cout << "you lost\n";
    }
    return 0;
}