#include "board.h"
#include <iostream>

GameBoard::GameBoard(int rows, int cols, int winLength)
    : rows(rows), cols(cols), winLength(winLength), grid(rows, std::vector<Token>(cols, Token::Empty)) {}

bool GameBoard::placeToken(int col, Token token) {
    if (col < 0 || col >= cols) return false;  // Check for valid column index
    for (int row = rows - 1; row >= 0; --row) {  // Place token in the lowest available row
        if (grid[row][col] == Token::Empty) {
            grid[row][col] = token;
            return true;
        }
    }
    return false;  // Column is full
}

bool GameBoard::checkWin(Token token) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (grid[row][col] == token) {
                if (checkDirection(row, col, 0, 1, token) ||  // Horizontal
                    checkDirection(row, col, 1, 0, token) ||  // Vertical
                    checkDirection(row, col, 1, 1, token) ||  // Diagonal 
                    checkDirection(row, col, 1, -1, token))   // Diagonal /
                {
                    return true;
                }
            }
        }
    }
    return false;  // No winning condition met
}

bool GameBoard::checkDirection(int row, int col, int dRow, int dCol, Token token) {
    int count = 0;
    for (int i = 0; i < winLength; ++i) {  // Check for 'winLength' tokens in a row
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == token) {
            ++count;
        }
        else {
            return false;
        }
    }
    return count >= winLength;  // Ensure there are at least 'winLength' in a row
}

void GameBoard::displayBoard() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == Token::Empty)
                std::cout << ". ";  // Empty cell
            else if (cell == Token::Red)
                std::cout << "R ";  // Red token
            else
                std::cout << "Y ";  // Yellow token
        }
        std::cout << "\n";
    }
}

