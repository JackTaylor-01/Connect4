#include "game.h"
#include <iostream>

ConnectFourGame::ConnectFourGame(int rows, int cols)
    : board(rows, cols), player1("Player 1", Token::Red), player2("Player 2", Token::Yellow) {
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
        std::cout << "Enter column (0-" << 6 << "): ";
        std::cin >> col;

        if (!board.placeToken(col, currentPlayer->getToken())) {
            std::cout << "Invalid move. Try again.\n";
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

