#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int i,j,k;
char board[3][3]; 
void initializeBoard() {
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

bool isGameOver() {
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; 
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; 
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; 
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; 
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

void makeMove(int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        printf("Invalid move! Please try again.\n");
    }
}

int main() {
    char currentPlayer = 'X';
    int row, col;

    printf("Welcome to Tic-Tac-Toe!\n");
    initializeBoard();

    while (!isGameOver()) {
        printf("Current board:\n");
        displayBoard();
        printf("Player %c's turn.\n", currentPlayer);
        printf("Enter row and column (0-2) to make your move: ");
        scanf("%d %d", &row, &col);
        makeMove(row, col, currentPlayer);
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    printf("Final board:\n");
    displayBoard();
    if (isGameOver() && !board[0][0] && !board[0][1] && !board[0][2] && !board[1][0] && !board[1][1] && !board[1][2] && !board[2][0] && !board[2][1] && !board[2][2]){
        printf("DRAW!");
    }
    else{
    printf("Player %c wins!\n", currentPlayer);
    }

    return 0;
}
