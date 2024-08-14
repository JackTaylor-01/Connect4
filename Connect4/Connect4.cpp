// Connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "board.h"
#include "player.h"

int main() {
    GameBoard board(6, 7);
    Player player1("Player 1", Token::Red);
    Player player2("Player 2", Token::Yellow);

    board.displayBoard();

    board.placeToken(3, player1.getToken());  // Player 1 places a token
    board.displayBoard();

    board.placeToken(3, player2.getToken());  // Player 2 places a token
    board.displayBoard();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
