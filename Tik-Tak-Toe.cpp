#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const char& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const char& cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            printBoard(board);

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the board is full (tie)
            if (isBoardFull(board)) {
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player X starts. Enter your moves using row and column numbers (0-2)." << endl;
    cout << "Example: To play in the top-right cell, enter 0 2." << endl;
    cout << endl;

    playGame();

    return 0;
}
