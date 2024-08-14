#include "board.h"
#include <iostream>

GameBoard::GameBoard(int rows, int cols)
    : rows(rows), cols(cols), grid(rows, std::vector<Token>(cols, Token::Empty)) {}

bool GameBoard::placeToken(int col, Token token) {
    if (col < 0 || col >= cols) return false;
    for (int row = rows - 1; row >= 0; --row) {
        if (grid[row][col] == Token::Empty) {
            grid[row][col] = token;
            return true;
        }
    }
    return false;

}
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
    std::cout << "\n";
}