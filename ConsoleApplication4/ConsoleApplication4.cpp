#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9];
    char currentPlayer;

public:
    TicTacToe() {
        for (int i = 0; i < 9; i++) board[i] = ' ';
        currentPlayer = 'X';
    }

    void printBoard() {
        cout << "\n";
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
        cout << "\n";
    }

    bool isDraw() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') return false;
        }
        return true;
    }

    char checkWinner() {
        const int winningCombinations[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };
        for (auto& combo : winningCombinations) {
            if (board[combo[0]] != ' ' &&
                board[combo[0]] == board[combo[1]] &&
                board[combo[1]] == board[combo[2]]) {
                return board[combo[0]];
            }
        }
        return ' ';
    }

    void playGame() {
        printBoard();
        while (true) {
            int move;
            cout << "Player " << currentPlayer << ", enter a cell number (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || board[move - 1] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[move - 1] = currentPlayer;
            printBoard();

            char winner = checkWinner();
            if (winner != ' ') {
                cout << "Player " << winner << " wins!\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}