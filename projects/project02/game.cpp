#include "game.h"

Game::Game() : board(ROWS, std::vector<Cell>(COLS, EMPTY)), player1Turn(true), gameStatus(ONGOING) {}

bool Game::checkWin(int row, int col, Cell player) {
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    for (auto& dir : directions) {
        int count = 1;
        for (int d = -1; d <= 1; d += 2) {
            int r = row + d * dir[0], c = col + d * dir[1];
            while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player) {
                count++;
                r += d * dir[0];
                c += d * dir[1];
            }
        }
        if (count >= 4) return true;
    }
    return false;
}

bool Game::checkDraw() {
    for (int c = 0; c < COLS; ++c)
        if (board[0][c] == EMPTY) return false;
    return true;
}

void Game::play(int col) {
    if (col < 0 || col >= COLS || gameStatus != ONGOING) return;
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == EMPTY) {
            Cell currentPlayer = player1Turn ? PLAYER_1 : PLAYER_2;
            board[row][col] = currentPlayer;
            if (checkWin(row, col, currentPlayer)) {
                gameStatus = player1Turn ? PLAYER_1_WINS : PLAYER_2_WINS;
            } else if (checkDraw()) {
                gameStatus = DRAW;
            }
            player1Turn = !player1Turn;
            return;
        }
    }
}

Status Game::status() const {
    return gameStatus;
}

void Game::display() const {
    for (const auto& row : board) {
        for (Cell cell : row) {
            if (cell == EMPTY) std::cout << ". ";
            else if (cell == PLAYER_1) std::cout << "X ";
            else std::cout << "O ";
        }
        std::cout << "\n";
    }
    std::cout << "0 1 2 3 4 5 6\n";
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    game.display();
    return os;
}