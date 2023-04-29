#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

class Connect4 {
public:
    int rows = 6;
    int cols = 7;
    int board[6][7] = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };

    void drawBoard();

    void placePiece(int colIndex, int player);

    bool checkWinner();

    void play();
};

int main() {
    Connect4 game;
    game.play();
    cout << "Game over :)";

    return 0;
}

void Connect4::play() {
    bool winner = false;
    int currentPlayer = 1;
    Connect4::drawBoard();

    while (!winner) {
        int placeColumn;
        cout << "Enter column index (0 - 6) >>> ";
        cin >> placeColumn;

        Connect4::placePiece(placeColumn, currentPlayer);
        Connect4::drawBoard();
        winner = Connect4::checkWinner();

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

void Connect4::drawBoard() {
    system("cls");
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            cout << "|";
            if (board[y][x] == 0) {
                cout << "   ";
            }
            else if (board[y][x] == 1) {
                cout << " X ";
            }
            else if (board[y][x] == 2) {
                cout << " O ";
            }
        }
        cout << "|" << endl;
        cout << "+---------------------------+" << endl;
    }
}

void Connect4::placePiece(int colIndex, int player) {
    bool placed = false;

    for (int x = 0; x < 6; ++x) {
        if (board[x][colIndex] == 0) {
            continue;
        }
        else {
            board[x - 1][colIndex] = player;
            placed = true;
            break;
        }
    }
    if (!placed) {
        board[5][colIndex] = player;
    }
}

bool Connect4::checkWinner() {
    // check horizontal win
    for (int row = 5; row >= 0; --row) {
        for (int col = 0; col <= 6; ++col) {
            if (Connect4::board[row][col] == 1 &&
                Connect4::board[row][col + 1] == 1 &&
                Connect4::board[row][col + 2] == 1 &&
                Connect4::board[row][col + 3] == 1 ||
                Connect4::board[row][col] == 2 &&
                Connect4::board[row][col + 1] == 2 &&
                Connect4::board[row][col + 2] == 2 &&
                Connect4::board[row][col + 3] == 2) {
                return true;
            }
            else if (Connect4::board[row][col] == 1 &&
                Connect4::board[row - 1][col] == 1 &&
                Connect4::board[row - 2][col] == 1 &&
                Connect4::board[row - 3][col] == 1 ||
                Connect4::board[row][col] == 2 &&
                Connect4::board[row - 1][col] == 2 &&
                Connect4::board[row - 2][col] == 2 &&
                Connect4::board[row - 3][col] == 2) {
                return true;
            }
            else if (Connect4::board[row][col] == 1 &&
                Connect4::board[row - 1][col + 1] == 1 &&
                Connect4::board[row - 2][col + 2] == 1 &&
                Connect4::board[row - 3][col + 3] == 1 ||
                Connect4::board[row][col] == 2 &&
                Connect4::board[row - 1][col + 1] == 2 &&
                Connect4::board[row - 2][col + 2] == 2 &&
                Connect4::board[row - 3][col + 3] == 2) {
                return true;
            } 
            else if (Connect4::board[row][col] == 1 &&
                Connect4::board[row - 1][col - 1] == 1 &&
                Connect4::board[row - 2][col - 2] == 1 &&
                Connect4::board[row - 3][col - 3] == 1 ||
                Connect4::board[row][col] == 2 &&
                Connect4::board[row - 1][col - 1] == 2 &&
                Connect4::board[row - 2][col - 2] == 2 &&
                Connect4::board[row - 3][col - 3] == 2) {
                return true;
            }
        }
    }
    return false;
}