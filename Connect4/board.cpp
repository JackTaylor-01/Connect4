#include "board.h"
#include <iostream>

GameBoard::GameBoard(int rows, int cols)
    : rows(rows), cols(cols), grid(rows, std::vector<Token>(cols, Token::Empty)) {}

void GameBoard::displayBoard() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == Token::Empty)
                std::cout << ". ";
            else if (cell == Token::Red)
                std::cout << "R ";
            else
                std::cout << "Y ";
        }
        std::cout << "\n";
    }
}