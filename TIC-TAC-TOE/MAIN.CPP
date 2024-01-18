#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];  // Check rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];  // Check columns
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];  // Check main diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];  // Check secondary diagonal

    return ' ';  // No winner yet
}

// Function to check if the board is full (a draw)
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;  // There is an empty space, board is not full
        }
    }
    return true;  // The board is full, and no one has won, so it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 Tic-Tac-Toe board
    int row, col;
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Display the current state of the board
        displayBoard(board);

        // Get the player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a winner or a draw
        char winner = checkWinner(board);
        if (winner != ' ') {
            displayBoard(board);
            cout << "Player " << winner << " wins!\n";
            break;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
