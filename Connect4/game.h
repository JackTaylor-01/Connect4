#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#include "board.h"
#include "player.h"

class ConnectFourGame {
public:
    ConnectFourGame(int rows, int cols, int winLength);
    void playGame();

private:
    GameBoard board;
    Player player1;
    Player player2;
    Player* currentPlayer;

    void switchPlayer();
    void displayStatus();
    bool checkForWin();
};

#endif

