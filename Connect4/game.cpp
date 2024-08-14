#include "game.h"
#include <iostream>
#include <limits>

ConnectFourGame::ConnectFourGame(int rows, int cols, int winLength)
    : board(rows, cols, winLength), player1("Player 1", Token::Red), player2("Player 2", Token::Yellow) {
    currentPlayer = &player1;
}

void ConnectFourGame::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void ConnectFourGame::displayStatus() {
    board.displayBoard();
    std::cout << "Next player: " << currentPlayer->getName() << " (" << (currentPlayer->getToken() == Token::Red ? "Red" : "Yellow") << ")\n";
}

bool ConnectFourGame::checkForWin() {
    if (board.checkWin(currentPlayer->getToken())) {
        std::cout << "Player " << currentPlayer->getName() << " wins!\n";
        return true;
    }
    return false;
}

void ConnectFourGame::playGame() {
    while (true) {
        displayStatus();
        int col;
        std::cout << "Enter column (0-" << (board.getCols() - 1) << "): ";
        while (!(std::cin >> col) || col < 0 || col >= board.getCols()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter a column number between 0 and " << (board.getCols() - 1) << ": ";
        }

        if (!board.placeToken(col, currentPlayer->getToken())) {
            std::cout << "Column full or invalid move. Try again.\n";
            continue;
        }

        if (checkForWin()) {
            board.displayBoard();
            std::cout << "Game over.\n";
            return;  // End game if there's a winner
        }

        switchPlayer();  // Switch turns after a valid move
    }
}



