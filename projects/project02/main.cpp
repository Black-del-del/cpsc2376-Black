// main.cpp
#include "game.h"
#include "game.cpp"
#include <iostream>

int main() {
    Game game;
    int move;
    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Enter column (0-6): ";
        std::cin >> move;
        game.play(move);
    }
    std::cout << game;
    if (game.status() == PLAYER_1_WINS) std::cout << "Player 1 Wins!\n";
    else if (game.status() == PLAYER_2_WINS) std::cout << "Player 2 Wins!\n";
    else std::cout << "It's a draw!\n";
    return 0;
}
