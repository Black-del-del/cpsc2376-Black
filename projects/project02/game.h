#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Game {
private:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::vector<std::vector<Cell>> board;
    bool player1Turn;
    Status gameStatus;

    bool checkWin(int row, int col, Cell player);
    bool checkDraw();
    
public:
    Game();
    void play(int col);
    Status status() const;
    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H