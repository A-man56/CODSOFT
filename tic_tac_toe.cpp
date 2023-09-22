#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}


bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Row
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Column
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; 
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "TIC-TAC-TOE GAME" << endl;

    while (!gameWon && !gameDraw) {
        cout << "Current Player: " << currentPlayer << endl;
        displayBoard(board);

        int row, col;
        cout << "Enter row (0, 1, 2) and column (0, 1, 2) separated by a space: ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (checkDraw(board)) {
                gameDraw = true;
                cout << "It's a draw!" << endl;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    displayBoard(board);
    
    cout << "Do you want to play again? (yes/no): ";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes") {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        gameWon = false;
        gameDraw = false;
        currentPlayer = 'X';
    } else {
        cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    }

    return 0;
}
