#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

// Enum to represent the different tokens on the board
enum class Token {
    EMPTY = ' ',  // Empty spot on the board
    X = 'X',      // Player 1
    O = 'O'       // Player 2
};

// Enum to represent possible game states
enum class GameState {
    ONGOING,
    PLAYER_X_WIN,
    PLAYER_O_WIN,
    DRAW
};

// Board dimensions
const int ROWS = 6;
const int COLS = 7;

class ConnectFour {
private:
    vector<vector<Token>> board;
    Token currentPlayer;

public:
    ConnectFour() {
        // Initialize the board with EMPTY tokens
        board = vector<vector<Token>>(ROWS, vector<Token>(COLS, Token::EMPTY));
        currentPlayer = Token::X;
    }

    void printRules() {
        cout << "\n***** Connect Four Rules *****\n";
        cout << "1. The game is played on a grid of 6 rows and 7 columns.\n";
        cout << "2. Players take turns to drop a disc into one of the columns.\n";
        cout << "3. The disc will fall to the lowest available position in the selected column.\n";
        cout << "4. The first player to get 4 discs in a row, either horizontally, vertically, or diagonally, wins the game.\n";
        cout << "5. If the board is filled and no player has won, the game is a draw.\n";
        cout << "6. Player 1 uses 'X' and Player 2 uses 'O'.\n";
        cout << "7. To make a move, enter a column number (0-6).\n";
        cout << "Good luck and have fun!\n";
    }

    void printBoard() {
        cout << "\nConnect Four\n";
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                cout << "|" << static_cast<char>(board[r][c]);
            }
            cout << "|\n";
        }
        cout << "---------------\n";
        cout << " 0 1 2 3 4 5 6\n";
    }

    void resetBoard() {
        // Reset the board to EMPTY tokens for a new game
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                board[r][c] = Token::EMPTY;
            }
        }
    }

    bool dropDisc(int col) {
        // Check if the column is valid
        if (col < 0 || col >= COLS) {
            cout << "Invalid column. Please choose a column between 0 and 6.\n";
            return false;
        }

        // Check for the first available row in the column
        for (int r = ROWS - 1; r >= 0; r--) {
            if (board[r][col] == Token::EMPTY) {
                board[r][col] = currentPlayer;
                return true;
            }
        }

        cout << "Column " << col << " is full. Try another one.\n";
        return false;
    }

    GameState checkWinner() {
        // Check horizontal, vertical, and diagonal directions for a win
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == currentPlayer) {
                    // Check horizontal
                    if (c + 3 < COLS &&
                        board[r][c + 1] == currentPlayer && 
                        board[r][c + 2] == currentPlayer && 
                        board[r][c + 3] == currentPlayer) {
                        return (currentPlayer == Token::X) ? GameState::PLAYER_X_WIN : GameState::PLAYER_O_WIN;
                    }
                    // Check vertical
                    if (r + 3 < ROWS &&
                        board[r + 1][c] == currentPlayer &&
                        board[r + 2][c] == currentPlayer && 
                        board[r + 3][c] == currentPlayer) {
                        return (currentPlayer == Token::X) ? GameState::PLAYER_X_WIN : GameState::PLAYER_O_WIN;
                    }
                    // Check diagonal (top-left to bottom-right)
                    if (r + 3 < ROWS && c + 3 < COLS &&
                        board[r + 1][c + 1] == currentPlayer &&
                        board[r + 2][c + 2] == currentPlayer && 
                        board[r + 3][c + 3] == currentPlayer) {
                        return (currentPlayer == Token::X) ? GameState::PLAYER_X_WIN : GameState::PLAYER_O_WIN;
                    }
                    // Check diagonal (bottom-left to top-right)
                    if (r - 3 >= 0 && c + 3 < COLS &&
                        board[r - 1][c + 1] == currentPlayer &&
                        board[r - 2][c + 2] == currentPlayer &&
                        board[r - 3][c + 3] == currentPlayer) {
                        return (currentPlayer == Token::X) ? GameState::PLAYER_X_WIN : GameState::PLAYER_O_WIN;
                    }
                }
            }
        }
        return GameState::ONGOING;
    }

    void changePlayer() {
        currentPlayer = (currentPlayer == Token::X) ? Token::O : Token::X;
    }

    bool isBoardFull() {
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == Token::EMPTY) {
                return false;
            }
        }
        return true;
    }

    void play() {
        int col;
        printRules();  // Print rules before starting the game
        while (true) {
            printBoard();
            cout << "Player " << static_cast<char>(currentPlayer) << "'s turn. Choose a column (0-6): ";
            cin >> col;

            if (dropDisc(col)) {
                GameState state = checkWinner();
                if (state == GameState::PLAYER_X_WIN) {
                    printBoard();
                    cout << "Player X wins!\n";
                    break;
                } else if (state == GameState::PLAYER_O_WIN) {
                    printBoard();
                    cout << "Player O wins!\n";
                    break;
                } else if (isBoardFull()) {
                    printBoard();
                    cout << "It's a draw!\n";
                    break;
                }
                changePlayer();
            }
        }
    }
};

int main() {
    char playAgain;
    
    do {
        ConnectFour game;
        game.play();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

        while (playAgain != 'y' && playAgain != 'n') {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> playAgain;
        }
        
    } while (playAgain == 'y');
    
    cout << "Thank you for playing! Goodbye!" << endl;
    return 0;
}
