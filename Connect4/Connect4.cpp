// Connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "game.h"
#include <iostream>

int main() {
    int rows, cols, winLength;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    std::cout << "Enter number of tokens in a row to win: ";
    std::cin >> winLength;

    // Validate inputs
    if (rows <= 0 || cols <= 0 || winLength <= 0 || winLength > std::min(rows, cols)) {
        std::cout << "Invalid input. Ensure rows and columns are positive and win length is feasible.\n";
        return 1;
    }

    ConnectFourGame game(rows, cols, winLength);
    game.playGame();

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
