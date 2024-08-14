#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class Token { Empty, Red, Yellow };

class GameBoard {
public:
    GameBoard(int rows, int cols);
    void displayBoard();

private:
    int rows;
    int cols;
    std::vector<std::vector<Token>> grid;
};

#endif#pragma once
