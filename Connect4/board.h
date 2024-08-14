#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class Token { Empty, Red, Yellow };

class GameBoard {
public:
    GameBoard(int rows, int cols);
    bool placeToken(int col, Token token);
    bool checkWin(Token token);
    void displayBoard();

private:
    int rows;
    int cols;
    std::vector<std::vector<Token>> grid;
    bool checkDirection(int row, int col, int dRow, int dCol, Token token);
};

#endif

