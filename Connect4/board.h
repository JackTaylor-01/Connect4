#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class Token { Empty, Red, Yellow };

class GameBoard {
public:
    GameBoard(int rows, int cols, int winLength);
    bool placeToken(int col, Token token);
    bool checkWin(Token token);
    void displayBoard();
    int getCols() const { return cols; }
    int getRows() const { return rows; }

private:
    int rows;
    int cols;
    int winLength;  // Number of tokens required to win
    std::vector<std::vector<Token>> grid;
    bool checkDirection(int row, int col, int dRow, int dCol, Token token);
};

#endif


